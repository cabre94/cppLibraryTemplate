#include "Complex.h"
#include "other.h"

#include <ostream>

namespace myLib {

Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

inline double Complex::Re() const {return re;}

inline void Complex::Re(double re_) {re = re_;}

inline double Complex::Im() const {return im;}

inline void Complex::Im(double im_) {im = im_;}

std::ostream& operator<<(std::ostream &out, const Complex &c){

	if(c.re == 0 && c.im ==0)
		out << 0;
	else if(c.re != 0)
		out << c.re;

	if(c.im == 1 && c.re == 0)
		out << "i";
	else if(c.im == 1)
		out << "+i";
	else if(c.im == -1)
		out << "-i";
	else if(c.im > 0)
		out << "+i" << c.im;
	else if(c.im < 0)
		out << "-i" << -1*c.im;

    return out;
}

Complex operator+(const Complex& c1, const Complex& c2){
	return { c1.Re() + c2.Re(), c1.Im() + c2.Im() };
}

Complex operator-(const Complex& c1, const Complex& c2){
	return { c1.Re() - c2.Re(), c1.Im() - c2.Im() };
}

Complex operator*(const Complex& c1, const Complex& c2){
	return { c1.Re() * c2.Re() - c1.Im() * c2.Im(),
			 c1.Re() * c2.Im() + c1.Im() * c2.Re()};
}

Complex operator/(const Complex& c1, const Complex& c2){
	double den = c2.Re() * c2.Re() + c2.Im() * c2.Im();

	return { (c1.Re()*c2.Re() + c1.Im()*c2.Im()) / den,
			 (c1.Im()*c2.Re() - c1.Re()*c2.Im()) / den};
}



int multiply(int a, int b){
    return a*b;
}

float multiply(float a, float b){
    return a*b;
}

double multiply(double a, double b){
    return a*b;
}

}	// namespace myLib