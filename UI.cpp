#include "UI.h"
#include <iostream>
UI::UI()
{
	/**
	 * .
	 * null constructor
	 */
	this->c = {};
}

void UI::showMenu() {
	/**
	 * .
	 * function used for showing the menu in the console
	 */
	std::cout << "1. Add\n";
	std::cout << "2. Delete\n";
	std::cout << "3. Edit\n";
	std::cout << "4. Display\n";
	std::cout << "5. Read from file\n";
	std::cout << "6. Save to file\n";
	std::cout << "u. Undo\n";
	std::cout << "x/X. Quit\n";
	std::cout << "\n";
}

void UI::run() {

	/**
	 * .
	 * function used for calling the functionalities of the application based on the input of the user
	 */
	while (true) {
		showMenu();
		std::string cmd;
		getline(std::cin, cmd, '\n');
		if (cmd == "x" || cmd == "X") {
			return;
		}
		else if (cmd == "") {
			continue;
		}
		else if (cmd == "1") {
			add();
		}
		else if (cmd == "2") {
			remove();
		}
		else if (cmd == "3") {
			edit();
		}
		else if (cmd == "4") {
			display();
		}
		else if (cmd == "5") {
			readFromFile();
		}
		else if(cmd=="6")
		{
			saveToFile();
		}
		else if (cmd == "u") {
			undo();
		}
		
	}
}

UI::UI(Ctrl* c_)
{
	/**
	 * .
	 * parametric constructor
	 * \param c_ controller class
	 */
	this->c = c_;
}

bool UI::add()
{
	/**
	 * .
	 * add function
	 * \return 
	 */
	int episodes;
	std::string title;
	std::string studio;
	int rating;
	std::cout << "Number of episodes:";
	std::cin >> episodes;
	std::cin.get();
	std::cout << "Title:";
	getline(std::cin, title, '\n');
	std::cout << "Studio:";
	getline(std::cin, studio, '\n');
	std::cout << "Rating:";
	std::cin >> rating;

	this->c->add(episodes, title, studio, rating);


	return false;
}

bool UI::display()
{
	/**
	 * .
	 * displays all the animes from the repository
	 * \return 
	 */
	this->c->display();
	return false;
}

bool UI::remove()
{
	/**
	 * .
	 * asks for the index of the removed anime from the list
	 * \return 
	 */
	int i;
	std::cout << "Index:";
	std::cin >> i;
	this->c->remove(i);
	return false;
}

bool UI::edit()
{
	/**
	 * .
	 * asks for the index of the modified anime from the list and for the new data 
	 * \return 
	 */
	int i;
	std::cout << "Index of the edited anime:";
	std::cin >> i;
	std::cin.get();
	int episodes;
	std::string title;
	std::string studio;
	int rating;
	std::cout << "New title:";
	getline(std::cin, title, '\n');
	std::cout << "New number of episodes:";

	std::cin >> episodes;
	std::cin.get();
	std::cout << "New studio:";
	getline(std::cin, studio, '\n');
	std::cout << "New rating:";
	std::cin >> rating;
	this->c->edit(i, episodes, title, studio, rating);

	return false;
}

bool UI::undo() {
	/**
	 * .
	 * calls the undo function
	 * \return 
	 */
	c->undo();
	return false;
}

bool UI::readFromFile()
{
	/**
	 * .
	 * calls the read from file function
	 * \return 
	 */
	this->c->readFromFile();
	return false;
}

bool UI::saveToFile()
{
	/**
	 * .
	 * calls the save to file function
	 * \return 
	 */
	this->c->saveToFile();
	return false;
}
