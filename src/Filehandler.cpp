#include "../inc/Filehandler.hpp"
#include <iostream>

bool Filehandler::isValid(const string &fileName) const {
	DIR* dir_point = opendir(this->_directory);
	dirent* entry;
	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG && fileName == entry->d_name){
			closedir(dir_point);
			return true;
		}
	}
	closedir(dir_point);
	return false;
}

void Filehandler::showAllFiles() const {
	DIR* dir_point = opendir(this->_directory);
	dirent* entry;

	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG)
				Filehandler::output(entry->d_name);
	}
	closedir(dir_point);
}

unsigned int Filehandler::countFiles()
{
	DIR* dir_point = opendir(this->_directory);
	dirent* entry;
	unsigned int count = 0;

	while ((entry = readdir(dir_point))){
		if (entry->d_type == DT_REG)
			count++;
	}
	closedir(dir_point);
	return count;
}

void Filehandler::setDirectory(char *dirName)
{
	_directory = dirName;
}


// void Filehandler::output(const string message) const {

// }