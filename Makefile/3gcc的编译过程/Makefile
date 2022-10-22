# 表明生成可执行文件main需要的文件：main.o Add.o
main: main.o Add.o
# 编译方式：链接main.o和Add.o以及对应的动态静态库 
	gcc main.c Add.o -o main

# 以下是Add.o和main.o的生成方式，合上述相似
Add.o: Add.c
	gcc -c Add.c
main.o: main.c
	gcc -c main.c

# 清理工程中间文件
clean:
	rm -f *.o main