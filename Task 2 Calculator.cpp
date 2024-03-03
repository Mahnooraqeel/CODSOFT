#include <iostream>
using namespace std;
void operation(int array[] , int , int);
int main()
{ 
       int operands , choice =0;
       char ch ='y';
       do
   {
    cout<<"This is a Basic Arithematic Calculator."<<endl;
    cout<<endl;
    cout<<"Enter the number of operands for which you want to perfoam arithematic calculation"<<endl;
    cin>>operands;
    if(operands <= 1)
    {
    	cout<<"Enter atleast 2 operands to perfoam arithematic operation"<<endl;
    	cin>>operands;
	}
    cout<<endl;
    int array[operands]={0};
    for(int i =0 ; i< operands  ; i++)
    {
        cout<<"Enter the "<< i + 1 <<" operand : ";
        cin>>array[i];
    }
    cout<<endl;
   cout<<"Enter your choice for the following operands (1-4) : "<<endl;
    cout<<"1. Adittion (+)"<<endl;
     cout<<"2. Subtraction (-)"<<endl;
      cout<<"3. Multiplication (*)"<<endl; 
       cout<<"4. Division (/)"<<endl;
        cout<<endl;
       
    cin>>choice;
    if (choice < 1 || choice > 4 )
    {
		cout<<"Enter choice Between 1 and 4"<<endl;
		cin>>choice;
	}
	
    cout<<endl;
    operation(array , operands , choice); 
    cout<<endl;
    cout<<"Do You want to use calculator again (y/n)."<<endl;
    cin>>ch;
   } while (ch=='y');
   cout<<endl;
   
   
    
}
void operation(int array[], int size, int choice) {
    int result = 0;
    if (choice == 1) 
    {
        for (int i = 0; i < size; i++) 
        {
            result += array[i];
        }
        
        cout << "The result for your Addition (+) operation is " << result << endl;
        
    } 
    else if (choice == 2)
    {
        result = array[0];
        for (int i = 1; i < size; i++)
        {
            result -= array[i];
        }
        
        cout << "The result for your Subtraction (-) operation is " << result << endl;
    } 
    else if (choice == 3) 
    {
        result = 1;
        for (int i = 0; i < size; i++) 
        {
            result *= array[i];
        }
        
        cout << "The result for your Multiplication (*) operation is " << result << endl;
        
    } 
    else if (choice == 4) 
    {
        float result = array[0];
        for (int i = 1; i < size; i++)
        {
            result /= array[i];
        }
        
        cout << "The result for your Division (/) operation is " << result << endl;
        
    }
    
    else 
    {
        cout << "Invalid choice!" << endl;
    }
}
