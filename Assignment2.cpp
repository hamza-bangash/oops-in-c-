#include<iostream>
#include <limits>
using namespace std;

/*Design a class named Room. Each object of the classroom can hold the following information:
room number, type of the room (Basic, Standard, or Luxury), check-in time, check-out time,
rent, and status of the room (free, occupied). Define functions to set and get information of a
Room.
b. Design a class named Hotel. Each object of the class Hotel can hold the following information:
name of the hotel, location of the hotel, name of the owner of the hotel, and rooms in the
hotel (objects of the classroom). Define functions to set and get information about the hotel
mentioned above and define the following functions:
▪ checkIn(int roomNo): A customer is assigned a room.
▪ checkOut(int bookingID): A customer leaves a room, and the room is now free to be
assigned to any other customer.
▪ getAvailRoom(): A summary of which rooms are available i.e. room number, type of
room, etc.
▪ showRoomSummary(int roomNo): Shows if the specific room is available or occupied,
if occupied which customer is it assigned to and what is the check-in time.

c. In main() create an object of the class hotel and assign different rooms to different custom-
ers.

Note: You can add functions more functions to any of these classes if needed.*/

class Room
{
    double roomnumber;
    string roomtype;
    string checkInTime;
    string checkOutTime;
    double roomRent;
    string roomStatus;
    double bookingId;
    static int autono;


    public:
    
    Room()//defult constructer
    {
        bookingId=0;
        checkInTime ="11 AM";
        checkOutTime ="1 PM";
        autono++;
        roomnumber = autono;
        roomStatus = "free";
    }

    void setData()
    {
        cout<<"Enter the room type as ((Basic, Standard, or Luxury)) : ";
        getline(cin,roomtype);
        cout<<"Enter the Check In time : ";
        getline(cin,checkInTime);
        cout<<"Enter the Check out time : ";
        getline(cin,checkOutTime);
        cout<<"Enter the room rent : ";
        cin>>roomRent; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// get raid of buffer memory
        //cout<<"Enter the Room status as((free, occupied)) : ";
        //getline(cin,roomStatus);
    }
    
    void getData()
    {
        cout<<"\nRoom number   : "<<roomnumber;
        cout<<"\nRoom type     : "<<roomtype;
        cout<<"\nCheck In time : "<<checkInTime;
        cout<<"\nCheck Out time: "<<checkOutTime;
        cout<<"\nRoom rent     : "<<roomRent;
        cout<<"\nRoom status   : "<<roomStatus;
        cout<<endl;
    }
    int getRoomNO()
    {
        return roomnumber;
    }
    void setRoomStatus(string roomStatus)
    {
        this->roomStatus = roomStatus;
    }
    string getRoomStatus()
    {
        return roomStatus;
    }
    void setBookingId()
    {
        cout<<"\nAssigin bookind Id to costomer : ";
        cin>>bookingId;
    }
    double getBookingId()
    {
        return bookingId;
    }
    void setCheckIn()
    {
        cout<<"\nEnter the checkin time : ";
        cin>>checkInTime;
    }
    string getCheckIn()
    {
        return checkInTime;
    }

    void setCheckOut()
    {
        cout<<"\nEnter the check out time :";
        cin>>checkOutTime;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string getCheckOut()
    {
        return checkOutTime;
    }

};
int Room::autono=0;

class Hotel
{
    string nameOfHotel;
    string nameOfHotelOwner;
    string location;
    int size; // store the number rooms
    Room* room;  // pointer of object of room class

    public:
    Hotel(int size=1) //defult  paramatize constructer
    {
        this->size = size;
        room = new Room[size];
    }
   
    void setData()
    {
        cout<<"\nEnter the name of Hotel : ";
        getline(cin,nameOfHotel);
        cout<<"Enter the name of Owner : ";
        getline(cin,nameOfHotelOwner);
        cout<<"Enter the Location : ";
        getline(cin,location);
        for(int i=0;i<size;i++)
        {
            cout<<"\n------Enter the Information of room : -----\n";
            room[i].setData();
        }
    }
    void getData()
    {
        cout<<"\nHotel Name : "<<nameOfHotel;
        cout<<"\nHotel Owner : "<<nameOfHotelOwner;
        for(int i=0;i<size;i++)
        {
            cout<<"\nInformation of Room :--------";
            room[i].getData();
        }
    }

    void checkIn(int roomNo) 
    {
        for(int i=0;i<size;i++)
        {
            if(roomNo==room[i].getRoomNO())
            {
                if(room[i].getRoomStatus()=="free" || room[i].getRoomStatus()=="Free")
                {
                    room[i].setBookingId();
                    room[i].setRoomStatus("occupied");
                    room[i].setCheckIn();
                    break;
                }
                else
                {
                    cout<<"\nRoom already occupied ";
                    break;
                }
            }
        }
    }

    int checkOut(int bookinID)
    {
        for(int i=0;i<size;i++)
        {
            if(bookinID == room[i].getBookingId())
            {
                room[i].setRoomStatus("free");
                cout<<"\nRoom no :" <<i+1<<" is free now : ";
                return 1;
            }
        }
        cout<<"\nIncorrect booking Id : ";
        return 0;
    }

    void showRoomSummary(int roomNo)
    {
        for(int i=0;i<size;i++)
        {
            if(roomNo == room[i].getRoomNO())
            {
                cout<<"\nSummary of room : "<<i+1;
                if(room[i].getRoomStatus() == "occupied" || room[i].getRoomStatus() == "Occupied")
                {
                    cout<<"\nRoom already occupied : ";
                    cout<<"\nRoom occupied by has Id no: ";
                    cout<<room[i].getBookingId();
                    cout<<"\nCheck in Time is : ";
                    cout<<room[i].getCheckIn();
                }
                else
                {
                    room[i].getData();
                }
                cout<<endl;
                break;
            }
        }
    }
    void getAvailRoom()
    {
        cout<<"\n---Availble Rooms are following : --- \n";
        for(int i=0;i<size;i++)
        {
            if(room[i].getRoomStatus() == "free" || room[i].getRoomStatus()=="Free")
            {
                room[i].getData();
            }
        }
    }
    ~Hotel()
    {
        delete[] room;
    }
    
};

int main()
{
    cout<<"\nEnter the numbers of rooms : ";
    int noOfRooms;
    cin>>noOfRooms;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');// delete  buffer memory

    Hotel hotel(noOfRooms);
    hotel.setData();
    hotel.getData();
while(1)
{
    cout<<"\n\t Menu ";
    cout<<"\n1.Room summary : ";
    cout<<"\n2.Check availble  rooms : ";
    cout<<"\n3.Booking room : ";
    cout<<"\n4.Leaving room : ";
    cout<<"\n5.Exit ";
    int check;
    cout<<"\n\nEnter the choice : ";
    cin>>check;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(check==1){
    int summaryOfRoom;
    cout<<"\n Enter the room number you want summar : ";
    cin>>summaryOfRoom;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    hotel.showRoomSummary(summaryOfRoom);
    }
    else if(check==2)
    hotel.getAvailRoom();
    else if(check==3){
        cout<<"\nEnter the room no : ";
        int roomNo;
        cin>>roomNo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        hotel.checkIn(roomNo);
    }
    else if(check==4){
    cout<<"\n Enter the booking id : ";
    int bookingId;
    cin>>bookingId;
    hotel.checkOut(bookingId);
    }
    else if(check==5)
    {
        break;
    }
    else
    cout<<"\nInvalid input ";
}
    cout<<endl<<endl;
    return 1;
}