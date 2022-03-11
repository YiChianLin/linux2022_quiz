CC = gcc
CFLAGS = -Iinclude  #將include 資料夾內的.h檔案引入

week = quiz_w3
name = $(week)_1
out = $(name).out
target = $(week)/$(name)

all: $(target).c
	-@$(CC) $(CFLAGS) -o $(out) $(target).c  # -@ 表示不顯示命令
	-@./$(out)

clean:
	-@rm -f *.out
