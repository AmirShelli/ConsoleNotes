#include "../inc/IOhandler.hpp"
#include <cstdio>
#include <cstdlib>

const string IOhandler::input() const {
	string input;

	cout << "->\t";
	cin >> input;
	return input;
}

void IOhandler::output(const string message) const {
	cout << message
		<< "\n***\n";
}

void IOhandler::waitCommand() const {
	output("enter any character to continue...");
	cin.get();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("clear");
}