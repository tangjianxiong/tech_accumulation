#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/string.h>
static struct task_struct *test_task;
static int get_state_i = 1;
static int thread_get_pstate(void *data)
{
    int state_a = 0;
    int state_b = 0;
    int state_c = 0;
    struct task_struct *p;
    printk(KERN_INFO "Hello,world!\n");
    while (get_state_i)
    {
        for_each_process(p)
        {
            if (strcmp(p->comm, "server_a") == 0)
            {
                state_a = p->state;
            }
            if (strcmp(p->comm, "client_b") == 0)
            {
                state_b = p->state;
            }
            if (strcmp(p->comm, "client_c") == 0)
            {
                state_c = p->state;
            }
            // if ((strcmp(p->comm, "client_b") == 0) || (strcmp(p->comm, "client_c") == 0) || (strcmp(p->comm, "server_a") == 0))
            // {
            //     printk(KERN_INFO "the process is \"%s\" (pid %i),and process status is  %ld\n", p->comm, p->pid, p->state);
            // }
                }
        ssleep(5);
    }

    return 0;
}
static int hello_init(void)
{
    int err;
    test_task = kthread_create(thread_get_pstate, NULL, "test_task");

    if (IS_ERR(test_task))
    {
        printk("Unable to start kernel thread.\n");
        err = PTR_ERR(test_task);
        test_task = NULL;
        return err;
    }
    wake_up_process(test_task);
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_INFO "GOODbye ,world\n");
    get_state_i = 0;
    kthread_stop(test_task);
    test_task = NULL;
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("Dual BSD/GPL");