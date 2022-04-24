#include "../inc/main.hpp"

#include "../inc/main.hpp"
#include "../inc/Imenu.hpp"
#include "../inc/Primary.hpp"
#include "../inc/Secondary.hpp"

int main() {
	Database db("./db");
	Primary *mainMenu = new Primary();
	Secondary *addMenu = new Secondary();

	Imenu *currentMenu = mainMenu;
	string option;
	do {
		currentMenu->displayMenu();
		do {
			option = currentMenu->input();
		} while (currentMenu->choseOption(option, db));
	}while (option.compare("exit"));
	return 0;
}