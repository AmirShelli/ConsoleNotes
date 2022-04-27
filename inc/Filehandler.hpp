#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include "main.hpp"
#include "IOhandler.hpp"

class Filehandler : public IOhandler {
protected:
	const char *_directory;
	unsigned int count;
public:
	bool isValid(const string &fileName) const;
	void showAllFiles() const;
	void setDirectory(char *dirName);
	unsigned int countFiles();
	// void output(const string message) const;
};

#endif