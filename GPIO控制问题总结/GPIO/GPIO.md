---
title: gpio控制
subtitle: 调试指南
author: Allwinner
changelog:
- ver: 1.1
  date: 2019.9.19
  author: Allwinner 
  desc: |
		1. 建立版本
		2. 增加T7 gpio调试记录


****
---


# 前言

## 文档简介
本文档对全志平台的GPIO接口使用进行详细的阐述，让用户明确掌握GPIO配置、申请等操作的编程方法。
## 目标读者
本文档适用于所有需要在全志T系列平台上开发设备驱动的人员。
## 适用范围
全志T系列平台。



# gpio介绍

GPIO（英语：General-purpose input/output），通用型之输入输出的简称，功能类似8051的P0—P3，其接脚可以供使用者由程控自由使用，PIN脚依现实考量可作为通用输入（GPI）或通用输出（GPO）或通用输入与输出（GPIO），如当clk generator, chip select等。  

既然一个引脚可以用于输入、输出或其他特殊功能，那么一定有寄存器用来选择这些功能。对于输入，一定可以通过读取某个寄存器来确定引脚电位的高低；对于输出，一定可以通过写入某个寄存器来让这个引脚输出高电位或者低电位；对于其他特殊功能，则有另外的寄存器来控制它们。  

# pinctrl介绍

## 子系统简介
许多SoC内部都包含pin控制器，通过pin控制器，我们可以配置一个或一组引脚的功能和特性。在高版本的Linux内核引入了pinctrl子系统，目的是为了统一各个SOC厂商的pin脚管理。通过pinctrl子系统管理所有的SOC的IO管脚，并对设备外围管脚如串口、I2C、LCD等都有相应的配置模式。配置IO功能，操作IO不需要自己配置GPIO控制器，结合电源管理机制，可以实现不同状态下，IO功能自动切换。

在软件上，Linux内核pinctrl驱动可以操作pin控制器为我们完成如下工作：

+ 枚举并且命名pin控制器可控制的所有引脚；
+ 提供引脚的复用能力
+ 提供配置引脚的能力，如驱动能力、上拉下拉、数据属性等。
+ 与gpio子系统的交互
+ 实现pin中断


## 相关专业术语

## 引脚状态和设备树关系

## 使用pinctrl配置设备IO引脚功能

## pinctrl子系统常用API

# gpio控制
全志提供相关的脚本工具，可查询和设置gpio引脚状态。

## gpio控制脚本

```shell
#!/bin/sh

#for args in $@
#do
#   echo $args
#done
#echo "all args is: $@"
#echo "arg num is: $#"

op=$1
io=$2
func=$3
data=$4
dlevel=$5
pull=$6

if  [ $# -lt 2 ];  then
    print_help
elif  [ $# -gt 6 ];  then
    print_help
fi



function print_help(){
    echo "===========================useage=================================================="
    echo "gpio op io func data dlevel pull   ---set io's function data dlevel pull          ="
    echo "gpio op io func data               ---set io's func data                          ="
    echo "gpio op io func                    ---set io's func                               ="
    echo "gpio op io                         ---get io's status                            ="
    echo "for example:                                                                      =" 
    echo "gpio -s PH1  1   1     1     1     ---set PH1's function=1 data=1,dlevel=1 pull=1 ="
    echo "gpio -s PH1  1   0                 ---set PH1's function=1 data=0                 ="
    echo "gpio -s PH1  1                     ---set PH1's function=1                        ="
    echo "gpio -g PH1                        ---get PH1's status                            ="
    echo "==================================================================================="
    exit -1
}

function gotoPinctrlDir(){
    if  [ ! -d /sys/kernel/debug/sunxi_pinctrl ];  then
        mount -t debugfs none /sys/kernel/debug
    fi
        
    cd /sys/kernel/debug/sunxi_pinctrl
}

function check_dev_name(){
	if  [ -f /sys/kernel/debug/sunxi_pinctrl/dev_name ];  then
		#TMP="I"
		TMP=${io:1:1}
		t1=`printf "%d" "'$TMP"`
		t2=`printf "%d" "'L"`
		#echo "$TMP=$t1  L=$t2 "
		if [ $t1 -ge $t2 ];  then
			echo "P$TMP,use r_pio"
			echo r_pio > dev_name
		else
			echo "P$TMP,use pio"
			echo pio > dev_name
		fi
	else
		echo "the driver don't support r_pio"
	fi
}

gotoPinctrlDir

check_dev_name

echo $io > sunxi_pin

if  [ $# == 2 ];  then
    if  [ $op = '-g' ];  then
        echo "get $io status:"
        cat sunxi_pin_configure
        if [ $? -ne 0 ]; then
            echo "maybe this pin is not in this chip"
        fi
    else 
        echo "get input param error"
        print_help
    fi
elif  [ $# == 3 ];  then
    if [ $op = '-s' ];  then
        echo $io $func > function
        echo "set $io function=$func"
    else 
        echo "get input param error"
        print_help
    fi
elif  [ $# == 4 ];  then
    if [ $op = '-s' ];  then
        echo $io $func > function
        echo $io $data > data
        echo "set $io function=$func"
        echo "set $io data=$data"
    else 
        echo "get input param error"
        print_help
    fi
elif  [ $# == 6 ];  then
    if [ $op = '-s' ];  then
        echo $io $func > function
        echo $io $data > data
        echo $io $dlevel > dlevel
        echo $io $pull > pull
        echo "set $io function=$func"
        echo "set $io data=$data"
        echo "set $io dlevel=$dlevel"
        echo "set $io pull=$pull"
    else 
        echo "get input param error"
        print_help
    fi
else
    echo "input param is $# error!!!"
fi

```

##  用法

### 查询引脚状态

```shell

# ./gpio -g PH15
the driver don't support r_pio
get PH15 status:
pin[PH15] funciton: 1
pin[PH15] data: 0
pin[PH15] dlevel: 1
pin[PH15] pull: 1

```

### 设置引脚状态

```shell
# ./gpio -s PH15 1 1 1 1
the driver don't support r_pio
set PH15 function=1
set PH15 data=1
set PH15 dlevel=1
set PH15 pull=1

```


# FAQ
相关gpio控制问题解决汇总。
## 调试方法

### 调试工具

### 调试节点

## 常见问题
