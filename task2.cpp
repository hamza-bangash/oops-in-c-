/*Suppose you are designing a program to manage a company's employee
database. Each employee has a unique ID, a name, a job title, and no of
hours worked per week. In main ask the user to enter the no of employees
and then create an array of that no of employees and initialize their values.
Your class must use getter and setter methods where required. The class
must have a method named cacl_Salary()
Now calculate the salary of each employee based on the following details:
If the no of hours worked of that employee is less than or equal to 40, the
salary would be hours worked multiplied by the hourly rate. If the no of
hours worked is greater than 40, then he will get an overtime. The pay for
the overtime hours is double than what he gets for the base hours. For that
calculate the extra hours worked and calculate the pay only for the overtime
and add it to the base pay. Do this for all the employees and display the
name and salary of all the employees.*/

#include <iostream>
using namespace std;

//creating a class for employee

class Employee
{
	
	private:
		int empId,noOfWorkedHours,salary;
		string empName,jobTitle;
		
	public:
		void setEmpId()//creating empId setter
		{
			cout<<"enter id: ";
			cin>>empId;
		}
		int getEmpId()//creating getter for empId
		{
			return empId;
		}
		void setEmpName()//creating setter for empName
		{
			cout<<"enter name: ";
			cin>>empName;
		}
		string getEmpName()//creating getter for EmpName
		{
			return empName;
		}
		void setNoOfWorkedHours()//creating setter for workedhours
		{
			cout<<"enter worked hour: ";
			cin>>noOfWorkedHours;
		}
		int getnoOfWorkedHours()//creating getter for worked hours
		{
			return noOfWorkedHours;
		}
		void setJobTitle()//creating setter for job title
		{
			cout<<"enter jobtitle: ";
			cin>>jobTitle;
		}
		string getJobTitle()//creating getter for job title
		{
			return jobTitle;
		}
		void calc_salary(int hourRate)//this function calculate salary and takes one parameter
		{
			if(noOfWorkedHours<=40)
				salary=noOfWorkedHours*hourRate;
			else if(noOfWorkedHours>40)
			{
				int extraTime;
				extraTime=noOfWorkedHours-40;
				noOfWorkedHours-=extraTime;
				salary=noOfWorkedHours*hourRate+extraTime*(2*hourRate);
			}
		}
		int getSalary()//creating getter for salary
		{
			return salary;
		}
};

int main ()
{
	int totalEmployees,hourRate;//declaring varaibles
	cout<<"enter the number of employees: ";
	cin>>totalEmployees;
	cout<<"enter the hour rate: ";
	cin>>hourRate;
	Employee empobj[totalEmployees];//For employee class creating array of objects
	for(int i=0;i<totalEmployees;i++)
	{
		empobj[i].setEmpId();//calling setter
		empobj[i].setEmpName();//calling setter
		empobj[i].setJobTitle();//calling setter
		empobj[i].setNoOfWorkedHours();//calling setter
		empobj[i].calc_salary(hourRate);//calling setter
	}
	cout<<endl<<"------------------------------------------------";
	for(int i=0;i<totalEmployees;i++)
	{
		cout<<endl<<"name: "<<empobj[i].getEmpName();//calling getter
		cout<<endl<<"salary: "<<empobj[i].getSalary()<<endl;//calling getter
	}
	cout<<endl<<"------------------------------------------------";
}
