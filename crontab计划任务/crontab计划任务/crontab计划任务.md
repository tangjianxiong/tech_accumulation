# 计划任务概述
例行执行的事物，例如定期执行的命令。
## 计划任务种类
计划任务的种类分为：例行性和突发性。
## at
at是可以处理仅执行一次就结束的命令。
## crontab
crontab这个命令设置的任务会循环的一直执行下去，可循环时间可以自由设置。
## Linux的例行事务
+ 执行日志文件的轮循
+ 日志文件分析
+ 删除缓存

# 仅执行一次的计划任务
场景：一分钟后查看当前目录的内容

```
tangjianxiong@SzExdroid20:/var/mail$ at now + 1 minutes
warning: commands will be executed using /bin/sh
at> echo "hello world" > /dev/tangjianxiong
at> ls -al
at> <EOT>

```

at的执行与终端环境无关，所有的标准输入输出都会发送到执行者的Mailbox中，在/var/mail/中可以查看。

# 循环执行的计划任务
crontab 是 Linux 下的计划任务，当时间达到我们设定的时间时，可以自动触发某些脚本的运行。


我们可以自己设置计划任务时间，然后编写对应的脚本。但是，有个特殊的任务，叫作 @reboot ，我们其实也可以直接从它的字面意义看出来，这个任务就是在系统重启之后自动运行某个脚本。