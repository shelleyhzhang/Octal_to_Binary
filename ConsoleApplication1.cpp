/* ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
 Author: Shelley Zhang
 Date: 12/15/2019
 Purpose: To convert a string input of an octal number into binary number format
*/

#include <iostream>
#include <iomanip>  
#include <conio.h>
#include "Convertor.h"
using namespace std;

int main()
{
    string octnum;
    string result = "0000 0000 0000 0000";
    string::size_type MAX_CHARS = 7;

    cout << "Conversion Console Application" << endl << endl;
    
    Convertor c;
    while (true)
    {
        cout << "---Please enter an octal number (0 to 0177777), e.g. 012, or Esc key to exit" << endl;
        char ch = _getch();
        if (ch == 27) {
            cout << "Esc Key Pressed. Bye!" << endl;
            return EXIT_SUCCESS;
        }
        else {
            _putch(ch);
            result = c.sz_Convert(MAX_CHARS,ch);
            if (result == "EXIT") {
                return EXIT_SUCCESS;
            }
            else {
                cout << "Conversion Complete: " << result << endl << endl;
            }
                
        }
       
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
