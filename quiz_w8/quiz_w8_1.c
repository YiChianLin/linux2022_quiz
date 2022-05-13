#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

/* Nonzero if either X or Y is not aligned on a "long" boundary */
#define UNALIGNED(X) ((long) X & (sizeof(long) - 1))

/* How many bytes are loaded each iteration of the word copy loop */
#define LBLOCKSIZE (sizeof(long)) /* 8 or 4 */

/* Threshhold for punting to the bytewise iterator */
#define TOO_SMALL(LEN) ((LEN) < LBLOCKSIZE)

#if LONG_MAX == 2147483647L
#define DETECT_NULL(X) (((X) -0x01010101) & ~(X) & 0x80808080)
#else
#if LONG_MAX == 9223372036854775807L
/* Nonzero if X (a long int) contains a NULL byte. */
#define DETECT_NULL(X) (((X) -0x0101010101010101) & ~(X) & 0x8080808080808080)
#else
#error long int is not a 32bit or 64bit type.
#endif
#endif

/* @return nonzero if (long)X contains the byte used to fill MASK. */
#define DETECT_CHAR(X, MASK) (DETECT_NULL(X ^ MASK))

void *memchr_opt(const void *src_void, int c, size_t length)
{
    const unsigned char *src = (const unsigned char *) src_void;
    unsigned char d = c;

    /* 判斷是否與 long 對齊 */
    printf("aa %d\n", UNALIGNED(src));
    while (UNALIGNED(src)) {
        if (!length--)
            return NULL;
        if (*src == d)
            return (void *) src;
        src++;
    }

    if (!TOO_SMALL(length)) {
        /* If we get this far, we know that length is large and
         * src is word-aligned.
         */

        /* The fast code reads the source one word at a time and only performs
         * the bytewise search on word-sized segments if they contain the search
         * character, which is detected by XORing the word-sized segment with a
         * word-sized block of the search character and then detecting for the
         * presence of NULL in the result.
         */
        unsigned long *asrc = (unsigned long *) src;
        /*for ascii the value range will be 0 ~ 127
         *so need 8 bits to express the target char
         *first make double char mask so  shift 8 bits
         */
        unsigned long mask = d << 8 | d; /* '.' = 46 = 101110 */
        /*mask = 00010 1110 0010 1110*/

        /*make 32 bits mask*/
        mask = mask << 16 | mask;
        /*make 64 bits mask*/
        for (unsigned int i = 32; i < LBLOCKSIZE * 8; i <<= 1) /* LBLOCKSIZE = 8 or 4*/
            mask = (mask << i) | mask;
        /* 用於 8 */
        while (length >= LBLOCKSIZE) {
            /* XXXXX: Your implementation should appear here */
            /* 如果每 long 長度個 bytes 進入函式有找到目標字元,則會回傳非0值,則可跳出迴圈*/
            if(DETECT_CHAR(*asrc, mask)) 
                break;

            asrc++; /* 每 long 長度個 byte 進行換下一 long 的長度*/
            length -= LBLOCKSIZE; /* 每 long 長度遞減*/
        }

        /* If there are fewer than LBLOCKSIZE characters left, then we resort to
         * the bytewise loop.
         */
        src = (unsigned char *) asrc; /* 大範圍找過後,擷取找到第一個出現的字串片段*/
    }
    /*針對該段字串,進行每個字元的查找*/
    while (length--) {
        if (*src == d)
            return (void *) src;
        src++;
    }
    return NULL;
}

int main()
{
    const char str[] = "http://wiki.csie.ncku.edu.tw";
    const char ch = '.';
    
    char *ret = memchr_opt(str, ch, strlen(str));
    printf("String after |%c| is - |%s|\n", ch, ret);
    return 0;
}