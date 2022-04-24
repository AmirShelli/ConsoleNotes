#include "main.hpp"

class Filehandler {
protected:
	char *_directory;
	unsigned int count;
public:
	bool isValid(const string &fileName) const;
	void showAllFiles() const;
	void setDirectory(char *dirName);
	unsigned int countFiles();
};
