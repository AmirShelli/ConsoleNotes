#include "../inc/IOhandler.hpp"

const string IOhandler::input() const {
	string input;

	cout << "->\t";
	cin >> input;
	return input;
}

void IOhandler::output(const string message) {
	cout << message << endl
		<< "***" << endl;
}
