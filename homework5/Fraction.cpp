/********************************************************************************
* @File name: Fraction.cpp
* @Author: Miracle_Zero
* @Version: 1.0
* @Date: 2020-05-16
* @Description:Definitin of functions used in the class Fraction
********************************************************************************/
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string.h>
#include<vector>
#include"Fraction.h"
using namespace std;

/*
@function:	Fraction()
@for:		Fraction
@description:	Create a fration with numerator and denominator are both zero
*/
Fraction::Fraction() {
	this->numerator = 0;
	this->denominator = 0;
}

/*
@function:	~Fraction()
@for:		Fraction
@description:	Delete the class
*/
Fraction::~Fraction() {

}

/*
@function:	common_divisor(long a, long b)
@for:		Fraction
@description:	get the greatest common divisor of numerator and denominator of the fraction
@input:		long a,long b
@output:	long gcd
*/
long Fraction::common_divisor(long a, long b) {
	if (b == 0)return a;
	else
		return this->common_divisor(b, a%b);
}

/*
@function:	getNumerator()
@for:		Fraction
@description:	get the numerator of the fraction
@output:	long numerator
*/
long Fraction::getNumerator() {
	return this->numerator;
}

/*
@function:	getDenominator()
@for:		Fraction
@description:	get the denominator of the fraction
@output:	long denominator
*/
long Fraction::getDenominator() {
	return this->denominator;
}

/*
@function:	setNumerator(long)
@for:		Fraction
@description:	set the numerator of the fraction
@input:		long numerator
*/
void Fraction::setNumerator(long n) {
	this->numerator = n;
}

/*
@function:	setDenominator(long)
@for:		Fraction
@description:	set the denominator of the fraction
@input:		long denominator
*/
void Fraction::setDenominator(long d) {
	this->denominator = d;
}

/*
@function:	simplify()
@for:		Fraction
@description:	simplify the numerator and the denominator of the fraction
*/
bool Fraction::simplify() {
	long gcd = this->common_divisor(this->numerator, this->denominator);
	if (gcd > 1) {
		this->numerator = this->numerator / gcd;
		this->denominator = this->denominator / gcd;
		return true;
	}
	else {
		return false;
	}
}

/*
@function:	double2fraction(double)
@for:		Fraction
@description:	Convert floating-point numbers to fractions
@input:		double input
*/
void Fraction::double2fraction(double input) {
	this->setDenominator(1);
	while((int)input != input) {
		input = input * 10;
		this->setDenominator(this->getDenominator() * 10);
	}
	this->setNumerator((long)input);
	this->simplify();
}

/*
@function:	fraction2double()
@for:		Fraction
@description:	Convert fractions to floating-point numbers
@output:		double output
*/
double Fraction::fraction2double() {
	double ans;
	ans = (double)this->numerator / this->denominator;
	return ans;
}

/*
@function:	string2fraction(string input)
@for:		Fraction
@description:	Convert string to fraction
@input:		string like a/b
@output:	error or not
*/
bool Fraction::string2fraction(string input) {
	size_t p = input.find("/");
	if (p != string::npos) {
		try {
			this->numerator = atol(input.substr(0, p).c_str());
			this->denominator = atol(input.substr(p + 1).c_str());
		}
		catch (...) {
			return false;
		}
		if (this->denominator == 0)return false;
		else return true;
	}
	else {
		return false;
	}
}

/*
@function:	operator<(Fraction input)
@for:		Fraction
@description:	Redefining the < of the fraction class
@others:	a/b<x/y	<=>		a*y<b*x
*/
bool Fraction::operator<(Fraction input) {
	if (this->numerator*input.getDenominator() < this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator<=(Fraction input)
@for:		Fraction
@description:	Redefining the <= of the fraction class
@others:	a/b<=x/y	<=>		a*y<=b*x
*/
bool Fraction::operator<=(Fraction input) {
	if (this->numerator*input.getDenominator() <= this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator>(Fraction input)
@for:		Fraction
@description:	Redefining the > of the fraction class
@others:	a/b>x/y		<=>		a*y>b*x
*/
bool Fraction::operator>(Fraction input) {
	if (this->numerator*input.getDenominator() > this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator>=(Fraction input)
@for:		Fraction
@description:	Redefining the >= of the fraction class
@others:	a/b>=x/y	<=>		a*y>=b*x
*/
bool Fraction::operator>=(Fraction input) {
	if (this->numerator*input.getDenominator() >= this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator==(Fraction input)
@for:		Fraction
@description:	Redefining the == of the fraction class
@others:	a/b==x/y	<=>		a*y==b*x
*/
bool Fraction::operator==(Fraction input) {
	if (this->numerator*input.getDenominator() == this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator!=(Fraction input)
@for:		Fraction
@description:	Redefining the != of the fraction class
@others:	a/b!=x/y	<=>		a*y!=b*x
*/
bool Fraction::operator!=(Fraction input) {
	if (this->numerator*input.getDenominator() != this->denominator*input.getNumerator())
		return true;
	else
		return false;
}

/*
@function:	operator%(Fraction input)
@for:		Fraction
@description:	Redefining the % of the fraction class
@others:	a/b % x/y = (a*y % b*x) / (b*y)
*/
long Fraction::operator%(Fraction input) {
	long ans;
	ans = ((this->numerator*input.getDenominator()) % (this->denominator*input.getNumerator())) / (this->denominator*input.getDenominator());
	return ans;
}

/*
@function:	operator double()
@for:		Fraction
@description:	Output fraction in double
*/
Fraction::operator double() {
	return this->fraction2double();
}

/*
@function:	operator double()
@for:		Fraction
@description:	Output fraction in float
*/
Fraction::operator float() {
	return (float)this->fraction2double();
}

/*
@function:	operator long()
@for:		Fraction
@description:	Output fraction in long
*/
Fraction::operator long() {
	return (long)this->fraction2double();
}

/*
@function:	operator long()
@for:		Fraction
@description:	Output the simplified fraction in string
*/
Fraction::operator std::string() {
	stringstream output;
	this->simplify();
	if (this->denominator == 1) {
		output << this->getNumerator();
	}
	else
		output << this->getNumerator() << "/" << this->getDenominator();
	return output.str();
}

/*
@function:	operator+(Fraction input)
@for:		Fraction
@description:	Redefining the + of the fraction class
@others:	a/b + x/y = (a*y + b*x) / (b*y)
*/
Fraction Fraction::operator+(Fraction input) {
	Fraction ans;
	if (this->denominator == input.getDenominator()) {
		ans.setDenominator(this->denominator);
		ans.setNumerator(this->numerator + input.getNumerator());
	}
	else {
		ans.setDenominator(this->denominator*input.getDenominator());
		ans.setNumerator(this->denominator*input.getNumerator() + this->numerator*input.getDenominator());
	}
	return ans;
}

/*
@function:	operator+=(Fraction input)
@for:		Fraction
@description:	Redefining the += of the fraction class
@others:	a/b + x/y = (a*y + b*x) / (b*y)
*/
Fraction Fraction::operator+=(Fraction input) {
	if (this->denominator == input.getDenominator()) {
		this->numerator += input.getNumerator();
	}
	else {
		this->numerator = this->denominator*input.getNumerator() + this->numerator*input.getDenominator();
		this->denominator = this->denominator*input.getDenominator();
	}
	return *this;

}

/*
@function:	operator-=(Fraction input)
@for:		Fraction
@description:	Redefining the -= of the fraction class
@others:	a/b - x/y = (a*y - b*x) / (b*y)
*/
Fraction Fraction::operator-=(Fraction input) {
	if (this->denominator == input.getDenominator()) {
		this->numerator -= input.getNumerator();
	}
	else {
		this->numerator = this->denominator*input.getNumerator()- this->numerator*input.getDenominator();
		this->denominator = this->denominator*input.getDenominator();
	}
	return *this;
}

/*
@function:	operator-(Fraction input)
@for:		Fraction
@description:	Redefining the - of the fraction class
@others:	a/b - x/y = (a*y - b*x) / (b*y)
*/
Fraction Fraction::operator-(Fraction input) {
	Fraction ans;
	if (this->denominator == input.getDenominator()) {
		ans.setDenominator(this->denominator);
		ans.setNumerator(this->numerator - input.getNumerator());
	}
	else {
		ans.setDenominator(this->denominator*input.getDenominator());
		ans.setNumerator(this->denominator*input.getNumerator() - this->numerator*input.getDenominator());
	}
	return ans;
}

/*
@function:	operator*(Fraction input)
@for:		Fraction
@description:	Redefining the * of the fraction class
@others:	a/b * x/y = (a*x) / (b*y)
*/
Fraction Fraction::operator*(Fraction input) {
	Fraction ans;
	ans.setNumerator(this->numerator*input.getNumerator());
	ans.setDenominator(this->denominator*input.getDenominator());
	return ans;
}

/*
@function:	operator*=(Fraction input)
@for:		Fraction
@description:	Redefining the *= of the fraction class
@others:	a/b * x/y = (a*x) / (b*y)
*/
Fraction Fraction::operator*=(Fraction input) {
	this->denominator *= input.getDenominator();
	this->numerator *= input.getNumerator();
	return *this;
}

/*
@function:	operator/(Fraction input)
@for:		Fraction
@description:	Redefining the / of the fraction class
@others:	(a/b) / (x/y) = (a*y) / (b*x)
*/
Fraction Fraction::operator/(Fraction input) {
	Fraction ans;
	ans.setDenominator(this->denominator*input.getNumerator());
	ans.setNumerator(this->numerator*input.getDenominator());
	return ans;
}

/*
@function:	operator/=(Fraction input)
@for:		Fraction
@description:	Redefining the /= of the fraction class
@others:	(a/b) / (x/y) = (a*y) / (b*x)
*/
Fraction Fraction::operator/=(Fraction input) {
	this->denominator *= input.getNumerator();
	this->numerator *= input.getDenominator();
	return *this;
}

/*
@function:	operator++(Fraction input)
@for:		Fraction
@description:	Redefining the ++ of the fraction class
@others:	(a/b)++=(a+1/b)
*/
Fraction Fraction::operator++() {
	this->numerator += 1;
	return *this;
}
/*
@function:	operator--(Fraction input)
@for:		Fraction
@description:	Redefining the -- of the fraction class
@others:	(a/b)--=(a-1/b)
*/
Fraction Fraction::operator--() {
	this->numerator -= 1;
	return *this;
}

/*
@function:	operator<<(std::ostream &out, Fraction &Fraction)
@for:		Public
@description:	Redefining the cout<< of the fraction class
*/
std::ostream& operator<<(std::ostream &out, Fraction &Fraction) {
	
	out << Fraction.getNumerator() << "/" << Fraction.getDenominator();
	return out;
}

/*
@function:	operator>>(std::istream &in, Fraction &Fraction)
@for:		Public
@description:	Redefining the cin>> of the fraction class
*/
std::istream& operator>>(std::istream &in, Fraction &Fraction) {
	string input;
	in >> input;
	bool valid = Fraction.string2fraction(input);
	if (!valid) {
		throw FractionInputFailException();
	}
	return in;
}