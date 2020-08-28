# 通过debugfs进行内核调试
# 概要
DebugFS，顾名思义，是一种用于内核调试的虚拟文件系统，内核开发者通过debugfs和用户空间交换数据。类似的虚拟文件系统还有procfs和sysfs等，这几种虚拟文件系统都并不实际存储在硬盘上，而是Linux内核运行起来后才建立起来。   
通常情况下，最常用的内核调试手段是printk。但printk并不是所有情况都好用，比如打印的数据可能过多，我们真正关心的数据在大量的输出里不是那么一目了然；或者我们在调试时可能需要修改某些内核变量，这种情况下printk就无能为力，而如果为了修改某个值重新编译内核或者驱动又过于低效，此时就需要一个临时的文件系统可以把我们需要关心的数据映射到用户空间。在过去，procfs可以实现这个目的，到了2.6时代，新引入的sysfs也同样可以实现，但不论是procfs或是sysfs，用它们来实现某些debug的需求，似乎偏离了它们创建的本意。比如procfs，其目的是反映进程的状态信息；而sysfs主要用于Linux设备模型。不论是procfs或是sysfs的接口应该保持相对稳定，因为用户态程序很可能会依赖它们。当然，如果我们只是临时借用procfs或者sysfs来作debug之用，在代码发布之前将相关调试代码删除也无不可。但如果相关的调试借口要在相当长的一段时间内存在于内核之中，就不太适合放在procfs和sysfs里了。故此，debugfs应运而生。

# 用法
## 挂载
默认情况下，debugfs会被挂载在目录/sys/kernel/debug之下，如果您的发行版里没有自动挂载，可以用如下命令手动完成：
```
# mount -t debugfs none /your/debugfs/dir
```
## 相关接口
### 建立根目录
在module_init里，我们首先要建立根目录mydebug：
```
my_debugfs_root = debugfs_create_dir("mydebug", NULL);
```
第一个参数是目录的名称，第二个参数用来指定这个目录的上级目录，如果是NULL，则表示是放在debugfs的根目录里。  
子目录也是用debugfs_create_dir来实现：

```
sub_dir = debugfs_create_dir("subdir", my_debugfs_root);
```
建立文件a的代码非常简单：
```
debugfs_create_u8("a", 0644, my_debugfs_root, &a);
```
这表示文件名为“a”，文件属性是0644，父目录是上面建立的“mydebug”，对应的变量是模块中的a。

### 创建文件
Linux内核还提供了其他一些创建debugfs文件的API，请参考本文的附录。
```
char hello[32] = "Hello world!\n";
struct debugfs_blob_wrapper b;
 
b.data = (void *)hello;
b.size = strlen(hello) + 1;
debugfs_create_blob("b", 0644, my_debugfs_root, &b);
```
b是一个32-bytes的字符数组，在debugfs里，数组可以用blob wrapper来实现。  
这里需要注意的是，blob wrapper定义的数据只能是只读的。在本例中，虽然我们把文件b的权限设定为0644，但实际这个文件还是只读的，如果试图改写这个文件，系统将提示出错。

如果需要对内核数组进行写的动作，blob wrapper就无法满足要求，我们只能通过自己定义文件操作来实现。在这个实作里，可以参考文件c的实现。c和b在模块里对应着同一块字符数组，不同的是，b是只读的，而c通过自定义的文件操作同时实现了读和写。

# 应用
在目前的虚拟项目场景中，可以通过创建debugfs调试节点来实时监测通信次数、非法通信、传输数据类型等信息。

# 附录
## 创建和撤销目录

```
struct dentry *debugfs_create_dir(const char *name, struct dentry *parent);
struct dentry *debugfs_create_file(const char *name, mode_t mode, 
        struct dentry *parent, void *data, 
        const struct file_operations *fops);
void debugfs_remove(struct dentry *dentry);
void debugfs_remove_recursive(struct dentry *dentry);
```

## 创建单值文件

```
struct dentry *debugfs_create_u8(const char *name, mode_t mode, 
        struct dentry *parent, u8 *value);
struct dentry *debugfs_create_u16(const char *name, mode_t mode, 
        struct dentry *parent, u16 *value);
struct dentry *debugfs_create_u32(const char *name, mode_t mode, 
        struct dentry *parent, u32 *value);
struct dentry *debugfs_create_u64(const char *name, mode_t mode, 
        struct dentry *parent, u64 *value);
 
struct dentry *debugfs_create_x8(const char *name, mode_t mode, 
        struct dentry *parent, u8 *value);
struct dentry *debugfs_create_x16(const char *name, mode_t mode, 
        struct dentry *parent, u16 *value);
struct dentry *debugfs_create_x32(const char *name, mode_t mode, 
        struct dentry *parent, u32 *value);
 
struct dentry *debugfs_create_size_t(const char *name, mode_t mode, 
        struct dentry *parent, size_t *value);
struct dentry *debugfs_create_bool(const char *name, mode_t mode, 
        struct dentry *parent, u32 *value);
```
其中，后缀为x8、x16、x32的这三个函数是指debugfs中的数据用十六进制表示

### 创建BLOB文件
```
struct debugfs_blob_wrapper {
    void *data;
    unsigned long size;
};
 
struct dentry *debugfs_create_blob(const char *name, mode_t mode, 
         struct dentry *parent, struct debugfs_blob_wrapper *blob);
```

### 其他

```
struct dentry *debugfs_rename(struct dentry *old_dir, struct dentry *old_dentry, 
        struct dentry *new_dir, const char *new_name);
 
struct dentry *debugfs_create_symlink(const char *name, 
        struct dentry *parent, const char *target);
```