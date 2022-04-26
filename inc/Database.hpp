#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "main.hpp"
#include "Filehandler.hpp"
#include "IOhandler.hpp"
#include <unistd.h>

class Database : public Filehandler {
private:
	// const char *_homeDirectory = get_current_dir_name();
	void readFrom(const string &fileName);
	void writeInto(const string &fileName);
public:
	Database() = default;
	Database(const string &dirName);
	void addNote();
	void allNotes();
	void editNote(const string &fileName);
	void deleteNote(const string &fileName);

	// const char *getHome() const;
	const char *getDirectory() const;
};


#endif