#include "Imenu.hpp" 
#include "main.hpp"

class Primary : public Imenu {
public:
	Primary();
	void displayMenu();
	bool choseOption(const string& option, Database db);
};