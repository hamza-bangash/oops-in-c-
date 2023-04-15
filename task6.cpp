/*Design a program that includes a base class named Animal, and two derived
classes, Bird and Reptile, that are privately inherited from the Animal class.
The Animal class has two public data members, the name and age of an
animal, and a method speak(), leave that empty here. The Bird class has an
additional private data member named wingLength, representing the length of
the bird's wings. The Reptile class has an additional private data member
named habitat, representing the environment where the reptile lives.
The sub classes will override the speak() method, which displays the name
and age of the animal along with a message indicating the type of the animal
and the sound it makes. The Bird class has a specific message indicating that
the bird can sing, while the Reptile class has a specific message indicating that
the reptile can creep.
The main function of the program should create an object of the Bird class
and an object of the Reptile class, initialize their data members using the
constructor, and call their speak() member function to display the information.
Note: None of your class should have getter and setter methods
Sample Output:*/

#include<iostream>

using namespace std;

class Animal
{
    public:
        string name;
        int age;
        void speat()
        {

        }
};
class Bird : private Animal
{
    float winglenght;
    public:
    Bird(string name ,int age)
    {
        this ->name = name;
        this ->age = age;
    }
    void speak ()
    {
        cout<<"\nName : "<<name;
        cout<<"\nAge  : "<<age;
        cout<<"\nI am   " <<name <<" i can sing";
    }
};
class Reptile : private Animal
{
    string habitat;
    public:
    void speak ()
    {
        cout<<"\nName : "<<name;
        cout<<"\nAge  : "<<age;
        cout<<"\nI am   "<<name<<" i can creep";
    }
    Reptile(string name ,int age)
        {
            this -> name = name;
            this -> age = age;
        }
};
int main()
{
    Bird bird("parrot",6);
    Reptile reptile("crocodile",8);
    bird.speak();
    cout<<endl<<endl;
    reptile.speak();
    cout<<endl<<endl;
return 0;
}
