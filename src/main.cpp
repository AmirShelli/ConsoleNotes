#include "../inc/main.hpp"
#include <sstream>
#include <map>

struct Note{
	string content;
	Note* next;
	Note* prev;
};

class Database{
private:

	Note* newNote();
public:
	
	void addNote();
	void allNotes();
	void deleteAll();
	void instructions();
	void writeIn(string name);
	void readFrom(string name);
};

class Menu{
private:
	Database myNotes;
	
public:
	void displayMenu();
};

class OptionHandler : public Database {
	typedef void (Database::*function)();
	map<string,function> commandMap;

	void choseOption(const string& option) {
		if(commandMap.count(option))
			(this->*commandMap.find(option)->second)();
		else
			cout << "please choose one of the options written above!\n";
	}
	OptionHandler();
};

OptionHandler::OptionHandler()
{
	commandMap["add"] = &OptionHandler::addNote;
	commandMap["all"] = &OptionHandler::allNotes;
	commandMap["exit"] = &OptionHandler::deleteAll;
	commandMap["help"] = &OptionHandler::instructions;
}

bool Menu::isValid(const string &str) const {return true;}

void Menu::displayMenu(){
	string option;

	{
		cout << "type one option.\n";
		cout << "\tall\tnew\thelp\texit\n";
		cin >> option;
	} while(!isValid(option));
	
}

int main(){
	ofstream file;
	string fileName;
	stringstream ss;
	
	//for new, in a separate function
	Note* note = new Note();
	cout << "enter the name of the new note.\n";
	cin >> fileName; 
	ss << "./db/" << fileName << ".txt";
	fileName= ss.str(); //check if exist
	file.open (fileName);
	if (file.is_open()) //try catch?
	{
		cout << "your note was successfully created.\n";
		file.close();
	}
	else 
		cout << "error.\n";

	return 0;
}