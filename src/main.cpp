#include "../inc/Imenu.hpp"
#include "../inc/Primary.hpp"
#include "../inc/Secondary.hpp"
#include <unistd.h>

void freeAll() {}

template<typename T, typename... Types>
void freeAll(T obj1, Types... obj2){
	delete obj1;
	freeAll(obj2...);
}

int main() {
	Database *currentDB = new Database(".//db//");
	Primary *mainMenu = new Primary();
	Secondary *addMenu = new Secondary();

	Imenu *currentMenu = mainMenu;
	string option;
	do {
		currentMenu->displayMenu();
		do {
			option = currentMenu->input();
		} while (!currentMenu->choseOption(option, currentDB));
		if(!option.compare("all")) 
			currentMenu = addMenu;
		else
			currentMenu = mainMenu;
	}while (option.compare("exit"));

	
	freeAll(mainMenu, addMenu, currentDB); 
	return 0;
}