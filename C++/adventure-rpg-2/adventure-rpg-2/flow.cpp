#include "flow.h"

// Pause and wait for the user to press 'enter' to continue
void beat()
{
	string _end;
	getline(std::cin, _end);
}

// Print out a nice separator line
void hline()
{
	// 50 units wide
	std::cout << string(50, '-') << "\n";
}

// Print a string to std::cout centered to fit 50 units.
void center(string s)
{
	int buffer = (50 - s.length()) / 2;
	std::cout << string(buffer, ' ') << s << string(buffer, ' ') << "\n";
}

// Print a new line
void nl()
{
	std::cout << "\n";
}