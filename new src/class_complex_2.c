#include <iostream>

using namespace std;

class ComplexNumber {
 public:
   ComplexNumber(double real = 0.0, double imag = 0.0);

   friend ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b);

   friend ostream&      operator<<(ostream &out,           const ComplexNumber &c);

 private:
	float r;
	float i;
};


ComplexNumber::ComplexNumber(double rr, double ii) : r(rr), i(ii) {
}

ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;

	return result;
}

ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;

	return result;
}

ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = (a.r * b.r - a.i * b.i);
	result.i = (a.r * b.i + a.i * b.r);

	return result;
}

ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
	result.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);

	return result;
}

ostream& operator<< (ostream &out, const ComplexNumber &c) {
	out << c.r << "+" << c.i << "i";
	return out;
}
