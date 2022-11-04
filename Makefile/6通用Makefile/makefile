# 伪目标声明，clean始终执行
.PHONY: clean

# 默认目标   -- main
# 默认编译器 -- 让系统指定
# 默认源文件 -- 是当前目录下的全部.c
# 默认选项   -- 空
TARGET   	?= main
COMPILER	?= $(CXX)
SOURCE   	?= $(wildcard *.c)
OPTION   	?= 

# 覆盖赋值，不允许用户重写
OBJ:=$(patsubst %.c,%.o, $(notdir $(SOURCE)))

$(TARGET):$(OBJ)
	$(COMPILER) $(OPTION) $(OBJ) -o $(TARGET)

%.o:%.c
	$(COMPILER) -c $^ -o $@

clean:
	$(RM) $(TARGET) *.o
