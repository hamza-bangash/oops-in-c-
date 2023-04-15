/* Suppose you are designing a program to model a grocery store's inventory.
Each item has a unique ID, a name, a price, and a quantity.The program should first ask the user to enter the total no of items to store,
then create an array of Items of that size in main. The main should be a
menu-driven program with the following choices:
1). Display Items
2). Update item details
3). Search for items by ID
The above methods should be declared outside the class.
There must be functions for all the operations. Display_items() takes the
array of objects and should display all the items with their details(ID, Name,
Price, Quantity).
2). UpdateItem() should take the item as an argument and further ask
whether to update the price or the quantity. And do accordingly in the
function. Think whether it should be pass by value or reference.
3). Search for items by ID should take array of items, size, and the ID_NO.
If the item is found, display its details, else display “item not found”. */


#include <iostream>
using namespace std;
//creating a class called Grocery
class Grocery
{
    private:
        int itemId,itemPrice,itemQuantity;
        string itemName;
    public:
        Grocery()//creating default constructor
        {

        }
        Grocery(int id,int price,int quantity,string name)//creating a constructor which takes 3 parameter
        {
            itemId=id;
            itemPrice=price;
            itemQuantity=quantity;
            itemName=name;
        }
        void setItemId()//creating a setter for itemId
        {
            cout<<"enter item id: ";
            cin>>itemId;
        }
        int getItemId()//creatig a getter for itemId
        {
            return itemId;
        }
        void setItemName()//creating setter for itemName
        {
            cout<<"enter the item name: ";
            cin>>itemName;
        }
        string getItemName()//craeting a getter for itemName
        {
            return itemName;
        }
        void setItemPrice()//creating a setter for itemprice
        {
            cout<<"enter the item price: ";
            cin>>itemPrice;
        }
        int getItemPrice()//creating a getter for itemPrice
        {
            return itemPrice;
        }
        void setItemQuantity()//creating a setter for itemQuantity
        {
            cout<<"enter the item quantity: ";
            cin>>itemQuantity;
        }
        int getItemQuantity()//creating a getter for itemQuantity
        {
        	return itemQuantity;
		}
        ~Grocery()//creating a destructor which gives a message object destroyed
        {
            cout<<"\nobject destroyed";
        }
};
//this function accept object array and int parameter and display the data stored in object array
void display_item(Grocery obj[],int size)
{
	int i=0;
	while(i<size)
	{
    	cout<<"\nitem id: "<<obj[i].getItemId();
    	cout<<"\nitem name: "<<obj[i].getItemName();
    	cout<<"\nitme price: "<<obj[i].getItemPrice();
    	cout<<"\nitem quantity: "<<obj[i].getItemQuantity();
    	i++;
    }
}
//this fuction accept object as refernece and change the data stored in it
void updateItem(Grocery &obj)
{
	int option;
	cout<<"\n1:Update Price   2:Upade Quantity";
	cout<<"\nenter option: ";
	cin>>option;
	if(option==1)
		obj.setItemPrice();
	else
		obj.setItemQuantity();
}
//this function accept three parameters and search for item on the given idno
void searchForItem(Grocery obj[],int size,int idNo)
{
	int i=0,temp=1;
	while(i<size)
	{
		if(obj[i].getItemId()==idNo)
			{
				cout<<endl<<"ITEM ID: "<<obj[i].getItemId();
    			cout<<endl<<"ITEM NAME: "<<obj[i].getItemName();
    			cout<<endl<<"ITEM PRICE: "<<obj[i].getItemPrice();
    			cout<<endl<<"ITEM QUANTITY: "<<obj[i].getItemQuantity();
    			temp=0;
			}
			i++;
	}
	if(temp==1)
		cout<<"\nitem notfound";
}
int main ()
{
    int totalItem,option;
    cout<<"enter number of items: ";
    cin>>totalItem;
    Grocery obj[totalItem];//creating object array for Grocery class
    for(int i=0;i<totalItem;i++)
    {
        obj[i].setItemId();
        obj[i].setItemName();
        obj[i].setItemPrice();
        obj[i].setItemQuantity();
    }
    cout<<endl<<"1:Display ITEM";
	cout<<endl<<"2:Update Item Details";
	cout<<endl<<"3:Search for items by ID";
	cout<<endl<<"enter the option: ";
    cin>>option;
    if(option==1)
       		display_item(obj,totalItem);//calling display_item function and passing two parameters
    else if(option==2)
    {
    	int itemoption;
    	cout<<"enter item no: ";
    	cin>>itemoption;
    	updateItem(obj[itemoption+1]);//calling updateItem fuction and passing object as refrecnec so change is actuall
		//becaue arrays starts from 0 for i add 1
	}
	else if(option==3)
	{
		int idno;
		cout<<"enter the id: ";
		cin>>idno;
		searchForItem(obj,totalItem,idno);//calling searchForItem fuction and passing three parameters
	}
	cout<<"\n----------------------------";
}
