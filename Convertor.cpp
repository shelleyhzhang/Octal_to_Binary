// Author: shelleyzhang@gmail.com
// Date: 12 / 15 / 2019
// Purpose : To convert a string input of an octal number into binary number format
#include "Convertor.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


string Convertor::sz_Convert(size_t MAX_CHARS, char x)
{
	string octnum = "0177777"; //initialize the octal number input string.
	string binum = "0000000000000000"; //initialize the binary number string.
	int digit = 0; //initialize individual digit reading.
	string result = "0000 0000 0000 0000";//initialize result string.

	getline(cin, octnum); 
	octnum = x + octnum; //append first input character to front of the string
	while (!check_number(MAX_CHARS, octnum)) {
		char ch = _getch();
		if (ch == 27) { //if input is ESC key
			cout << "Esc Key Pressed. Bye!" << endl;
			return "EXIT";
		}
		else {
			_putch(ch); //writes the character back to the console
			getline(cin, octnum);
			octnum = ch + octnum; //append first input character to the front of the string
		}
	}

	octnum = octnum.substr(1, octnum.length() - 1); //remove initial digit '0'
	if (octnum.length()) //if the length is postive
	{
		for (int i = octnum.length() - 1; i >= 0; i--)
		{
			digit = int(octnum[i]) - int('0'); //extract single digit one at a time
			//Consider 3 binary digits as a group, assign one digit at a time
			binum[18 - (octnum.length() - i) * 3] = (char) int(digit % 2) + int('0'); 
			//if octal number length reaches maximum, the left most digit [0 or 1] assigned to one digit only, as above
			if (!(octnum.length() == MAX_CHARS - 1 && i == 0)) 
			{
				binum[17 - (octnum.length() - i) * 3] = (char) int((digit % 4) / 2) + int('0');
				binum[16 - (octnum.length() - i) * 3] = (char) int(digit / 4) + int('0');
			}
		}
		result = binum.insert(4, " ").insert(9, " ").insert(14, " "); //insert a space between every 4 binary digits
	}
	return result;
}

bool Convertor::check_number(size_t MAX_CHARS, string x)
{
	string strsub;
	string prompt = "***Please re-enter a valid octal number 0-0177777, .e.g 012\n";
	if (x.empty() || x.length() > MAX_CHARS) {
		cout << "string is empty or reach maximum length of " << MAX_CHARS << endl << prompt;
		return false;
	}
	else if (x[0] != '0') {
		cout << "first digit is not 0" << endl << prompt;
		return false;
	}
	else {
		strsub = x.substr(1, x.length() - 1); //remove initial digit '0'
		size_t ilen = strsub.length(); //define strsub length
		if (ilen == MAX_CHARS - 1 && strsub[0] > '1') {
			cout << "input is above maximum allowed 0177777" << endl << prompt;
			return false;
		}
		for (size_t i = 0; i < ilen; ++i) {
			if (strsub[i] < '0' || strsub[i] > '7') {
				cout << "input has character#" << i + 2 << " not a valid digit [0-7]" << endl << prompt;
				return false;
			}
		}
	}
	return true;
}


