#include "../inc/Primary.hpp"
#include <cstdlib>
#include <iostream>

Primary::Primary() {
	commandMap["add"] = &Primary::addNote;
	commandMap["all"] = &Primary::allNotes;
	commandMap["exit"] = &Primary::deleteAll;
}

bool Primary::choseOption(const string& option, Database db) {
	if(commandMap.count(option)) {
		try {
			(db.*commandMap.find(option)->second)();
			return true;
		}
		catch (exception &e){
			cout << "error";
		}
	}
	output("please choose one of the options written above!");
	return false;
}



void Primary::displayMenu(){
	string option;

	system("clear");
	output("type one option.");
	output("\tall\tadd\thelp\texit");
}

