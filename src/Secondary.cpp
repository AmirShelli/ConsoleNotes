#include "../inc/Secondary.hpp"

bool Secondary::choseOption(const string& option, Database db) {
	
	system("clear");
	if(isValid(option)) {
		output("type \":q\" to finish typing.");
		db.openNote(option);
		return true;
	}
	else if (option.compare("back")) {
		return true;
	}
	cout << "please type an existing file or \"back\"!\n";
	return false;
}

void Secondary::displayMenu() {
	string option;

	system("clear");
	output("enter the name of the note or \"back\" to go to the PRIMARY MENU\n");
}
