#include "../inc/Filehandler.hpp"

bool Filehandler::isValid(const string &fileName) const {
	DIR* dir_point = opendir(_directory);
	dirent* entry;
	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG && fileName == entry->d_name)
			return true;
	}
	return false;
}

void Filehandler::showAllFiles() const {
	DIR* dir_point = opendir(_directory);
	dirent* entry;

	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG)
			cout << entry->d_name << endl;
	}
}

unsigned int Filehandler::countFiles()
{
	DIR* dir_point = opendir(_directory);
	dirent* entry;
	unsigned int count;


	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG)
			count++;
	}
	return count;
}

void Filehandler::setDirectory(char *dirName)
{
	_directory = dirName;
}