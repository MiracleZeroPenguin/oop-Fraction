/********************************************************************************
* @File name: Functions.h
* @Author: Miracle_Zero
* @Version: 1.0
* @Date: 2020-05-16
* @Description:Declaration of Function used in top module
********************************************************************************/
#ifndef FUNCTIONS_H
#define FUNCTION_H
#include<string>
#include<iostream>
#include"Fraction.h"
using namespace std;
class Functions {
public:
	Functions();		
	~Functions();
	bool exit=false;			//Exit program or not
private:
	void printInfo();			//Print the menu
	void classifyFunc();		//From catalog page to functional interface of requirement
	void double2fraction();		//Floating point input, fractional output
	void fraction2double();		//Fractional input, floating point output
	void fractionAdd();			//Fractional add
	void fractionSub();			//Fractional sub
	void fractionMul();			//Fractional multiplex
	void fractionDiv();			//Fractional divide
	void fractionCompare();		//Fractional compare
	void fractionIncrease();	//Fractional self increase(x++/y)
	void fractionDecrease();	//Fractional self decrease(x--/y)

};
#endif // !FUNCTIONS_H
