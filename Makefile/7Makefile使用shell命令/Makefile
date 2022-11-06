# 伪目标声明，clean始终执行
.PHONY: clean
# .PHONY: all
# .PHONY: show

# 默认目标       -- main
# 默认编译器     -- 让系统指定
# 默认源文件     -- 是当前目录下的全部.c
# 中间文件路径   -- build
# 默认选项       -- 空
target   	?= main
compiler	?= $(CXX)
source   	?= $(wildcard *.c)
path        ?= build
options   	?= 

obj=$(patsubst %.c,%.o, $(notdir $(source)))
link=$(patsubst %.c,./$(path)/%.o, $(source))

all: show $(target)
	@echo ----------------编译完成----------------

show:
	@echo ----------------开始编译----------------
	@if [ ! -e $(path) ];then mkdir $(path);fi;
	@echo "目标     ：$(target)"
	@echo "编译器   : $(compiler)"
	@echo "源文件   : $(source)"
	@echo "编译选项 : $(options)"

# 主要的编译
$(target):$(link)
	@$(compiler) $(options) $^ -o $(target)

./$(path)/%.o:./%.c
	@$(compiler) -c $^ -o ./$@

# 清理
clean:
	@echo ----------------开始清理----------------
	@$(RM) $(target) ./$(path)/*.o
	@echo "删除obj..."
	@echo "删除target..."
	@echo ----------------清理完成----------------
