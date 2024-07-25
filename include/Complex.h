// Here header files that expose the public interface and are to be installed
// TODO: maybe change name to myLibAPI

#pragma once

#include <ostream>


namespace myLib {

class Complex {
public:
	Complex(double re_, double im_);

	double Re() const {return re;}
	void Re(double re_) {re = re_;}

	double Im() const {return im;}
	void Im(double im_) {im = im_;}

	friend std::ostream& operator<<(std::ostream &out, const Complex &c);

	// TODO add other operators

private:
	double re, im;
};

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);


int multiply(int a, int b);
float multiply(float a, float b);
double multiply(double a, double b); 

}	// namespace myLib