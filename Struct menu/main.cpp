#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct menuItemType
{
    string menuItem;
    double menuPrice = 0.00;
};

void getData(fstream& inFile, menuItemType menuList[], int listSize)
{
    fstream in;
    in.open("Ch9_Ex4Data.txt");
    
    int i = 0;

    if (in.is_open())
    {
        while(i < listSize)
        {
            getline(in, menuList[i].menuItem);
            
            in >> menuList[i].menuPrice;
            in.ignore();
               
            i++;
        }
    }
    else 
    {
        cout << "File couldn't be opened" << endl;
    }
    in.close();
}

void showMenu(menuItemType menuList[], int listSize)
{
    cout << "Welcome to Johnny's Resturant\n    ----Today's Menu----\n";

    int count = 1;

    for (int i = 0; i < listSize; i++)
    {
        cout << count << ". " << left << setw(20) << menuList[i].menuItem << "$" << menuList[i].menuPrice << endl;
        count++;
    }
    cout << endl;
}

void printCheck(menuItemType menuList[], int listSize)
{
    char selection;
    const double tax = .05;
    double total = 0.00;
    int number;

    cout << "You can make up to 8 single order selections" << endl;
    do
    {
        cout << "Do you want to make a selection Y/y (Yes), N/n (No): ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
            cout << "Enter a number: ";
            cin >> number;

            if (number == 1)
            {
                total += menuList[0].menuPrice;
            }
            else if (number == 2)
            {
                total += menuList[1].menuPrice;
            }
            else if (number == 3)
            {
                total += menuList[2].menuPrice;
            }
            else if (number == 4)
            {
                total += menuList[3].menuPrice;
            }
            else if (number == 5)
            {
                total += menuList[4].menuPrice;
            }
            else if (number == 6)
            {
                total += menuList[5].menuPrice;
            }
            else if (number == 7)
            {
                total += menuList[6].menuPrice;
            }
            else if (number == 8)
            {
                total += menuList[7].menuPrice;
            }
         
        }
    } while (selection != 'n' && selection != 'N');
    
    cout << "\n  Welcome to Johnny's Resturaunt\n" << endl;
    cout << "\tFood Total: " << fixed << setprecision(2) << "$" << total << endl;
    cout << "\tTax: " << fixed << setprecision(2) << "$" << tax * total << endl;
    cout << "\tAmount Due: " << fixed << setprecision(2) << "$" << total * tax + total << endl;
    
}

int main()
{
    const int SIZE = 8;
    menuItemType menuList[SIZE];

    fstream in;
    in.open("Ch9_Ex4Data.txt");

    getData(in, menuList, SIZE);

    showMenu(menuList, SIZE);

    printCheck(menuList, SIZE);

    in.close();

    return 0;
}
