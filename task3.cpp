/*Write the definition for a class called Rectangle that has floating point data members
length and width. The class has the following member functions:
void setlength(float) to set the length data member
void setwidth(float) to set the width data member
float perimeter() to calculate and return the perimeter of the rectangle
float area() to calculate and return the area of the rectangle
void show() to display the length and width of the rectangle
int sameArea(Rectangle) that has one parameter of type Rectangle. sameArea returns 1 if the
two Rectangles have the same area, and returns 0 if they don&#39;t.
1. Write the definitions for each of the above member functions.
2. Write main function to create two rectangle objects. Set the length and width of the first
rectangle to 5 and 2.5. Set the length     and width of the second rectangle to 5 and 18.9. Display
each rectangle and its area and perimeter.

3. Check whether the two Rectangles have the same area and print a message indicating the
result. Set the length and width of the     first rectangle to 15 and 6.3. Display each Rectangle and
its area and perimeter again. Again, check whether the two     Rectangles have the same area and
print a message indicating the result.*/

#include<iostream>
using namespace std;

class Rectangle // specifiying structe
{
    float lenght;   // define varables
    float width;
    public:
    void setLenght(float lenght)  // to set a value to lenght
    {
        this -> lenght = lenght;
    }
    void setWidth(float width)  // to set value to width
    {
        this -> width = width;
    }
    float calculateParameters()  // calculating parameters of rectangle 
    {
        return ((2*lenght) + (2*width));
    }
    float area()  // calculating area of rectangle
    {
        return (lenght * width);
    }
    void show()  // show the lenght and width of rectangle 
    {
        cout<<"\n the lenght is :  "<<lenght;
        cout<<"\n the width is  :  "<<width;
    }

    int sameArea (Rectangle obj)
    {
        if(obj.area() == area())
          return 1;
        else
          return 0;
    }
};

int main()
{
    Rectangle obj1,obj2; //creating a 2 object of rectangle

    obj1.setLenght(5);    // calling a function to set value of data member
    obj1.setWidth(2.5);

    obj2.setLenght(5);
    obj2.setWidth(18.9);
   

    obj1.show(); // printing the lenght and width of obj1
    cout<<"\n parameters of rectangle : " <<obj1.calculateParameters(); // printing parameters of rectangle 
    cout<<"\n area of rectangle  : "<<obj1.area(); //printing area of rectangle

    obj2.show(); // printing the lenght and width of obj2
    cout<<"\n parameters of rectangle : " <<obj2.calculateParameters(); // printing parameters of rectangle 
    cout<<"\n area of rectangle  : "<<obj2.area(); //printing area of rectangle
    cout<<"\n sameArea : "<<obj1.sameArea(obj2)<<endl<<"----------------------\n ";   //comapring area of reactangle

     obj1.setLenght(15);    // calling a function to set value of data member
    obj1.setWidth(6.3);


    obj1.show(); // printing the lenght and width of obj1
    cout<<"\n parameters of rectangle : " <<obj1.calculateParameters(); // printing parameters of rectangle 
    cout<<"\n area of rectangle  : "<<obj1.area(); //printing area of rectangle

    obj2.show(); // printing the lenght and width of obj2
    cout<<"\n parameters of rectangle : " <<obj2.calculateParameters(); // printing parameters of rectangle 
    cout<<"\n area of rectangle  : "<<obj2.area(); //printing area of rectangle
    cout<<"\n sameArea : "<<obj1.sameArea(obj2) <<endl<<"\n ---------------------------------- \n";   //comapring area of reactangle

   return 0;
}