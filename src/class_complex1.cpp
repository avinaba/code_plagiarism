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
Complex mult(Complex c);//Multiplication: z1. z2 = (x1x2 - y1y2) + i(x1y2 + x2y1)
Complex div(Complex c);
void print();
double getReal() const;
double getImag() const;
void setReal(double r);
void setImag(double i);
private:
double real, imag;
};
void reset(double,double, Complex&, Complex&);

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
Complex Complex::mult(Complex c){//real = x1, y1 = imag  c.real = x2, c.imag = y2
Complex mult;//Multiplication: z1. z2 = (x1x2 - y1y2) + i(x1y2 + x2y1)
mult.real = real*c.real - imag*c.imag;
mult.imag = real*c.imag + c.real*imag;
return mult;
}
Complex Complex::div(Complex c){
Complex div;//a=real,b=imag,c=c.real,d=c.imag
div.real = (real*c.real+imag*c.imag)/(c.real*c.real + c.imag*c.imag);
div.imag = (imag*c.real-real*c.imag)/(c.real*c.real + c.imag*c.imag);
return div;
}

void Complex::print(){
cout << '(' << real << ") + (" << imag << ")i" << endl;
}

void reset(double r1, double i1,Complex&a, Complex&c){
a.setReal(r1);
a.setImag(i1);
c.setReal(0);
c.setImag(0);
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
