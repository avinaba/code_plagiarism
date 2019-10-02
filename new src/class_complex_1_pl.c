#include <iostream>
using namespace std;

class complex_var{
public:
complex_var();
complex_var(double r);
complex_var(double r, double i);
complex_var(complex_var &obj);
complex_var add_complex_var(complex_var c);
complex_var sub_complex_var(complex_var c);
complex_var mult_complex_var(complex_var c);
complex_var div_complex_var(complex_var c);
void print();
double getReal() const;
double getImag() const;
void setReal(double r);
void setImag(double i);

private:
double real, imag;
void reset();
};

complex_var::complex_var(double r=0,double i=0){
real = r;
imag = i;
}

complex_var::complex_var(complex_var &obj){
real = obj.real;
imag = obj.imag;
}

complex_var complex_var::add_complex_var(complex_var c){
complex_var sum;
sum.real = real + c.real;
sum.imag = imag + c.imag;
return sum;
}
complex_var complex_var::sub_complex_var(complex_var c){
complex_var sub_complex_var;
sub_complex_var.real = real - c.real;
sub_complex_var.imag = imag - c.imag;
return sub_complex_var;
}
complex_var complex_var::mult_complex_var(complex_var c){
complex_var mult_complex_var;
mult_complex_var.real = real*c.real - imag*c.imag;
mult_complex_var.imag = real*c.imag + c.real*imag;
return mult_complex_var;
}
complex_var complex_var::div_complex_var(complex_var c){
complex_var div_complex_var;
div_complex_var.real = (real*c.real+imag*c.imag)/(c.real*c.real + c.imag*c.imag);
div_complex_var.imag = (imag*c.real-real*c.imag)/(c.real*c.real + c.imag*c.imag);
return div_complex_var;
}

void complex_var::print(){
cout << '(' << real << ") + (" << imag << ")i" << endl;
}

double complex_var::getReal() const{
return real;
}
double complex_var::getImag() const{
return imag;
}
void complex_var::setReal(double r){
real = r;
}
void complex_var::setImag(double i){
imag = i;
}

void complex_var::reset(){
	setReal(0);
	setImag(0);
}