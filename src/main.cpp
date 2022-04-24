#include "../inc/Imenu.hpp"
#include "../inc/Primary.hpp"
#include "../inc/Secondary.hpp"

int main() {
	Database *currentDB = new Database("./db");
	Primary *mainMenu = new Primary();
	Secondary *addMenu = new Secondary();

	Imenu *currentMenu = mainMenu;
	string option;
	do {
		currentMenu->displayMenu();
		do {
			option = currentMenu->input();
		} while (currentMenu->choseOption(option, currentDB));
		if(option.compare("all")) // needs to be enhanced
			currentMenu = addMenu;
	}while (option.compare("exit"));
	return 0;
}