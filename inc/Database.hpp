#include "main.hpp"
#include "Filehandler.hpp"

class Database : public Filehandler {
private:
	list<string> notes;
	ofstream createNote();

	void readFrom(const string &fileName);
	void writeInto(const string &fileName);
public:
	Database(char *dirName);
	void addNote();
	void allNotes();
	void deleteAll();
	void openNote(const string &fileName);
};
