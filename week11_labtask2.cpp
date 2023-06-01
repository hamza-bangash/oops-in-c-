/*Modify the first program by defining another class named Operations, that contains the methods
for adding and subtracting the complex numbers. In main create two objects of the complex class
and using the methods defined in the Operaions class, add and subtract those numbers, and
display the results.*/
#include<iostream>
using namespace std;

class Complex;
class Operation
{
    public:
    Complex addComplex(Complex ,Complex );
    Complex subComplex(Complex , Complex );
    
};

class Complex
{
    private:
    int real;
    int imag;

    public:

   Complex(int real=0,int imag=0) // defult parametized constructer
    {
     this->real = real;
     this->imag = imag;
    }
    void display()
    {
       cout<<"complex number is : "<<real<<"+"<<imag<<"i\n";
    }
    friend Complex Operation::addComplex(Complex ,Complex );
    friend Complex Operation::subComplex(Complex ,Complex );
};

    Complex Operation::addComplex(Complex obj1, Complex obj2)
    {
        Complex temp;

        temp.real = obj1.real + obj2.real;

        temp.imag = obj1.imag + obj2.imag;

        return temp;
    }
    Complex Operation::subComplex(Complex obj1, Complex obj2)
    {
        Complex temp;
        
        temp.real = obj1.real - obj2.real;
        temp.imag = obj1.imag - obj2.imag;
        
        return temp;
    }

int main()
{
    Complex obj1(5,6);
    obj1.display();
    Complex obj2(3,2);
    obj2.display();

cout<<"\n--------Addition-------\n";
    Complex obj3;
   Operation obj;
   obj3 = obj.addComplex(obj1,obj2);
   obj3.display();
cout<<"\n--------Subtraction-------\n";
    Complex obj4;
    obj4 = obj.subComplex(obj1,obj2);
    obj4.display();

    cout<<endl<<endl;
}