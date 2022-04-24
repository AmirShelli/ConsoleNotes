#include "Imenu.hpp" 
#ifndef PRIMARY_HPP
#define PRIMARY_HPP

#include "main.hpp"

class Primary : public Imenu {
public:
	Primary();
	void displayMenu();
	bool choseOption(const string& option, Database *db);
};

#endif