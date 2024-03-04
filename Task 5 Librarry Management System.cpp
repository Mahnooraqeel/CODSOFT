#include <iostream>
using namespace std;

struct library
{
    string title;
    string author;
    string ISBN;
    string status;
}; 

void search(library array[], int size);
void checkout(library (&array)[10], int size);
void bookreturn(library (&array)[10], int size);
void fine(library array[], int size);
bool datecheck(int, int);

static int date = 0, month = 0;

int main()
{
	//I have used array of structure as my database.Took Random data from internet.
    library array[10] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "available"},
        {"To Kill a Mockingbird", "Harper Lee", "9780061120084", "available"},
        {"1984", "George Orwell", "9780451524935", "available"},
        {"The Catcher in the Rye", "J.D. Salinger", "9780316769488", "available"},
        {"Lord of the Flies", "William Golding", "9780399501487", "available"},
        {"Animal Farm", "George Orwell", "9780451526342", "available"},
        {"Brave New World", "Aldous Huxley", "9780060850524", "available"},
        {"The Hobbit", "J.R.R. Tolkien", "9780345339683", "available"},
        {"The Hunger Games", "Suzanne Collins", "9780439023481", "available"},
        {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "9780590353427", "available"}}; 

    int choice = 0;
    cout << "Welcome to the Library Management System" << endl;
    cout << endl<<endl;

    do
    {
        cout << "Main Menu:" << endl;
        cout << "1. Display all Books" << endl;
        cout << "2. Search a Book" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Displaying all books:" << endl;
            for (int i = 0; i < 10; ++i)
            {
                cout << "Book " << i + 1 << ":" << endl;
                cout << "Title: " << array[i].title << endl;
                cout << "Author: " << array[i].author << endl;
                cout << "ISBN: " << array[i].ISBN << endl;
                cout << "Status: " << array[i].status << endl;
                cout << endl;
            }
            break;
        case 2:
            search(array, 10);
            break;
        case 3:
            checkout(array, 10);
            break;
        case 4:
            bookreturn(array, 10);
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }
    } while (choice != 5);

}

void search(library array[], int size)
{
    string search = "null";
    cout << "Enter the ISBN of the book to search: ";
    cin.ignore();
    getline(cin , search);

    for (int i = 0; i < size; ++i)
    {
        if (search == array[i].ISBN )
        {
            cout << "Book " << i + 1 << ":" << endl;
            cout << "Title: " << array[i].title << endl;
            cout << "Author: " << array[i].author << endl;
            cout << "ISBN: " << array[i].ISBN << endl;
            cout << endl;
        }
    }
}

void checkout(library (&array)[10], int size)
{
    cout << "Available Books:" << endl;
    for (int i = 0; i < size; ++i)
    {
        if (array[i].status == "available")
        {
            cout << "Book " << i + 1 << ":" << endl;
            cout << "Title: " << array[i].title << endl;
            cout << "ISBN: " << array[i].ISBN << endl;
            cout << endl;
        }
    }

    string borrow = "null";
    cout << "Enter the ISBN number of the book you wish to borrow: ";
    cin >> borrow;

    for (int i = 0; i < size; ++i)
    {
        if (borrow == array[i].ISBN)
        {
            cout << "You have borrowed the following book:" << endl;
            cout << "Title: " << array[i].title << endl;
            cout << "Author: " << array[i].author << endl;
            cout << "ISBN: " << array[i].ISBN << endl;
            array[i].status = "unavailable";

            cout << "Enter the date and month of issuance of the book: ";
            while (true)
            {
                cin >> date >> month;
                if (!datecheck(date, month))
                {
                    cout << "Invalid date and month entered. Please enter again: " << endl;
                }
                else
                {
                    break;
                }
            }

            cout << "You have to return this book in 7 days, otherwise a fine of PKR 20 will be issued for each day after the deadline." << endl;
        }
    }
}

void bookreturn(library (&array)[10], int size)
{
    string returnbook = "null";
    cout << "Enter the ISBN or title of the book you wish to return: ";
    cin >> returnbook;
    

    for (int i = 0; i < size; ++i)
    {
        if (returnbook == array[i].ISBN || returnbook == array[i].title)
        {
            if (array[i].status == "unavailable")
            {
                array[i].status = "available";
                fine(array,size);
            }
            else
            {
                cout << "The book you listed has not been borrowed." << endl;
                
            }
        }
    }
    
}

void fine(library array[], int size)
{
    int rdate, rmonth, fine = 0;
    cout << "Enter the date and month of return of the book: ";
    while (true)
    {
        cin >> rdate >> rmonth;
        if (!datecheck(rdate, rmonth))
        {
            cout << "Invalid date and month entered. Please enter again: " << endl;
        }
        else
        {
            break;
        }
    }
if (rmonth == month) 
{
        fine = rdate - date;
    }

    if (rmonth > month) 
	{
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        fine = (rdate - date) + ((rmonth - month) * ((rmonth == 1 || rmonth == 3 || rmonth == 5 || rmonth == 7 || rmonth == 8 || rmonth == 10 || rmonth == 12) ? 31 : ((rmonth == 4 || rmonth == 6 || rmonth == 9 || rmonth == 11) ? 30 : 28)));
    }

    if (fine > 7)
	 {
        cout << "You submitted the book " << fine << " days later." << endl;
        fine = (fine - 7) * 20;
        cout << "Your total payable fine is PKR " << fine << ". Please pay it to the librarian at the counter today,";
        cout << "otherwise your library card will be cancelled." << endl;
    }
}

bool datecheck(int date, int month)
{
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
    {
        
        return false;
    }

    if (date < 1 || date > months[month])
    {
        
        return false;
    }

    cout << "Entered date is valid." << endl;
    return true;
}

