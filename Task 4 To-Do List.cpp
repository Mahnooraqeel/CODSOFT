#include <iostream>
#include <string>
using namespace std;

void addtask(string array[], int);
void display(string array[], string status[], int);
void flag(string array[], string status[], int);
void del(string array[], string status[], int&);

int main() 
{
    int choice;
    int noftask = 1;
    char ch = 'n';
    string array[100]={"null"};
    string status[100];
    for (int i = 0; i < 100; i++) 
    {
        status[i] = {"Pending"};
    }

    do              												//menu
    {   cout<<" This Is Your Daily Remainder To-Do List "<<endl;
        cout<<" You Can Enter A Maximum Of 100 Tasks"<<endl;
        cout << " Select One Of The Given Options:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Display tasks" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Delete a task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;

        cin.ignore();
        if (choice == 1) 
        {
            addtask(array, noftask);
            noftask++;
            cout<<endl;
        }
        else if (choice == 2)
        {
            display(array, status, noftask);
            cout<<endl;
        }
        else if (choice == 3)
        {
            flag(array, status, noftask);
            cout<<endl;
        }
        else if (choice == 4) 
        {
            del(array, status, noftask);
            cout<<endl;
        }
        else if (choice == 5)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        }

    } while (choice != 5);

    return 0;
}

void addtask(string array[], int noftask)                          //Function to add task.
{
    
    cout << "Enter the task: ";
    cout<<endl;
    getline(cin, array[noftask]);
}

void display(string array[], string status[], int noftask)        //Function to displya task list.
{
    cout << "Tasks:" << endl;
    for (int i = 1; i < noftask; i++) 
    {
    	if (array[i]=="null")
    	{
    		cout<<"Your Task List Is currently Empty";
		}
		
        cout << i << ". " << array[i] << " (" << status[i] << ")" << endl;
    }
}

void flag(string array[], string status[], int noftask)          //Function to mark task as completed.
{
    display(array, status, noftask);
    int task;
    cout << "Enter the task number you want to mark as completed: ";
    cin >> task;
    status[task] = {"Completed"};
    cout << "Task marked as completed." << endl;
    display(array, status, noftask);
}

void del(string array[], string status[], int& noftask)
{
    int task;
    cout << "Enter the task number you wish to delete: ";       //Function to delete a task.
    cin >> task;

    if (task >= 1 && task < noftask)
    {
        for (int i = task; i < noftask; i++) 
        {
            array[i] = array[i + 1];
            status[i] = status[i + 1];
        }
        noftask--; 

    } 
    else 
    {
        cout << "Invalid task number." << endl;
    }
    display(array, status, noftask);
}

