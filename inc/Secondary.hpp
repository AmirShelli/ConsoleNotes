#include "Imenu.hpp"

class Secondary : public Imenu {
public:
	void displayMenu();
	bool choseOption(const string& option, Database db);
};