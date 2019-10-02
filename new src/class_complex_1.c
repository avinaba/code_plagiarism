#include <iostream>
using namespace std;

class Complex{
public:
Complex();
Complex(double r);
Complex(double r, double i);
Complex(Complex &obj);
Complex add(Complex c);
Complex sub(Complex c);
Complex mult(Complex c);
Complex div(Complex c);
void print();
double getReal() const;
double getImag() const;
void setReal(double r);
void setImag(double i);
private:
double real, imag;
void reset();
};

Complex::Complex(){
real = imag = 0;
}

Complex::Complex(double r){
real = r;
imag = 0;
}

Complex::Complex(double r, double i){
real = r;
imag = i;
}

Complex::Complex(Complex &obj){
real = obj.real;
imag = obj.imag;
}

Complex Complex::add(Complex c){
Complex sum;
sum.real = real + c.real;
sum.imag = imag + c.imag;
return sum;
}
Complex Complex::sub(Complex c){
Complex sub;
sub.real = real - c.real;
sub.imag = imag - c.imag;
return sub;
}
Complex Complex::mult(Complex c){
Complex mult;
mult.real = real*c.real - imag*c.imag;
mult.imag = real*c.imag + c.real*imag;
return mult;
}
Complex Complex::div(Complex c){
Complex div;
div.real = (real*c.real+imag*c.imag)/(c.real*c.real + c.imag*c.imag);
div.imag = (imag*c.real-real*c.imag)/(c.real*c.real + c.imag*c.imag);
return div;
}

void Complex::print(){
cout << '(' << real << ") + (" << imag << ")i" << endl;
}

void Complex::reset(){
setReal(0);
setImag(0);
}

double Complex::getReal() const{
return real;
}
double Complex::getImag() const{
return imag;
}
void Complex::setReal(double r){
real = r;
}
void Complex::setImag(double i){
imag = i;
}
