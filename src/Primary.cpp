#include "../inc/Primary.hpp"
#include <cstdlib>
#include <iostream>

Primary::Primary() {
	commandMap["add"] = &Primary::addNote;
	commandMap["all"] = &Primary::allNotes;
}

bool Primary::choseOption(const string& option, Database *db) {
	if(!option.compare("exit"))
		return true;
	if(commandMap.count(option)) {
		try {
			(db->*commandMap.find(option)->second)();
			cin.get();
			return true;
		}
		catch (exception &e){
			output(e.what());
		}
	}
	output("please choose one of the options written above!");
	return false;
}



void Primary::displayMenu(){
	string option;
	system("clear");
	output("type one option.");
	output("\tall\tadd\texit");
}

