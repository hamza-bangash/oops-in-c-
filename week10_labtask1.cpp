/*You are required to design a program for a zoo where there are different types and categories
of animals. Use Inheritance and polymorphism to write a maintainable code.
Animal is an abstract class with two protected data members name and color, destructor, and a
pure virtual function display().
Deer is derived from Animal and has an additional boolean data member hasAntlers, indicating
whether or not the deer has antlers. Deer overrides the display() function to print information
about the deer's name, color, and whether or not it has antlers.
Zebra is derived from Animal and has an additional string data member stripe_pattern,
indicating the pattern of stripes on the zebra's body. Zebra overrides the display() function to
print information about the zebra's name, color, and stripe pattern.
In main, using polymorphism create child’s class objects and call their display() methods.*/

#include<iostream>
using namespace std;

class Animal
{
    protected:
    string name;
    string color;

    public:
    virtual void display()=0;
    ~Animal()
    {

    }
};

class Deer : public Animal
{
    bool hasAntlers;
    
    public:
    Deer(string name,string color, bool hasAntlers)
    {
        this->name=name;
        this->color=color;
        this->hasAntlers=hasAntlers;
    }
    void display()
    {
        cout<<"\nName : "<<name;
        cout<<"\ncolor: "<<color;
        cout<<"\nhasAntlers : "<<hasAntlers;
    }
};

class Zebra : public Animal
{
    string stripe_pattern;

    public:
    
    Zebra(string name, string color , string stripe_pattern)
    {
        this->color=color;
        this->name=name;
        this->stripe_pattern=stripe_pattern;
    }
     void display()
    {
        cout<<"\nName : "<<name;
        cout<<"\ncolor: "<<color;
        cout<<"\nstripe pattern : "<<stripe_pattern;
    }   
};

int main()
{
    Animal* deer=new Deer("deer","brown",true);
    deer->display();

    Animal* zebra=new Zebra("zibra","black","vertical");
  
    zebra->display();

    cout<<endl<<endl;
}