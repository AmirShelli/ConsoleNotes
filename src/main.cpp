#include "../inc/main.hpp"
#include <exception>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>

class Database {
private:
	list<string> notes;
	ofstream createNote();
public:
	Database();
	void addNote();
	void allNotes();
	void deleteAll();
	void instructions();
	void writeInto(const string &fileName);
	void readFrom(const string &fileName);
	string &getNote(const string fileName);
};

void Database::readFrom(const string &fileName) {
	string line;
	
	ifstream file;
	file.open(fileName, ios::app);
	if (file.is_open())
	{
		cout << "\n***\n" 
			<< "you can write in this file, type \":q\" to finish typing.\n"
			<< "***\n";
		while (getline (file,line))
				cout << line << endl;
		file.close();
	}
	else 
		cout << "error\n"; //change to throw
}


void Database::writeInto(const string &fileName) {
	string line;
	
	ofstream file;
	file.open(fileName, ios::in);
	if (file.is_open())
	{
		do {
			getline(cin, line);
			file << line;
		} while(line.compare(":q"));
		file.close();
	}
	else cout << "can not open a file";
}

Database::Database()
{
	DIR* dir_point = opendir(".");
	dirent* entry;
	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG){		
			std::string fname = entry->d_name;
			if (fname.find(".txt", (fname.length() - 4)) != std::string::npos)
				notes.push_back(fname);
			cout << fname << endl;
		}
	}
}

string &Database::getNote(const string fileName)
{
	std::list<string>::iterator findIter = std::find(notes.begin(), notes.end(), fileName);
	return *findIter; //test for not found

}

ofstream Database::createNote() {
	ofstream file;
	string fileName;
	bool alreadyExists;
	stringstream ss;

	cout << "enter the name of the new note.\n";
	cin >> fileName;
	ss << fileName << ".txt";
	fileName = ss.str();
	file.open (fileName);
	alreadyExists = (find(this->notes.begin(), this->notes.end(), fileName) != this->notes.end());
	if(alreadyExists)
		throw exception();
	else
		notes.push_back(fileName);
	return file;
}

void Database::addNote() {
	ofstream file;
	
	file = createNote();
	try{
		if (file.is_open()){
			cout << "your note was successfully created.\n";
			file.close();
		}	
		else
			throw exception();
	}
	catch(exception e)
	{
		cout << "error.\n" << e.what();
	}
}

void Database::allNotes() {
	std::list<string>::iterator it;

	if(notes.empty())
		cout << "there are no notes in your database.\n";
	else {
		for (it = notes.begin(); it != notes.end(); ++it)
			std::cout << *it << endl;
	
	}
	
}

void Database::deleteAll()
{
	exit(0);
}

void Database::instructions()
{
	cout << "hello this is the help desk.\n"
		<< "I have nothing to help you with, sorry!\n";
}

class Menu {
private:
	Database myNotes;
public:
	void displayMenu();

	class IOptionHandler : public Database {
	protected:	
		typedef void (Database::*function)();
		map<string,function> commandMap;
	public:
		virtual bool choseOption(const string& option) = 0;
	};

	class MainMenu : public IOptionHandler
	{
	public:
		MainMenu();
		bool choseOption(const string& option);
	};

	class AllMenu : public IOptionHandler
	{
	public:
		bool choseOption(const string& option);
	};
};

Menu::MainMenu::MainMenu() {
	commandMap["add"] = &MainMenu::addNote;
	commandMap["all"] = &MainMenu::allNotes;
	commandMap["help"] = &MainMenu::instructions;
	commandMap["exit"] = &MainMenu::deleteAll;
}

bool Menu::MainMenu::choseOption(const string& option) {
	if(commandMap.count(option)) {
		(this->*commandMap.find(option)->second)();
		return true;
	}
	cout << "please choose one of the options written above!\n";
	return false;
}

bool Menu::AllMenu::choseOption(const string& option) {
	string &str = getNote(option);

	cout << "----> " << option << endl;
	if(str != "") {
		readFrom(str);
		writeInto(str);
		return true;
	}
	else if (option.compare("back")) {
		return true;
	}
	cout << "please type an existing file or \"back\"!\n";
	return false;
}

void Menu::displayMenu(){
	string option;
	MainMenu main;
	AllMenu all;

	do {
		cout << "***\ntype one option.\n";
		cout << "\tall\tadd\thelp\texit\n->\t";
		do {	
			cin >> option;
		} while(!main.choseOption(option));
		if (!option.compare("all"))
		{	
			cout << "enter the name of the note you want to read from/write into.\n"
				<< "or \"back\" to go to the MENU\n";
			do {	
				cin >> option;
			} while(!all.choseOption(option));
		}

	} while(1);
}

int main(){
	chdir("./db");
	Menu start;
	Database db;

	start.displayMenu();

	return 0;
}