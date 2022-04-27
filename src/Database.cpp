#include "../inc/Database.hpp"
#include <cstdlib>
#include <cstdio>
#include <exception>


Database::Database(const string &directory)
{
	_directory = directory.c_str();
}

void Database::readFrom(const string &fileName) {
	string line;
	
	ifstream file;
	file.open(fileName, ios::out);
	if (file.is_open())
	{
		while (getline (file,line))
				cout << line << endl;
		file.close();
	}
	else 
		throw exception();
	
}

// const char *Database::getHome() const {
// 	return this->_homeDirectory;
// }

const char *Database::getDirectory() const {
	return this->_directory;
}

void Database::writeInto(const string &fileName) {
	string line;
	ofstream file;
	
	file.open(fileName, ios::app);
	if (file.is_open())
	{
		while(getline(cin, line) && line.compare(":q"))
			file << line << "\n";
		file.close();
	}
	else 
		throw exception();
}

void Database::addNote() {
	ofstream file;
	string fileName;

	do {
		output("name of the note: ");
		fileName = input();
	} while(isValid(fileName));

	file.open(this->getDirectory() + fileName);
	if (file.is_open()){
		output("your note was successfully created.");
		file.close();
	}	
	else
		throw exception();
}


void Database::deleteNote(const string &fileName)
{
	const int result = remove(fileName.c_str());
	if(result == 0)
		output("successfully delete.");
	else
		throw exception();
	waitCommand();
}

void Database::allNotes() {
	if(!this->countFiles())
		output("you have no files in your database.");
	else 
		this->showAllFiles();
}

void Database::editNote(const string &fileName) {
	try{
		system("clear");
		output("type \":q\" to finish writing.");
		output("----> " + fileName);
		readFrom(fileName);
		writeInto(fileName);
	}
	catch (exception &e)
	{
		//error
	}
}

Database::~Database() {}