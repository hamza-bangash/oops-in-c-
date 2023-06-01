/*Now make changes to existing code in a way that in the main, create an array of pointers to the
Animal class and populate it with objects of different derived classes. Pass this array to a
function named displayAll(). In that function call the display() method with each array element.
Finally, in main, at the end destroy the objects and release the memory. Make sure that the
child’s class objects should be destroyed.*/

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

void displayAll(Animal** animal,int size)
{
    for(int i=0;i<size;i++)
    {
     animal[i]->display();
     cout<<endl;
    }
}
int main()
{
    Animal* animal[2];

    animal[0]=new Deer("deer","brown",true);
    animal[1]=new Zebra("zibra","black","vertical");
    
    displayAll(animal,2);

    for(int i=0;i<2;i++)
    {
        delete animal[i];
    }

    cout<<endl<<endl;
}