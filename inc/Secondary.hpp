#ifndef SECONDARY_HPP
#define SECONDARY_HPP

#include "Imenu.hpp"

class Secondary : public Imenu {
private:
	typedef void (Database::*function)(const string &str);
	map<string,function> commandMap;
public:
	Secondary();
	void displayMenu();
	bool choseOption(const string& option, Database *db);
};

#endif