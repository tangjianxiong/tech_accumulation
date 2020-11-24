# ioctl控制Linux设备驱动
大部分驱动除了需要具备读写设备的能力之外，还需要
## ioctl 系统调用

```c
/*
fd:文件描述符
cmd:控制命令
...:可选参数:插入*argp，具体内容依赖于cmd
*/
int ioctl(int fd,unsigned long cmd,...);

```

用户程序只是通过命令码告诉驱动程序它想做什么，至于怎么解释这些命令和怎么实现这些命令，这都是驱动程序要做的事情。

## 驱动ioctl方法

```c
int (*ioctl) (struct inode *inode,struct file *filp,unsigned int cmd,unsigned long arg);
/*
inode与filp两个指针对应于应用程序传递的文件描述符fd，这和传递open方法的参数一样。
cmd 由用户空间直接不经修改的传递给驱动程序
arg 可选。
*/
```
在驱动程序中实现的ioctl函数体内，实际上是有一个switch {case}结构，每一个case对应一个命令码，做出一些相应的操作。怎么实现这些操作，这是每一个程序员自己的事情，因为设备都是特定的。关键在于怎么样组织命令码，因为在ioctl中命令码是唯一联系用户程序命令和驱动程序支持的途径。


在Linux核心中是这样定义一个命令码的：  

| 设备类型 | 序列号 | 方向 | 尺寸 |
|----------|--------|------|------|
| 8bit     | 8bit   | 2bit | 8bit |

这样一来，一个命令就变成了一个整数形式的命令码。但是命令码非常的不直观，所以Linux Kernel中提供了一些宏，这些宏可根据便于理解的字符串生成命令码，或者是从命令码得到一些用户可以理解的字符串以标明这个命令对应的设备类型、设备序列号、数据传送方向和数据传输尺寸。

### 定义命令
内核提供了一些宏来帮助定义命令：
```c


//nr为序号，datatype为数据类型,如int
_IO(type, nr ) //没有参数的命令
_IOR(type, nr, datatype) //从驱动中读数据
_IOW(type, nr, datatype) //写数据到驱动
_IOWR(type,nr, datatype) //双向传送


//举例

#define MEM_IOC_MAGIC 'm' //定义类型
#define MEM_IOCSET _IOW(MEM_IOC_MAGIC,0,int)
#define MEM_IOCGQSET _IOR(MEM_IOC_MAGIC, 1, int)
```


### 实现命令
定义好了命令，下一步就是要实现ioctl函数了，ioctl的实现包括三个技术环节，返回值、参数使用和命令操作。

#### 返回值
ioctl函数的实现是根据命令执行的一个switch语句，但是当命令不能匹配任何一个设备所支持的命令时，通常返回-EINVAL(非法参数)。

#### 参数使用

用户使用　　int ioctl(int fd,unsinged long cmd,...)　　时，...就是要传递的参数；  
再通过　　int (*ioctl)(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)　　中的arg传递； 
如果arg是一个整数，可以直接使用；  
如果是指针，我们必须确保这个用户地址是有效的，因此，使用之前需要进行正确检查。


内部有检查的，不需要检测的:
```c
copy_from_user
copy_to_user
get_user
put_user

```

需要检测的：
```c

```

#### 命令操作


