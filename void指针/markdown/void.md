[toc]
# void指针

void的意思就是“无类型”，void指针则为“无类型指针”，void指针可以指向任何类型的数据。  
所以void指针一般被称为通用指针或者泛指针,或者叫做万能指针

+ 定义形式：void *p
在C语言中在任何时候都可以用void类型的指针来代替其他类型的指针，void指针可以指向任何数据类型的变量，如果要通过void指针去获取它所指向的变量值时候，需要先将void指针强制类型转换成和变量名类型想匹配的数据类型指针后再进行操作。
+ 指针的强类类型转化：
```
void *p;
int *pa = (int *)p
```
只有经过类型转换然后才能对原来的void指针指向的空间进行操作

+ 任何类型的指针都可以赋值给void指针：
```
float f = 1.22f;
float *p1 = &f;
p = p1;//将float指针赋值被p
```

# void指针的应用场合
## 场景
当进行纯粹的内存操作的时候，或者传递一个指向未定类型的指针时，可以使用void指针；
void* memcpy(void *addr1,void *addr2,size_t n);
该函数只进行纯粹的内存拷贝，包括NULL字符在内的任何内容都将被拷贝
+ 对函数参数的限定
+ 对函数返回的限定
+ void指针也常用作函数指针

## 代码
```
SOURCE = void.c
OBJ = void.o	#将.c文件转为.o文件
INCLUDES = -I./hdr	#头文件路径


TARGET = void
CC = gcc

$(TARGET): $(OBJ)	
	$(CC) $(OBJ)  -o $(TARGET) 


.PHONY: clean
clean:
	rm -rf $(OBJ) 
```