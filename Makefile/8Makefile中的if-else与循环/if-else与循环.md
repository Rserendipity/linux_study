# 八、Makefile中的if-else与循环

## 1.if-else

Makefile中的if语句和C语言等语言中的if有所不同

体现在：

1. 有 对值的判断 和 变量是否存在 两种判断
2. if需要对应的 endif
3. 没有 else if 这样的语法，想要使用 else if 的语法，需要嵌套使用 if 来实现 else if 的功能
4. if可以不跟else
5. 由于使用 endif 来限制if的结束范围，所以在if语句内可以执行多条语句

---

1、对值的判断：

- `ifeq (内容,比较内容)`
- 判断成功以后会执行if内的语句
- 需要注意的是，if有对应的结束if的语句 --- endif

例子：

```sh
A := abc
B := 
ifeq ($(A),abc)
	B:=100
else
	B:=200
endif # 注意这里的endif，这里是要求

print:
	echo $(B)
```

> 执行`make print`的结果是 100 ，可以看到if的分支控制起到了作用，将 B 的值赋值成 100

测试值不相等：

- `ifneq (内容,比较内容)`
- 如果 内容 和 比较的内容 不相等，会执行if内的语句
- 相信很容易理解，不重复举例了

---

2、对变量是否存在的判断：

- `ifdef (内容,比较内容)`
- 如果定义了 内容 这个变量，就会执行if内的内容

```sh
ifdef aaa
	aaa:=aaa is exist
else
	aaa:=aaa will be defined
endif

print:
	echo $(aaa)
```

> 执行`make print`的结果是 aaa will be defined ，可以看到if的分支控制起到了作用，由于没有定义过aaa，所以执行了else的内容，定义aaa为aaa will be defined

- `ifndef (内容)`
- 没有定义过 内容 会执行if的内容，和ifdef的性质相反
- 不过多介绍了

## 2.循环

foreach

- 语法 `$(foreach 元素,列表,语句)`
- 将 列表 里面的内容分别给 元素 然后执行 语句
- 会返回所有操作完毕的结果列表

例子：
```
list := a b c d
newlist := $(foreach elem,$(list),$(elem)999)

print:
	echo $(newlist)
```

> 执行`make print`的结果是 a999 b999 c999 d999
> - 定义了一个变量 list
> - 用foreach循环，分别取出 list 的元素，交给 elem 变量，执行使得elem后面跟了999数字，然后返回给newlist