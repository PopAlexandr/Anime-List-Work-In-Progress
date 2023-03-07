#pragma once
#include "Ctrl.h"
#include "Anime.h"
#include <cstring>
#include <iostream>
class UI
{
public:
	UI();
	UI(Ctrl* c);
	void showMenu();
	void run();
	bool add();
	bool display();
	bool remove();
	bool edit();
	bool undo();
	bool readFromFile();
	bool saveToFile();
private:
	Ctrl* c;

};