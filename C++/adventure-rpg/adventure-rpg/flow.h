#pragma once

#include "stdafx.h"

// Useful quick functions used to control the flow of the console program.

// Pause and wait for the user to press 'enter' to continue
void beat()
{
	string _end;
	getline(cin, _end);
}

// Print out a nice separator line
void hline()
{
	// 50 units wide
	cout << string(50, '-') << "\n";
}

// Print a string to std::cout centered to fit 50 units.
void center(string s)
{
	int buffer = (50 - s.length()) / 2;
	cout << string(buffer, ' ') << s << string(buffer, ' ') << "\n";
}

// Print a new line
void nline()
{
	cout << "\n";
}