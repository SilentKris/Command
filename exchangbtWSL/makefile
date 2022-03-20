CC = g++
LD = g++

#正则表达式表示目录下的所有CPP文件，相当与：SRCS = main.cpp, a.cpp, b.cpp
SRCS = $(wildcard *cpp)

#OBJS表示SRCS中的.cpp全部替换成.o，相当与：OBJS = main.o a.o b.o
OBJS = $(patsubst %cpp, %o, $(SRCS))

#可执行文件的名字
TARGET = main

#.PHONE伪目标
.PHONE:all clean

#第一行依赖关系：冒号后面为依赖的文件，相当与HELLO：main.o a.o b.o
#第二行规则：$@表示目标文件，$^表示所有依赖文件，$<表示第一个依赖文件
$(TARGET):$(OBJS)
	$(LD) -o $@ $^

#上一句目标文件依赖一堆.o文件，这句表示所有的.o都由相应的.cpp文件自动生成
%.o:%.cpp
	$(CC) -c $^

#make clean 删除所有的.o和目标文件
clean:
	del  $(OBJS) $(TARGET).exe