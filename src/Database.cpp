#include "../inc/Database.hpp"

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

	cout << "enter the name of the new note.\n";
	do {
		cin >> fileName;
	} while(!isValid(fileName));
	if (file.is_open()){
		cout << "your note was successfully created.\n";
		file.close();
	}	
	else
		throw exception();
}


void Database::deleteNote()
{
	cout << "not yet implemented";
	system("read");
}

void Database::allNotes() {
	if(!countFiles())
		cout << "you have no files in your database.";
	else 
		showAllFiles();
	system("read");

}

void Database::openNote(const string &fileName) {
	cout << "----> " << fileName << endl;
	readFrom(fileName);
	writeInto(fileName);
}