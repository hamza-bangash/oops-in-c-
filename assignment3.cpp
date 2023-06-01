#include<iostream>
using namespace std;

class A
{
    int a;
    public:
   A()
   {
        a=0;
   }

//1. ! operator overloading 
   bool operator !()
   {
    
    if(!a)
        return true;
    else 
      return false;
   }

//2. && operator overloading
   bool operator &&(const A &obj)
   {
    if(a&&obj.a)
       return true;
    else 
        return false;
   }

//3. ^ operator overloading
   A operator ^(A &obj)
   {
    A temp;
    temp.a = a^ obj.a;
    return temp;
   }
//4. ++ operator overloading  
   A operator ++ (int dumy)
   {
    A temp;
     temp=*(this);
     ++(*this);
     return temp;
   }
//5. ++ operator overloading
A operator ++()
{
    ++a;
    return (*this);
}

//6. >> operator overloading 
    friend istream& operator>> (istream& cin,A& obj);

    int getData()
    {
        return a;
    }
};


istream& operator>> (istream& cin,A& obj)
{
    cin>>obj.a;
    return cin;
}
int main()
{
   A obj1,obj2;

   cout<<"\nEnter value of obj1 : ";
   cin>>obj1;
   cout<<"\nEnter value of obj2 : ";
   cin>>obj2;
   
  
    
   if(!(obj1&&obj2))
   {
    cout<<"\n\n condition is false ";
   }
   else
   {
    cout<<"\n\n condition is true ";
   }

    ++obj2;
   cout<<"\n\n\nvalue of obj during increment : "<<(obj1++).getData();
   cout<<"\nvlaue of obj after increment : "<<obj1.getData();


   A obj3= obj1^obj2;
    cout<<"\n\n Xnor of : "<<obj1.getData()<<"^"<<obj2.getData()<<" = "<<obj3.getData();

   cout<<endl<<endl;
}