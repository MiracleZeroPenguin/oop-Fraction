/********************************************************************************
* @File name: Fraction.h
* @Author: Miracle_Zero
* @Version: 1.0
* @Date: 2020-05-16
* @Description:Declaration of the class Fraction
********************************************************************************/
#ifndef FRACTION_H
#define FRACTION_H
class Fraction {
public:
	Fraction(void);			//Create a fration with numerator and denominator are both zero
	~Fraction();			//Delete the class

private:
	long numerator, denominator;

public:
	long common_divisor(long a, long b);	//get the greatest common divisor of numerator and denominator of the fraction
	long getNumerator();					//get the numerator of the fraction
	long getDenominator();					//get the denominator of the fraction
	void setNumerator(long);				//set the numerator of the fraction
	void setDenominator(long);				//set the denominator of the fraction
	bool simplify();						//simplify the numerator and the denominator of the fraction
	void double2fraction(double);			//Convert floating-point numbers to fractions
	double fraction2double();				
	bool string2fraction(std::string);
	bool operator<(Fraction);
	bool operator<=(Fraction);
	bool operator>(Fraction);
	bool operator>=(Fraction);
	bool operator==(Fraction);
	bool operator!=(Fraction);
	long operator%(Fraction);
	operator double();
	operator float();
	operator long();
	operator std::string();
	Fraction operator+(Fraction);
	Fraction operator+=(Fraction);
	Fraction operator-=(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator*=(Fraction);
	Fraction operator/(Fraction);
	Fraction operator/=(Fraction);
	Fraction operator++();
	Fraction operator--();
};

class FractionInputFailException :public std::exception {
public:
	virtual const char* what() const throw() {
		return "Incorrect Input!!!";
	}
};

/** Left Shift Operator overloading functions */
std::ostream& operator<<(std::ostream &out, Fraction &Fraction);
/** Right Shift Operator overloading functions */
std::istream& operator>>(std::istream &in, Fraction &Fraction);

#endif // !FRACTION_H
