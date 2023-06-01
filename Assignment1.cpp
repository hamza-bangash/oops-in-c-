#include<iostream>
using namespace std;

class A
{
    int a,b,c;
    public:
    A()
    {}
    A(int a)
    {
        this->a=a;
    }
    A(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    A(int a,int b,int c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }

    void fun(int a,int b)
    {
        cout<<"\na :"<<a;
        cout<<"\nb :"<<b;
    }
   void fun(double a,double b)
   {
    cout<<"\na :"<<a;
    cout<<"\nb :"<<b;
   }
  
};

class B
{
    int a,b,c;
    public:
    B(int a=0,int b=0, int c=0)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

class C
{
    int a,b,c;
    public:
    //C(){}//we cant use now less tha three argument constructer
    C(int a=0,int b=0, int c=0)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

int main()
{
    A a1;
    A a2(1);
    A a3(1,2);
    A a4(1,2,3);

    B b1;
    B b2(1);
    B b3(1,2);
    B b4(1,2,3);

    C c1;
    C c2(1);
    C c3(1,2);
    C c4(1,2,3);
 cout<<"\n Passing integer type value : ";
    a1.fun(5,10);
   
cout<<"\n Passing Double type value  : ";
    a1.fun(5.5,10.5);
    

    cout<<endl<<endl;
}