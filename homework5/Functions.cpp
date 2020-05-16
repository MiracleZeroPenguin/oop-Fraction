/********************************************************************************
* @File name: Functions.cpp
* @Author: Miracle_Zero
* @Version: 1.0
* @Date: 2020-05-16
* @Description:Definitin of Function used in top module
********************************************************************************/
#include"Functions.h"

/*
@function:	Functions()
@for:		Functions
@description:	Create Functions class and begin calculation
*/
Functions::Functions() {
	printInfo();
	classifyFunc();
	system("pause");
}

/*
@function:	~Functions()
@for:		Functions
@description:	End the calculation and back to menu
*/
Functions::~Functions() {
	system("cls");
}

/*
@function:	printInfo()
@for:		Functions
@description:	Print the menu of the calculation
*/
void Functions::printInfo() {
	cout << "Please enter the function serial number to be tested\n" << endl;
	cout << "1: Convert double to fraction\n"
		<< "2: Convert fraction to double (x/y)\n"
		<< "3: +\tAdd two fractions\n"
		<< "4: -\tSubtract two fractions\n"
		<< "5: *\tMultiply two fractions\n"
		<< "6: ¡Â\tDivide two fractions\n"
		<< "7: < <= == != >= >\tCompare two fractions\n"
		<< "8: ++\tSelf increasing\n"
		<< "9: --\tSelf decreasing\n"
		<< "10: Exit\n\n"
		<< "> ";
}

/*
@function:	classifyFunc()
@for:		Functions
@description:	Jump to different fractional calculation functions according to different instructions
@input:		istream(int)
*/
void Functions::classifyFunc() {
	int choice;
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1: {
		//1: Convert double to fraction
		double2fraction();
		break;
	}
	case 2: {
		//2: Convert fraction to double(x / y)
		fraction2double();
		break;
	}
	case 3: {
		//3: +\tAdd two fractions
		fractionAdd();
		break;
	}
	case 4: {
		//4: -\tSubtract two fractions
		fractionSub();
		break;
	}
	case 5: {
		//5: *\tMultiply two fractions
		fractionMul();
		break;
	}
	case 6: {
		//6: ¡Â\tDivide two fractions
		fractionDiv();
		break;
	}
	case 7: {
		//7: < <= == != >= > Compare two fractions
		fractionCompare();
		break;
	}
	case 8: {
		//8: ++\tSelf increasing
		fractionIncrease();
		break;
	}
	case 9: {
		//9: --\tSelf decreasing
		fractionDecrease();
		break;
	}
	case 10: {
		//10:exit
		exit = true;
	}
	default: {
		cout << "Please enter the correct instruction number!!!" << endl;
	}
	}
}

/*
@function:	double2fraction()
@for:		Functions
@description:	Floating point input, fractional output
@input:		istream(floating point)
@output:	ostream(fraction)
*/
void Functions::double2fraction() {
	Fraction fraction;
	string input;
	cout << "Please enter a floating point number like 1.55:" << endl;
	cin >> input;
	fraction.double2fraction(input);
	cout << "The fraction of " << input << " is " << fraction.operator std::string()<<endl;	
}

/*
@function:	fraction2double()
@for:		Functions
@description:	Fraction input, float point number output
@input:		istream(fraction)
@output:	ostream(float point)
*/
void Functions::fraction2double() {
	Fraction fraction;
	double output;
	cout << "Please enter a Fraction like 5/11:";
	try {
		cin >> fraction;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "The float point number of " << fraction << " is ";
	cout << fraction.fraction2double() << endl;
}

/*
@function:	fractionAdd()
@for:		Functions
@description:	Fractional add
@input:		istream(fraction a),istream(fraction b)
@output:	ostream(fraction a+b)
*/
void Functions::fractionAdd() {
	Fraction a, b, ans;
	cout << "Please enter the first franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "Please enter the second franction: ";
	try {
		cin >> b;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	ans = a + b;
	cout << "Answer\t";
	cout << a << " + " << b << " = " << ans.operator std::string() << endl;
}

/*
@function:	fractionSub()
@for:		Functions
@description:	Fractional sub
@input:		istream(fraction a),istream(fraction b)
@output:	ostream(fraction a-b)
*/
void Functions::fractionSub() {
	Fraction a, b, ans;
	cout << "Please enter the first franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "Please enter the second franction: ";
	try {
		cin >> b;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	ans = a - b;
	cout << "Answer\t";
	cout << a << " - " << b << " = " << ans.operator std::string() << endl;
}

/*
@function:	fractionMul()
@for:		Functions
@description:	Fractional multiplex
@input:		istream(fraction a),istream(fraction b)
@output:	ostream(fraction a*b)
*/
void Functions::fractionMul() {
	Fraction a, b, ans;
	cout << "Please enter the first franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "Please enter the second franction: ";
	try {
		cin >> b;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	ans = a * b;
	cout << "Answer\t";
	cout << a << " * " << b << " = " << ans.operator std::string() << endl;
}

/*
@function:	fractionDiv()
@for:		Functions
@description:	Fractional divide
@input:		istream(fraction a),istream(fraction b)
@output:	ostream(fraction a/b)
*/
void Functions::fractionDiv() {
	Fraction a, b, ans;
	cout << "Please enter the first franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "Please enter the second franction: ";
	try {
		cin >> b;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	ans = a / b;
	cout << "Answer\t";
	cout << a << " ¡Â " << b << " = " << ans.operator std::string() << endl;
}

/*
@function:	fractionCompare()
@for:		Functions
@description:	Fractional compare
@input:		istream(fraction a),istream(fraction b)
@output:	ostream(fraction a<?>b)
@others:	< <= > >= == !=
*/
void Functions::fractionCompare() {
	Fraction a, b;
	cout << "Please enter the first franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << "Please enter the second franction: ";
	try {
		cin >> b;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	if (a == b) {
		cout << a << " == " << b << endl;
	}
	if (a < b) {
		cout << a << " < " << b << endl;
	}
	if (a <= b) {
		cout << a << " <= " << b << endl;
	}
	if (a > b) {
		cout << a << " > " << b << endl;
	}
	if (a >= b) {
		cout << a << " >= " << b << endl;
	}
	if (a != b) {
		cout << a << " != " << b << endl;
	}
}

/*
@function:	fractionIncrease()
@for:		Functions
@description:	Fractional selfish increase
@input:		istream(fraction a)
@output:	ostream(fraction a++)
*/
void Functions::fractionIncrease() {
	Fraction a;
	cout << "Please enter the franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << a.operator std::string() << "++ = ";
	++a;
	cout << a.operator std::string() << endl;
}

/*
@function:	fractionDecrease()
@for:		Functions
@description:	Fractional selfish decrease
@input:		istream(fraction a)
@output:	ostream(fraction a--)
*/
void Functions::fractionDecrease() {
	Fraction a;
	cout << "Please enter the franction: ";
	try {
		cin >> a;
	}
	catch (exception& e) {
		system("cls");
		cout << e.what();
		return;
	}
	cout << a.operator std::string() << "-- = ";
	--a;
	cout << a.operator std::string() << endl;
}