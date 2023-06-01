/*Scenario: You are working on a project that involves complex numbers in C++. You have created
a class called "Complex" that represents a complex number. You want to implement a friend
function that adds two complex numbers together and returns the result.
Define a "Complex" class with the following private data members:
int real: the real part of the complex number
int imag: the imaginary part of the complex number
Define a friend function called "addComplex" that takes two "Complex" objects as arguments
and returns a new "Complex" object representing the sum of the two complex numbers. The
friend function should have the following signature:
Complex addComplex(Complex c1, Complex c2)
In the "Complex" class, define a public member function called "display" that displays the
complex number in the format a + bi, where a is the real part and b is the imaginary part.
In the main function, create two "Complex" objects and add them together using the
"addComplex" function. Display the result using the "display" function.*/
#include<iostream>
using namespace std;

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

    friend Complex  addComplex(Complex , Complex);
};

Complex addComplex(Complex obj1 , Complex obj2)
{
    Complex temp;
    temp.real = obj1.real + obj2.real;
    temp.imag = obj1.imag + obj2.imag;

    return temp;
}

int main()
{
    Complex obj1(5,6);
    obj1.display();
    Complex obj2(3,2);
    obj2.display();

cout<<"\n--------Results-------\n";
    Complex obj3;
    obj3 = addComplex(obj1,obj2);
    obj3.display();

    cout<<endl<<endl;
}