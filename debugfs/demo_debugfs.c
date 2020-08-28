#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/fs.h> // for libfs
#include <asm-generic/uaccess.h>

/** 自定义可读写blob **/
struct my_blob_wrapper
{
    void *data;
    unsigned long size;
};
static int my_blob_wrapper_open(struct inode *inode, struct file *filp)
{
    filp->private_data = inode->i_private;
    return 0;
}
static ssize_t my_blob_wrapper_read(struct file *filp, char __user *user_buf, size_t count, loff_t *ppos)
{
    struct my_blob_wrapper *blob = filp->private_data;
    return simple_read_from_buffer(user_buf, count, ppos,
                                   blob->data, blob->size); // from libfs
}
static ssize_t my_blob_wrapper_write(struct file *filp, const char __user *user_buf, size_t count, loff_t *ppos)
{
    struct my_blob_wrapper *blob = filp->private_data;
    return simple_write_to_buffer(blob->data, blob->size, ppos,
                                  user_buf, count);
}
static struct file_operations my_blob_wrapper_ops = {
    .owner = THIS_MODULE,
    .open = my_blob_wrapper_open,
    .read = my_blob_wrapper_read,
    .write = my_blob_wrapper_write,
    .llseek = default_llseek, // from vfs
};
/* 接口函数 */
struct dentry *my_create_blob(const char *name, umode_t mode,
                              struct dentry *parent,
                              struct my_blob_wrapper *blob)
{
    return debugfs_create_file(name, mode, parent, blob, &my_blob_wrapper_ops);
}
/** my_clob implementation end **/

static struct dentry *root_d;
static u8 var8;
static u16 var16;
static u32 var32;
static u32 varbool;
static char buf[] = "Hello debugfs!\n";
static struct debugfs_blob_wrapper b;
static struct my_blob_wrapper b2;
static u32 arr[] = {1, 2, 3, 4, 5};

int __init mod_init(void)
{
    printk(KERN_INFO "exam_debugfs: initialing...\n");
    root_d = debugfs_create_dir("exam_debugfs", NULL);
    if (!root_d)
    {
        printk(KERN_INFO "exam_debugfs: error create root dir\n");
        return 1;
    }
    /* u{8,16,32}, bool */
    debugfs_create_u8("var-u8", 0664, root_d, &var8);
    debugfs_create_u16("var-u16", 0664, root_d, &var16);
    debugfs_create_u32("var-u32", 0664, root_d, &var32);
    //debugfs_create_bool("var-bool", 0664, root_d, &varbool);
    /* u32_array */
    debugfs_create_u32_array("array", 0664, root_d, arr, sizeof(arr) / sizeof(u32));
    /* blob_wrapper */
    b.data = buf;
    b.size = strlen(buf) + 1;
    debugfs_create_blob("blob", 0644, root_d, &b); // blob is readonly, even if 0644
    /* my_blob_wrapper */
    b2.data = buf;
    b2.size = strlen(buf) + 1;
    my_create_blob("myblob", 0644, root_d, &b2);

    return 0;
}
void __exit mod_exit(void)
{
    debugfs_remove_recursive(root_d);
    printk(KERN_INFO "exam_debugfs: exiting...\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a demo for debugfs");
MODULE_AUTHOR("rsljdkt");