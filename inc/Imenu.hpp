#include "main.hpp"
#include "Database.hpp"
#include "IOhandler.hpp"

class Imenu :public IOhandler, public Database {
protected:
	Database myNotes;
	typedef void (Database::*function)();
	map<string,function> commandMap;
public:
	virtual void displayMenu() = 0;
	virtual bool choseOption(const string& option, Database db) = 0;
};
