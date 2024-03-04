#include <iostream>
using namespace std;

void display(void);
char array[4][4] = {0};

void player();
bool error(int, int);
bool check1(char array[4][4]);
bool check2(char array[4][4]);
bool checkDraw(char array[4][4]);
bool playAgain();

int main() 
{
    cout << "You Are Playing Tic Tac Toe " << endl;
    cout << "Indices of the Board are : " << endl;          //Board Display
    
    for (int i = 1; i < 4; i++) 
    {
        for (int j = 1; j < 4; j++) 
        {
            cout  << i << "," << j << "\t" ;
        }
        cout<<endl;
    }

    do {
        player();
    } while (playAgain());

    cout << "Thank you for playing Tic Tac Toe!" << endl;

    return 0;
}

void display(void)                                          //Function to display board after players turn
{
    for (int i = 1; i < 4; i++) 
    {
        for (int j = 1; j < 4; j++) 
        {
            cout << array[i][j] << "\t"; 
        }
        cout << endl;
    }
}

void player() 
{
    int row = 1, col = 1;

    for (int count = 0; count < 5; count++) 
    {
        do 
        {
            cout << "Enter the row and column numbers for player 1 : ";
            cin >> row >> col;
        } 
        while (!error(row, col));                             //error check

        array[row][col] = 'X';
        display();

        if(check1(array))                                    //Winner cases check function for player 1.
        {
            cout << "Player 1 is the winner." << endl;
            return;
        }
        else
        {
            cout<<endl;
            cout<<"Game Ongoing"<<endl;
            cout<<endl;
        }
        if (checkDraw(array)) 
        {
            cout << "It's a draw!" << endl;
            return;
        }

        do 
        {
            cout << "Enter the row and column numbers for player 2 : ";
            cin >> row >> col;
        } 
        while (!error(row, col));                             //error check

        array[row][col] = 'O';
        display();

        if(check2(array))                                    //Winner cases check function for player 2.
        {
            cout << "Player 2 is the winner." << endl;
            return;
        }
        else
        {
            cout<<endl;
            cout<<"Game Ongoing"<<endl;
            cout<<endl;
        }
        if (checkDraw(array)) 
        {
            cout << "It's a draw!" << endl;
            return;
        }
    }
}

bool error(int row, int col)                              //Function to check error in user entered value.
{
    if (!(row < 4 && col < 4))
    {
        cout << "Enter numbers between 1 and 3." << endl;
        return false;
    } 
    else if (array[row][col] != 0) 
    {
        cout << "Cell already occupied. Enter a different position." << endl;
        return false;
    } 
    else 
    {
        return true;
    }
}

bool check1(char array[][4])                               //Function to check winning cases for player 1.
{
    int count = 0;

    for (int i = 1, j = 1; i < 4 && j < 4;)               // Winner check for vertical motion. 
    {
        if (array[i][j] == 'X') 
        {
            count++;

            if (count == 3) 
            {
                return true;
            }

            i++;                                          //move downwards.
        } 
        else 
        {
            count = 0;
            j++;                                          //move forwards.
            i = 1;
        }
    }
    
    for(int i=0 ; i< 4 ; i++)                             //Winner check horizontally.
    {   
        int count=0;
        for(int j=0; j< 4 ; j++)
        {
            if (array[i][j]=='X')                            //check entire row at once.move forard.
            {
                count++;
            }
            else
            {
                count=0;
            }
        }
        if (count==3)
        {
            return true;
        }
    }

    for(int i =1;  i< 4 ; i++)                              //Winner check from top right to bottom left diagnol winner.
    {   
        int j =i;
        if(array[i][j]=='X')
        {
            count ++;
            if(count==3)
            {
                return true;
            }
        }
        else
        {
            count=0;
        }
    }

    for(int i=1 , j =3 ; i<4 ; i++ , j--)                    //Winner check from Top left to Bottom right diagnolly.
    {
        if(array[i][j]=='X')
        {
            count++;
            if(count==3)
            {
                return true;
            }
        }
        else
        {
            count=0;
        }
    }
    return false;
}

bool check2(char array[][4])                                   //Function to check player 2 winning cases. 
{
    int count = 0;

    for (int i = 1, j = 1; i < 4 && j < 4;)                   // Winner check for vertical motion.
    {
        if (array[i][j] == 'O') 
        {
            count++;

            if (count == 3) {
                return true;
            }

            i++;
        } 
        else 
        {
            count = 0;
            j++;
            i = 1;
        }
    }
    
    
    for(int i=0 ; i< 4 ; i++)                                   //Winner check horizontally.         
    {   
        int count=0;
        for(int j=0; j< 4 ; j++)
        {
            if (array[i][j]=='O')
            {
                count++;
            }
            else
            {
                count=0;
            }
        }
        if (count==3)
        {
            return true;
        }
    }
    
    for(int i =1;  i< 4 ; i++)                                    //Winner check from top right to bottom left diagnol winner.
    {   
        int j =i;
        if(array[i][j]=='O')
        {
            count ++;
            if(count==3)
            {
                return true;
            }
        }
        else
        {
            count=0;
        }
    }
    
    for(int i=1 , j =3 ; i<4 ; i++ , j--)                          //Winner check from Top left to Bottom right diagnolly.
    {
        if(array[i][j]=='O')
        {
            count++;
            if(count==3)
            {
                return true;
            }
        }
        else
        {
            count=0;
        }
    }
    return false;
}
    
    
bool checkDraw(char array[][4])                                   //Function to Check Draw case.
{

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (array[i][j] == 0) {

                return false;
            }
        }
    }

    return true; 
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

