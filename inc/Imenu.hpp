#ifndef IMENU_HPP
#define IMENU_HPP

#include "main.hpp"
#include "Database.hpp"
#include "IOhandler.hpp"

class Imenu : public Database {
public:
	virtual void displayMenu() = 0;
	virtual bool choseOption(const string& option, Database *db) = 0;
};

#endif
