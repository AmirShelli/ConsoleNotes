#include "Imenu.hpp" 
#ifndef PRIMARY_HPP
#define PRIMARY_HPP

#include "main.hpp"

class Primary : public Imenu {
private:
	typedef void (Database::*function)();
	map<string,function> commandMap;
public:
	Primary();
	void displayMenu();
	bool choseOption(const string& option, Database *db);
	~Primary() {};
};

#endif