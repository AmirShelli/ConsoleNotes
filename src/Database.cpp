#include "../inc/Database.hpp"
#include <cstdlib>


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

const char *Database::getHome() const {
	return this->_homeDirectory;
}

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
			file << line << endl;
		file.close();
	}
	else 
		throw exception();
}

void Database::addNote() {
	ofstream file;
	string fileName;
	bool alreadyExists;

	do {
		cout << "name of the note: ";
		cin >> fileName;
	} while(isValid(fileName));

	file.open(this->getDirectory() + fileName);
	if (file.is_open()){
		cout << "your note was successfully created.\n";
		file.close();
		cin.get();
	}	
	else
		throw exception();
}


void Database::deleteNote(const string &fileName)
{
	cout << "not yet implemented";
	cin.get();
}

void Database::allNotes() {
	system("clear");
	if(!this->countFiles())
		cout << "you have no files in your database.";
	else 
		this->showAllFiles();
	cin.get();

}

void Database::editNote(const string &fileName) {
	try{
		system("clear");
		cout << "type \":q\" to finish writing.\n";
		cout << "----> " << fileName << endl;
		readFrom(fileName);
		writeInto(fileName);
	}
	catch (exception &e)
	{
		//error
	}
}