/*Modify task 2 by using a friend class instead of declaring multiple friend functions.*/
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

    friend class Operation;
};

class Operation
{
    public:
    Complex addComplex(Complex obj1, Complex obj2)
    {
        Complex temp;

        temp.real = obj1.real + obj2.real;
        temp.imag = obj1.imag + obj2.imag;
        return temp;
    }
    Complex subComplex(Complex obj1, Complex obj2)
    {
        Complex temp;
        
        temp.real = obj1.real - obj2.real;
        temp.imag = obj1.imag - obj2.imag;
        return temp;
    }
};


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