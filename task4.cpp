/*Write a program in C++ where there is a class named Favourite_Songs, it contains
the size of the array (string array) and a pointer to dynamic array of strings
containing the song names. The class should have a methods for adding a new song
addSong(string song). This method will create another array of size+1, copy the
values from the previous array into that array along with the new song), deleteing a
song (now think of the logic to delete a song and update the array), updating the
song, printing the songs. Make use of the new and delete keyword where required.
The program must have a copy constructor that creates a deep copy of the object
passed. Copy constructor should be called when the user selects Create backup of
the songs.The class should also have the destructor. Release all the memory where
needed using the delete keyword.*/

#include <iostream>
using namespace std;
class Favorite_Songs//creating a class called Favorite_Songs
{
	private://these are the class private member
		int size;
		string *arr;//creating private member declaring dynamic array
	public:
		Favorite_Songs(int size)//this is a constructor with one argument
		{
			this -> size=size;
			arr=new string[size];
		}
        void displayString()//this function show all the string elements
        {
            for(int i=0;i<size;i++)
                cout<<arr[i]<<endl;
        }
        void deletesong()//this function deletes the song
        {
           int index;
		    cout<<"\nEnter the index number";
			cin>>index;
			if(index>=size || index<0)
			{
				cout<<"\ninvalid index number ";
			}
			else
			{
				string* newarry = new string[size-1];
				for(int i=0;i<size;i++)
				{
					int j=0;
					if(i==index)
						continue;
					else
					{
						newarry[j]=arr[i];
						j++;
					}
				}
				delete[] arr;
				arr = newarry;
			}
        }
		void addSong(string obj)//this function adds the song the string array
		{
            size++;
			string str2[size];
			for(int i=0;i<size-1;i++)
            str2[i]=arr[i];
			str2[size-1]=obj;
			arr=new string[size];
			for(int i=0;i<size;i++)
				arr[i]=str2[i];
		}
		void updateSong(int i)//this function update the string element according to the user wish
		{
			cout<<"enter the song to be updated: ";
			cin>>arr[i];
		}
        Favorite_Songs(Favorite_Songs &obj)//this is a copy constructor which copy one obj to the other one
        {
            size=obj.size;
            arr=new string[size];
            for(int i=0;i<size;i++)//this loop copy the array of one obj to another;
                arr[i]=obj.arr[i];
        }
		~Favorite_Songs()//this is a destructor which destroy the dynamic array
		{
			delete []arr;
		}
};
int main ()
{
	Favorite_Songs obj(1);//declaring obj
	string str;
	cout<<"enter the new song name: ";
	cin>>str;
	obj.addSong(str);
	obj.displayString();
	while(1)//this loop shows the menu for the user
	{
		cout<<endl<<"1. Add a Song";
		cout<<endl<<"2. Delete a Song";
		cout<<endl<<"3. Update a Song";
		cout<<endl<<"4. Print all songs";
		cout<<endl<<"5. Create Backup of songs";
		cout<<endl<<"6. Exit";
		int opt;
		cout<<endl<<"enter the option: ";
		cin>>opt;
		if(opt==6)
			break;
		else if(opt==1)
		{
			cout<<"enter the new song name: ";
			cin>>str;
			obj.addSong(str);//calling addsong function 
			obj.displayString();//calling displaystring function
		}
		else if(opt==2)
		{
			obj.deletesong();//calling deletesong function
			obj.displayString();//calling displaysting function
		}
		else if(opt==3)
		{
			int i;
			cout<<"enter the song number to update: ";
			cin>>i;
			obj.updateSong(i);//calling upadatesong function 
			obj.displayString();//calling displaysting function
		}
		else if(opt==4)
			obj.displayString();//calling displaystring function
		else if(opt==5)
		{
			cout<<"Backup Created";
			Favorite_Songs obj2(obj);//calling copy constructior for backup
			obj2.displayString();//calling displaystring function
		}
		else
			cout<<"Invalid";//incase if the user chose option not given in the menu
	}
}
