# README

## 程序说明

1. 编译环境：VisualStudio 2017

2. 主要函数：
	```c++
   void double2fraction();		//Floating point input, fractional output
   void fraction2double();		//Fractional input, floating point output
   void fractionAdd();			//Fractional add
   void fractionSub();			//Fractional sub
   void fractionMul();			//Fractional multiplex
   void fractionDiv();			//Fractional divide
   void fractionCompare();		//Fractional compare
   void fractionIncrease();	//Fractional self increase(x++/y)
   void fractionDecrease();	//Fractional self decrease(x--/y)
   ```

3. 文件结构

   -main.cpp										|	主函数
   				-Functions.h					|	主函数调用的顶端类声明
   				-Functions.cpp				|	主函数调用的顶端类定义
   							-Fraction.h			|	分数类
   							-Fraction.cpp		|	分数类定义，包括各项重定义函数

## CopyRight

* FileName:		Fraction
* Author:		Miracle_Zero
* Date:		2020/5/16

   

   