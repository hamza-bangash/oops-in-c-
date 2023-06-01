#include<iostream>
#include<fstream>
#include<string.h>
#include <limits>
#include<stdio.h>

using namespace std;


/////// fuction protypes///////
void mainmenu();
void addministrativemenu();
void studentmenu();
void facultymenu();

////////// address class  /////////////
class Address
{
/////// instance private data member
        char state[20];
        char city[20];
        int streetno;

    public:
/////////// defult constructer /////////
   Address()
    {
        strcpy(state,"N/A");
        strcpy(city ,"N/A");
        streetno =0;
    } 
//////// function which set data to variable from user
     void setData()
     {
        cout<<"Enter the state      : ";
        cin.getline(state,20);
        cout<<"Enter the City       : ";
        cin.getline(city,20);
        cout<<"Enter the streetno   : ";
        cin>>streetno;
        try
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw streetno;
            }
        }
        catch(...)
        {
            cout<<"\nPlz Enter integer type value : ";
            cout<<"\nEnter the streetno    : ";
            cin>>streetno;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   
        }
        
     } 
/////// method which print the data of address ///////
     void showData() 
     {
        cout<<"\nState      : "<<state;
        cout<<"\nCity       : "<<city;
        cout<<"\nstreet no  : "<<streetno;
     }
};
///////// person class //////////
class Person 
{
    protected :
        char name[20];
        char email[20];
        char phone[20];
        char password[20];  
//////// compestion is used///////
        Address address;  
    public:
///// defult constructer //////
   Person()
    {
        strcpy(name,"N/A");
        strcpy(email,"N/A");
        strcpy(phone,"N/A");
        strcpy(password,"N/A");
    } 
///////////function to set data from useer///////
   virtual void setData()=0;
////// function which show data //////////////
   virtual void showData(){}
/////////// this method will write data into file from object /////////
    virtual void writeData(){}
///////// this method will read data from file to obj ////////////////
    virtual void readData(){}
///////// this method will read data from file to obj according user search for ////////////////
    virtual int searchData(){return 0;}
////// this method get password and email from and confrim with file////////////
   virtual int  emailPassword(string email , string password){return 0;}
/////////////////this method will delete the record according to user input /////////////
   virtual void removeData(){}
};

//////////////  student class  /////////////////////
class Student: public Person
{
    private:
        double rollno;
        double gpa;
        char section;
    public:
///////// defult constructer /////////////
    Student()
    {
        rollno=0;
        gpa=0;
        section='?';
    }
//////////this method is used to set data to variables from user////////
   void setData();
/////////this function is used to print data of varaibles //////////////////
    void showData();
/////////// this method will write data into file from object /////////
    void writeData();
///////// this method will read data from file to obj ////////////////
    void readData();
///////// this method will read data from file to obj according user search for ////////////////
    int searchData();
////// this method get password and email from and confrim with file////////////
   int  emailPassword(string email , string password);
/////////////////this method will delete the record according to user input /////////////
    void removeData();
};

//////////this method is used to set to variable from user////////
 void Student::setData()
    {
        cout<<"\n\n\nEnter the name       : ";
        cin.getline(name, 20);
        cout<<"Enter the email      : ";
        cin.getline(email,20);
        cout<<"Enter the password   : ";
        cin.getline(password,20);
        cout<<"Enter the phone no   : ";
        cin.getline(phone,20);
        address.setData();
        cout<<"Enter the gpa        : ";
        cin>>gpa;
        cout<<"Enter the rollno     : ";
        cin>>rollno;
        cout<<"Enter the section    : ";
        cin>>section;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
/////////this function is used to print data of varaible //////////////////
    void Student::showData()
    {
        cout<<"\nName       : "<<name;
        cout<<"\nemail      : "<<email;
        cout<<"\nphone      : "<<phone;
        address.showData();
        cout<<"\nRollno     : "<<rollno;
        cout<<"\nsection    : "<<section;
        cout<<"\nGpa        : "<<gpa;   
    }
/////////// this method will write data into file from object /////////
    void Student::writeData()
    {
        if(!(strcmp(name,"N/A")==0 && strcmp(email,"N/A")==0))
        {
            ofstream obj("student.txt",ios::out | ios::app | ios::binary);
            obj.write((char*)this , sizeof(*this));
            obj.close();  
        }   
        else
        {
            cout<<"\nData is not initlze to write into file \n";
        }
    }
///////// this method will read data from file to obj ////////////////
    void Student::readData()
    {
        ifstream obj("student.txt",ios::in | ios::binary);
        if(obj)
        {
            int i=1;
            obj.read((char*)this , sizeof(*this));
            while(!obj.eof())
            {   
                cout<<"\n\n\n------Student No  "<<i++<<"-------\n";
                showData();
                obj.read((char*)this, sizeof(*this));
            }
            obj.close();
        }
        else 
        {
            cout<<"\nEorr file is not found ";
        }
        cout<<endl<<endl;
    }
///////// this method will read data from file to obj according user search for ////////////////
    int Student::searchData()
    {
        string name;
        double rollno;
        char section;
         
         cout<<"\n\n\t-----------------Enter the Information ---------------\n\n";
         cout<<"Enter the name   : ";
         getline(cin,name);
         cout<<"Enter the rollno : ";
         cin>>rollno;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout<<"Enter the section: ";
         cin>>section;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        ifstream obj("student.txt",ios::in | ios::binary);
        if(obj)
        {
            obj.read((char*)this, sizeof(*this));
            while(!obj.eof())
            {
                if(this->name == name && this->rollno == rollno & this->section == section)
                {
                    showData();
                    obj.close();
                    return 0;
                }
                obj.read((char*)this, sizeof(*this));  
            }
            obj.close();
            cout<<"\nRecord no found please Enter correct information :";
        }
        else 
        {
            cout<<"\nEorr file is not found ";
        }
        return 0;
    }
////// this method get password and email from and confrim with file////////////
   int  Student::emailPassword(string email , string password)
   {
        fstream obj("student.txt",ios::in | ios::binary);
        if(obj)
        {
            while(!obj.eof())
            {
                obj.read((char*)this,sizeof(*this));
                if(this->email == email  && this->password == password)
                {
                    obj.close();
                    cout<<"\n ------You Succefully Login-------- \n";
                    return 1;
                }
            }
            obj.close();
            cout<<"\n\n ???? Invalid Password || email ????? :: \n\n";
            return 0;
        }
        else
        {
            cout<<"\n ?????? file is not found  ????????? :";
            return 0;
        }
    }
/////////////////this method will delete the record according to user input /////////////
    void Student::removeData()
    {
        string name;
        double rollno;
        char section;
         
         cout<<"\n\n\t-----------------Enter the Information ---------------\n\n";
         cout<<"Enter the name   : ";
         getline(cin,name);
         cout<<"Enter the rollno : ";
         cin>>rollno;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout<<"Enter the section: ";
         cin>>section;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        
        ifstream obj("student.txt",ios::in | ios::binary);
        ofstream temperaryObj("studenttemperary.txt",ios::out | ios::binary);

        obj.read((char*)this , sizeof(*this));
        while(!obj.eof())
        {
            if(!(this->name==name && this->rollno == rollno && this->section == section))
            {
                temperaryObj.write((char*)this,sizeof(*this));
            }
            obj.read((char*)this,sizeof(*this));
        }
        obj.close();
        temperaryObj.close();

        remove("student.txt");
        rename("studenttemperary.txt","student.txt");  
    }

// //////    faculty class    ///////////

class Faculty : public Person
{
    char subjectteacher[20];
    char education[20];
    double salary;

    public:
//////// defult constructer /////////
    Faculty()
    {
        strcpy(subjectteacher,"N/A");
        strcpy(education,"N/A");
        salary=0;
    }
///////////this function set data to varaible from user ////////
    void setData();
///////////// this function show data to user///////////
    void showData();
/////////// this method will write data into file from object /////////
    void writeData();
///////// this method will read data from file to obj ////////////////
    void readData();
///////// this method will read data from file to obj according user search for ////////////////
    int searchData();
////// this method get password and email from and confrim with file////////////
    int  emailPassword(string email , string password);
/////////////////this method will delete the record according to user input /////////////
    void removeData();
};
///////////this function set data to varaible from user ////////
    void Faculty::setData()
    {
        cout<<"\n\n\nEnter the name       : ";
        cin.getline(name, 20);
        cout<<"Enter the email      : ";
        cin.getline(email,20);
        cout<<"Enter the password   : ";
        cin.getline(password,20);
        cout<<"Enter the phone no   : ";
        cin.getline(phone,20);
        address.setData();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the education  : ";
        cin.getline(education,20);
        cout<<"Enter the salary     : ";
        cin>>salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter subjectname    : ";
        cin.getline(subjectteacher,20);
    }
///////////// this function show data to user///////////
    void Faculty::showData()
    {
        cout<<"\nName       : "<<name;
        cout<<"\nemail      : "<<email;
        cout<<"\nphone      : "<<phone;
        address.showData();
        cout<<"\nteach subj  : "<<subjectteacher;
        cout<<"\nEducation   : "<<education;
        cout<<"\nsalary      : "<<salary;
    }
/////////// this method will write data into file from object /////////
    void Faculty::writeData()
    {
        if(!(strcmp(name,"N/A")==0 && strcmp(email,"N/A")==0))
        {
            ofstream obj("faculty.txt",ios::out | ios::app | ios::binary);
            obj.write((char*)this , sizeof(*this));
            obj.close();  
        }   
        else
        {
            cout<<"\n Data is not inilized to store into a file ";
        }
    } 
///////// this method will read data from file to obj ////////////////
    void Faculty::readData()
    {
        ifstream obj("faculty.txt",ios::in | ios::binary);
        if(obj)
        {
            int i=1;
             obj.read((char*)this, sizeof(*this));
            while(!obj.eof())
            {
                cout<<"\n\n------Teacher No :: "<<i++<<"---------\n";
                showData();
                obj.read((char*)this, sizeof(*this));
            }
            obj.close();
        }
        else 
        {
            cout<<"\n ????? Eorr file is not found ?????? ";
        }
    } 
///////// this method will read data from file to obj according user search for ////////////////
    int Faculty::searchData()
    {
        string name;
        string subjectteacher;
        string education;

        cout<<"\n\n\t-----------Enter the Information ---------------\n\n";
         cout<<"Enter the name   : ";
         getline(cin,name);
         cout<<"Enter the teaching subject : ";
         getline(cin,subjectteacher);
         cout<<"Enter the Education: ";
         getline(cin,education);
        
        ifstream obj("faculty.txt",ios::in | ios::binary);
        if(obj)
        {
             obj.read((char*)this, sizeof(*this));
            while(!obj.eof())
            {
                if(this->name == name && this->subjectteacher == subjectteacher && this->education == education)
                {
                    showData();
                    obj.close();
                    return 0;
                }
                obj.read((char*)this, sizeof(*this));  
            }
            obj.close();
            cout<<"\n????Record no found :";
        }
        else 
        {
            cout<<"\nEorr file is not found ";
        }
        return 0;
    }
    ////// this method get password and email from and confrim with file////////////
    int  Faculty::emailPassword(string email , string password)
    {
        fstream obj("faculty.txt",ios::in | ios::binary);
        if(obj)
        {
            while(!obj.eof())
            {
                obj.read((char*)this,sizeof(*this));
                if(this->email == email  && this->password == password)
                {
                    obj.close();
                    cout<<"\n\n Successfully Login \n\n";
                    return 1;
                }
            }
            obj.close();
            cout<<"\n\n ?????Invalid Password || email :: ????\n\n";
            return 0;
        }
        else
        {
            cout<<"\nError faculty data is not found  :";
            return 0;
        }
    }
/////////////////this method will delete the record according to user input /////////////
    void Faculty::removeData()
    {
        string name;
        string subjectteacher;
        string education;

        cout<<"\n\n\t-----------Enter the Information ---------------\n\n";
         cout<<"Enter the name   : ";
         getline(cin,name);
         cout<<"Enter the teaching subject : ";
         getline(cin,subjectteacher);
         cout<<"Enter the Education: ";
         getline(cin,education);
        
        ifstream obj("faculty.txt",ios::in | ios::binary);
        ofstream temperaryObj("facultytemperary.txt",ios::out | ios::binary);

        obj.read((char*)this , sizeof(*this));
        while(!obj.eof())
        {
            if(!(this->name==name && this->subjectteacher == subjectteacher && this->education == education))
            {
                temperaryObj.write((char*)this,sizeof(*this));
            }
            obj.read((char*)this,sizeof(*this));
        }
        obj.close();
        temperaryObj.close();

        remove("faculty.txt");
        rename("facultytemperary.txt","faculty.txt");   
    }

/////////////// addministrative class   //////////////


class Addministrative : public Person
{
    public : 
////////// function which show data  //////////
    void setData();
/////////// function which show data ///////////
    void showData();
/////////// this method will write data into file from object /////////
    void writeData();
///////// this method will read data from file to obj ////////////////
    void readData();
///////// this method will read data from file to obj according user search for ////////////////
    int searchData();
////// this method get password and email from and confrim with file////////////
    int  emailPassword(string email , string password);
};

////////// function which show data  //////////
    void Addministrative::setData()
    {
        cout<<"\n\n\nEnter the name       : ";
        cin.getline(name, 20);
        cout<<"Enter the email      : ";
        cin.getline(email,20);
        cout<<"Enter the password   : ";
        cin.getline(password,20);
        cout<<"Enter the phone no   : ";
        cin.getline(phone,20);
        address.setData();
    }
/////////// function which show data ///////////
    void Addministrative::showData()
    {
        cout<<"\nName       : "<<name;
        cout<<"\nemail      : "<<email;
        cout<<"\nphone      : "<<phone;
        address.showData();
    }
/////////// this method will write data into file from object /////////
    void Addministrative::writeData()
    {
        if(!(strcmp(name,"N/A")==0 && strcmp(email,"N/A")==0))
        {
            ofstream obj("addministrative.txt",ios::out | ios::app | ios::binary);
            obj.write((char*)this , sizeof(*this));
            obj.close();  
        }   
        else
        {
            cout<<"\nPlease first set the data to enter to file";
            setData();
        }
    }
///////// this method will read data from file to obj ////////////////
    void Addministrative::readData()
    {
        ifstream obj("addministrative.txt",ios::in | ios::binary);
        if(obj)
        {
             obj.read((char*)this, sizeof(*this));
            while(!obj.eof())
            {
                showData();
                obj.read((char*)this, sizeof(*this));
            }
            obj.close();
        }
        else 
        {
            cout<<"\nEorr file is not found ";
        }
    }
///////// this method will read data from file to obj according user search for ////////////////
    int Addministrative::searchData()
    {
        string email;
        string password;

        cout<<"\n\n\t ----- Enter the Informatioin for searching --------\n\n";
        cout<<"Enter email    : ";
        getline(cin,email);
        cout<<"Enter password : ";
        getline(cin,password);
      
        ifstream obj("addministrative.txt",ios::in | ios::binary);
        if(obj)
        {
             obj.read((char*)this, sizeof(*this));
            while(!obj.eof())
            {
                if(this->email ==email &&  this->password == password)
                {
                    showData();
                    obj.close();
                    return 0;
                }

                obj.read((char*)this, sizeof(*this));
            }
            obj.close();
            cout<<"\nRecord not found : ";
        }
        else 
        {
            cout<<"\nEorr file is not found ";
            writeData();
        }
        return 1;
    }
////// this method get password and email from and confrim with file////////////
    int  Addministrative::emailPassword(string email , string password)
    {
        fstream obj("addministrative.txt",ios::in | ios::binary);
        if(obj)
        {
            
            while(!obj.eof())
            {
                obj.read((char*)this,sizeof(*this));
                if(this->email == email  && this->password == password)
                {
                    obj.close();
                    cout<<"\n\n\t Scucessfully login \n\n";
                    return 1;
                }
            }
            obj.close();
            cout<<"\n\n\t ??????? Invalid Password || email ????????\n\n";
            return 0;
        }
        else
        {
            cout<<"\n????Error Addministrative not exist:";
            cout<<"\n----Plz Enter the addministrative data to create a file :---";
            setData();
            writeData();
            
            return 0;
        }
    }

// //// mainmenu ///////

void mainmenu()
{
    while(1)
    {
        cout<<"\n1. login as addministrative";
        cout<<"\n2. login as faculty";
        cout<<"\n3. login as student";
        cout<<"\n4. exit";
        int check=0;
        cout<<"\nEnter the choice : ";
        cin>>check;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(1)
        {
            try{
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw check;
                }
                else
                    break;
            }
            catch(...)
            {
                cout<<"\nplz Enter integer type value ";
                cout<<"\nEnter the choice : ";
                cin>>check;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if(check==1)
        {
            addministrativemenu();
        }
        else if(check==2)
        {
            facultymenu();
        }
        else if(check==3)
        {
           studentmenu();
        }
        else if(check==4)
        {
            break;
        }
        else
        {
            cout<<"\ninvalid input";
        }
    }
}

//// ////////addministrative menu//////////
void addministrativemenu()
{
    Person* addministrative=new Addministrative;
    Person* student=new Student;
    Person* faculty=new Faculty;

    string email;
    string password; 

    cout<<"\n\t\t--------Login as addministrative---------\n\n";
    cout<<"Enter email    : ";
    getline(cin,email);
    cout<<"Enter password : ";
    getline(cin,password);

    if(addministrative->emailPassword(email,password)==1)
    {
         while(1)
        {
            cout<<"\n\n\n1.Display student data";
            cout<<"\n2.Display teacher data";
            cout<<"\n3.Add student";
            cout<<"\n4.Add teacher";
            cout<<"\n5.Remove student";
            cout<<"\n6.Remove teacher";
            cout<<"\n7.searchforteacher";
            cout<<"\n8.searchforStudent";
            cout<<"\n9.view addministrative data ";
            cout<<"\n10.search for addministrative ";
            cout<<"\n11.back to previous menu";
            int check;
            cout<<"\nEnter the choice :: ";
            cin>>check;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while(1)
            {
                try{
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw check;
                    }
                    else
                        break;
                }
                catch(...)
                {
                    cout<<"\nplz Enter integer type value ";
                    cout<<"\nEnter the choice : ";
                    cin>>check;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if(check==1)
            {
                student->readData();
            }
            else if(check==2)
            {
                faculty->readData();
            }
            else if(check==3)
            {
                student->setData();
                student->writeData();
            }
            else if(check==4)
            {
                faculty->setData();
                faculty->writeData();
            }
            else if(check==5)
            {
                student->removeData();
            }
            else if(check==6)
            {
                faculty->removeData();
            }
            else if(check==7)
            {
                faculty->searchData();
            }
            else if(check==8)
            {
                student->searchData();
            }
            else if(check==9)
            {
                addministrative->readData();
            }
            else if(check==10)
            {
                addministrative->searchData();
            } 
            else if(check==11)
            {
                mainmenu();
            }
            else
            {
                cout<<"\n invalid input";
            }
        }
    }
    else
    {
        cout<<"\n    Please try again  \n";
        mainmenu();
    }  

    delete[] student;
    delete[] faculty;
    delete[] addministrative;
}

//////// student menu //////

void studentmenu()
{
    Person* student=new Student;

    string email;
    string password; 

    cout<<"\n\t\t--------Login as Student---------\n\n";
    cout<<"Enter email    : ";
    getline(cin,email);
    cout<<"Enter password : ";
    getline(cin,password);
    if(student->emailPassword(email,password)==1)
    {
        while(1)
        {
            cout<<"\n\n\n1.view own data : ";
            cout<<"\n2.back to preious menu : ";
            int check;
            cout<<"\nEnter the choice : ";
            cin>>check;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while(1)
            {
                try{
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw check;
                    }
                    else
                        break;
                }
                catch(...)
                {
                    cout<<"\nplz Enter integer type value ";
                    cout<<"\nEnter the choice : ";
                    cin>>check;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if(check==1)
            {
                student->searchData();
            }
            else if(check==2)
            {
                mainmenu();
            }
            else
            {
                cout<<"\ninvalid input";
            }
        }
    }
    else
    {
        cout<<"\n\n Please try again : ";
    }
    delete[] student;
}

///////// facult menu ////////

void facultymenu()
{
    Person* faculty=new Faculty;
    Person* student=new Student;

    string email;
    string password; 

    cout<<"\n\t\t--------Login as Faculty---------\n\n";
    cout<<"Enter email    : ";
    getline(cin,email);
    cout<<"Enter password : ";
    getline(cin,password);
    if(faculty->emailPassword(email,password)==1)
    {
        while(1)
        {
            cout<<"\n\n\n1.view Student data";
            cout<<"\n2.Search Student";
            cout<<"\n3.view own data ";
            cout<<"\n4.back to the previous menu";

            int check;
            cout<<"\nEnter the choice : ";
            cin>>check;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
             while(1)
            {
                try{
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw check;
                    }
                    else
                        break;
                }
                catch(...)
                {
                    cout<<"\nplz Enter integer type value ";
                    cout<<"\nEnter the choice : ";
                    cin>>check;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if(check==1)
            {
                student->readData();
            }
            else if(check==2)
            {
                student->searchData();
            }
            else if(check==3)
            {
                faculty->searchData();
            }
            else if(check==4)
            {
                mainmenu();
            }
            else
            {
                cout<<"\nInvalid input";
            }
        }
    }

    delete[] faculty;
    delete[] student;
}

////////// main function  //////////

int main()
{
   cout<<"\n\n\t\t ---------- WELLCOME TO STUDENTMANGEMENT SYSTEM -------------\n\n\n ";
   mainmenu(); // calling to mainmenu function
    cout<<endl<<endl;
    return 1;   
}
