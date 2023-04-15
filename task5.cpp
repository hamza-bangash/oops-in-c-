/*Scenario: You are developing a contact management software that allows users to
keep track of their contacts. Each contact in the software consists of a person's name,
phone number, email address, and date of birth. You want to implement this system
using object-oriented programming principles, with a composition relationship.
Here, the class Contact is composed of n numbers of contacts(array of contacts).
And the total count of contacts(size of array), each contact is composed of the object
of date of birth class plus some other data members like name, phone_no, and email.
Also design a method in the ContactBook class to print the names of all contacts in
the book who have a birthday in a specific month.
Create a class diagram in Draw.io for the whole scenario. You must submit the cpp
file and also the png file of the class diagram.
Note: Your program must fulfill the criteria of composition.*/

#include <iostream>
using namespace std;

class DOB // class
{
    int day,month,year; // deaclare variables
    public:// access specifier
        DOB() // defulat parameters
        {
            while (true)
            {
                cout<<"Enter a day : ";
                cin>>day;
                cout<<"Enter a month : ";
                cin>>month;
                cout<<"Enter a year : ";
                cin>>year;

                if((day>30 || day<=0) || (month>12 || month<=0 ) || (year>2023 || year<=0)) // check date 
                {
                    cout<<"\n invalid date  plz try again : "<<endl;
                }

                else
                {
                    break;
                }
            }
            
        }
        int getDay()
        {
            return day;
        }
        int getMonth()
        {
            return month;
        }
        int getYear()
        {
            return year;
        }

};
class Contacts // class
{
    string name,email,phone; // decalare varables
    DOB date;// decalare obj of class Dob
    public : // access specifier
        Contacts()
        {

            cout<<"Enter a name : ";
            cin>>name;
            cout<<"Enter a eamil : ";
            cin>>email;
            cout<<"Enter a phone number ";
            cin>>phone;

            cout<<" ------------------------------\n ";
        }
        int getMonth()
        {
            return date.getMonth();
        }
        string getName()
        {
            return name;
        }
        string getEmail()
        {
            return email;
        }

        string getPhone()
        {
            return phone;
        }
        void dispalydob()
        {
            cout<<"\nDate of brith : "<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();
        }
};
class Bookofcontacts // decalare a class
{ 
    int size;
    Contacts* contact;
    public :

    Bookofcontacts(int size)
        {
            this -> size = size;
            contact = new Contacts[size];
        }
        void displaycontact()
        {
            for(int i=0;i<size;i++)
            {
                cout<<"\nName : "<<contact[i].getName();
                cout<<"\nEmail : "<<contact[i].getEmail();
                cout<<"\nPhoneNo : "<<contact[i].getPhone();
                contact[i].dispalydob();
                cout<<endl<<endl;
            }
        }
        void specificmonthname(int month)
        {
            for(int i=0;i<size;i++)
            {

                if(contact[i].getMonth()==month)
                {
                    cout<<"\nname is : "<<contact[i].getName();
                }
            }
        }
};


int main()
{
    int size;
    cout<<"\nEnter the number of contacts : ";
    cin>>size;

    Bookofcontacts obj(size);

    obj.displaycontact();

    int month;

    cout<<"\nEnter a specificmonth  to prints name : ";
    cin>>month;
    if(month>12 || month<=0)
    {
        cout<<"\n Invalid data ";
    }
    else
    obj.specificmonthname(month);

    cout<<endl<<endl;

    return 0;
}