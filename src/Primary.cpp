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
			system("clear");
			(db->*commandMap.find(option)->second)();
			waitCommand();
			return true;
		}
		catch (exception &e){
			system("clear");
			output(e.what());
			waitCommand();
		}
	}
	output("please choose one of the options written above!");
	return false;
}



void Primary::displayMenu(){
	system("clear");
	output("type one option.");
	output("\tall\tadd\texit");
}

