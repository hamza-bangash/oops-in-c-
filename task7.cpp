/*You have been asked to design a program that simulates the behavior of a
Skimmer, which is a type of boat that is capable of both swimming and flying.
To accomplish this, you will create a Skimmer class that is derived from two
base classes, Boat and Plane using protected inheritence.

The Boat class will contain data member called boatLength, which represents
the length of the boat, and a member function called swim(), which prints the
message “I am swimming”
The Plane class will contain a data member called maxAltitude, which
represents the maximum altitude the plane can reach, and a member function
called fly(), which prints the message “I am flying”.
The Skimmer class will contain a private data member called numPassengers,
which represents the number of passengers the skimmer can carry, and a
public member function called swimAndFly(), which will class the swim()
and fly() method of the super classes.
In the main function, create an object of the Skimmer and initialize through
constructor.
Display the properties of the Skimmer object using the display() member
function. Finally, call the swimAndFly() function to simulate the behavior of
the Skimmer.
Note: None of your class should have getter and setter methods, only initialize
the object through a constructor.*/

#include <iostream>
using namespace std;

class Boat
{
	protected:
		int boatLength;
	public:
		void swim()
		{
			cout<<endl<<"I AM SWIMMING";
		}
};
class Plane
{
	protected:
		int maxAltitude;
	public:
		void fly()
		{
			cout<<endl<<"I AM FLYING";
		}
};
class Skimmer:protected Boat, protected Plane
{
		int numPassengers;
	public:
		Skimmer(int length,int altitude,int passengers)
		{
			boatLength=length;
			maxAltitude=altitude;
			numPassengers=passengers;
		}
		void SwimAndFly()
		{
			swim();
			fly();
		}
		void display()
		{
			cout<<endl<<"Skimmer Name: Swim and Fly";
			cout<<"  Length: "<<boatLength<<"ft,";
			cout<<" Max Altitude: "<<maxAltitude<<"ft,";
			cout<<" Passengers: "<<numPassengers;
		}
};
int main ()
{
	Skimmer skimmer(40,13000,2);
	skimmer.display();
	skimmer.SwimAndFly();

	cout<<endl<<endl;

	return 0;
}