#include "../inc/Secondary.hpp"
#include <cstdlib>
#include <unistd.h>

Secondary::Secondary() {
	commandMap["edit"] = &Secondary::editNote;
	commandMap["delete"] = &Secondary::deleteNote;
}

bool Secondary::choseOption(const string& option, Database *db) {
	string fileName;

	if(commandMap.count(option)) {
		try {
			do {
				system("clear");
				db->allNotes();
				output("type the name of the file you need.");
				fileName = input();
			}while (!db->isValid(fileName));
			system("clear");
			(db->*commandMap.find(option)->second)(db->getDirectory() + fileName);
			return true;
		}
		catch (exception &e){
			system("clear");
			output(e.what());
			waitCommand();
		}
	}
	if (!option.compare("back") || !option.compare("exit") )
		return true;
	cout << "please type the right command or \"back\"!\n";
	displayMenu();
	return false;
}

void Secondary::displayMenu() {
	system("clear");
	output("type one option.");
	output("\tedit\tdelete\tback");
}
