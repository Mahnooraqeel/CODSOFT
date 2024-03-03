#include <iostream>
#include <cstdlib> // For rand() and exit()
#include <time.h>  //To use srand() time function
using namespace std;

int main()
{
    int number, guess, count = 0;
    char c = 'n';
    
    // Outer loop to allow replaying the game
    do
    {   
        cout << "You Are Playing Number Guess Game" << endl;
        cout  <<  "You have Five turns to guess the Number right" << endl;
        
        //Generate a different number everytime
        srand(time(0)); 
        
        // Generate a random number
        guess = rand() % 100;

        
        // Inner loop for guessing and providing feedback
        do
        {   cout << "Enter The Number in the range of 0 to 100." << endl;
            cin >> number;
            if (number == guess)
            {
                cout << "Congrats !! You Guessed Right" << endl;
                cout << endl;
                break;
            }
            else if (number < guess)
            {
                cout << "You guessed too low" << endl; 
                cout << endl;
            }
            else if (number > guess)
            {
                cout << "You guessed too high" << endl;
                cout << endl;
            }
            
            count++;
           
        } while (count != 5);
        
        // If player couldn't guess within 5 attempts
        if (count == 5)
        {
            cout << "Alas ! You lost" << endl;
            cout << endl;
        }
        
        cout<<endl;
        cout << "Do you want to play again? (y/n)" << endl;
        cout << endl;
        cin >> c;
        
    } while (c == 'y'); // Loop until player doesn't want to play again
    
    if (c == 'n')
    {
        exit(0); 
    }
    
    return 0;
}

