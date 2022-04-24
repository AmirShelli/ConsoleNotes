#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "main.hpp"
#include "Filehandler.hpp"

class Database : public Filehandler {
private:
	list<string> notes;
	ofstream createNote();

	void readFrom(const string &fileName);
	void writeInto(const string &fileName);
public:
	Database(const string &dirName);
	void addNote();
	void allNotes();
	void deleteNote();
	void openNote(const string &fileName);
};


#endif