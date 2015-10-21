/// Only this libraries are needed
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

/// Somewhere in your definitions

// Limiting the input to only one character
std::string readLimitedInput(int x, int y, int LIMIT) {
	//// Limit of characters
	//const int LIMIT = 1;
	// counter of characters
	int index = 0;
	// Our string to return
	std::string s;
	// Our character that we'll append to 's'
	char c;
	while (true) {
		gotoxy(x, y);
		c = _getch();
		// We make sure we've more than 0 letters 
		// (otherwise we'll be popping the string at index -1)
		if (c == 8 && index > 0) {
			s.pop_back();
			// Iterate back to our last position
			index--;
			x--;
			gotoxy(x, y);
			std::cout << " ";
		}
		else if (c == 8 && index == 0) {
			// Nothing happens (on purpose)
		}
		else {
			// This limits the amount of characters that
			// our input can receive (change 1 to desired limit)
			if (index != LIMIT) {
				// we push our character into our stack
				s.push_back(c);
				index++;
				x++;
				// Uppercase conversion
				// We do this for every non-digit using the isdigit(std::string) function
				// index - 1 because arrays are counted starting from 0, otherwise we can just use 'index'
				if (!(isdigit(s[index]))) {
					s[index - 1] = toupper(s[index - 1]);
				}
			}
		}
		gotoxy(x - 1, y);
		if (index - 1 != -1) {
			std::cout << s[index - 1];
		}

		if (c == 13) {
			return s;
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	// std::flush is a method which has the same use as std::endl (Except it doesn't insert a new line)
	// Basically, it ensures every character successfully arrives their destination
	// another way to call the method -> std::cout.flush();
	std::cout << std::flush;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(consoleHandle, coord);
}