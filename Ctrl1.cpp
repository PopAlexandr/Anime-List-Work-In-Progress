#include "Repo.h"
#include <qdebug.h>
#include "Anime.h"
#include "Redo.h"
#include "Ctrl1.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

#include <vector>

using namespace std;

Ctrl::Ctrl() {
	/**
	 null constructor
	 */
	re=new Repo();
}

Ctrl::Ctrl(Repo* re_)
{
	/**
	 * .
	 * parameterized constructor
	 * \param re_  the parameter
	 */
	this->re = re_;
}
bool Ctrl::add( int e,  std::string t,  std::string s,  int r)
{
	/**
	 * .
	 * add function for a new anime
	 * \param e number of episodes of the new anime
	 * \param t title of the new anime
	 * \param s studio of the new anime
	 * \param r rating of the new anime
	 * \return false
	 */

	Anime a;
	a.setEpisodes(e);
	a.setTitle(t);
	a.setStudio(s);
	a.setRating(r);
	this->re->add(a);
	undoList.push_back(new UndoAdd(re, re->getSize()));
	return false;
}

bool Ctrl::display()
{
	/**
	 * .
	 * display funcion
	 * \return true
	 */
	std::vector<Anime> v;
	v = this->re->getAll();
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v.at(i);
	}
	return true;
}

bool Ctrl::remove(int i)
{
	/**
	 * .
	 * remove an element by index
	 * \param i the index
	 * \return false
	 */
	if (i+1 == re->getSize()) {
		
		Anime anime{ re->getAll().at(i) };
		this->re->remove(i+1);
		undoList.push_back(new UndoDelete(re, anime));
	}
	else{
		
		Anime anime{ re->getAll().at(i) };
		this->re->remove(i+1);
		undoList.push_back(new UndoDelete(re, anime));
	}
		
		return false;
	
}

bool Ctrl::edit(int i, int e, std::string t, std::string s, int r)
{
	/**
	 * .
	 * edit the parametres of an existing anime
	 * \param i the index of the modified anime
	 * \param e the new number of episodes of the modified anime
	 * \param t the new title of the modified anime
	 * \param s the new studio of the modified anime
	 * \param r the new rating of the modified anime
	 * \return ye
	 */
	Anime a;
	Anime old{ re->getAll().at(i) };
	a.setEpisodes(e);
	a.setTitle(t);
	a.setStudio(s);
	a.setRating(r);
	this->re->edit(i, a);
	undoList.push_back(new UndoEdit(re, i, old));
	return false;
}

bool Ctrl::undo() {
	/**
	 * .
	 * undo funcion
	 * \return no
	 */

	 //redoList.push_back(new Redoceplredo(re, i, old);
	Undo* toUndo{ undoList.back() };
	toUndo->doUndo();
	undoList.pop_back();
	delete toUndo;
	/*
	if (this->undoStack.top() == ActionType::ADD) {
		this->redoStack.push({ ActionType::ADD,this->undoStack.top().second });
		this->undoStack.pop();
		this->re->remove(this->redoStack.size() - 1);
		return true;

	}

	else if (this->undoStack.top().first == ActionType::REMOVE) {
		this->redoStack.push({ ActionType::REMOVE,this->undoStack,this->undoStack.top().second });
		this->undoStack.pop();
		this->re->add(this->redoStack.top().second);
		return true;

	}


	*/
	return false;
}
std::vector<Anime> Ctrl::returnAll()
{
	return re->getAll();
}

bool Ctrl::redo() {
	Redo* toRedo{ redoList.back() };
	toRedo->doRedo();
	redoList.pop_back();
	delete toRedo;
	return false;
}

bool Ctrl::readFromFile()
{
	/**
	 * .
	 * function used for reading from the csv file
	 * \return nay
	 */
	std::ifstream f("File.csv");
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	if (f.is_open())
	{
		while (getline(f, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file\n";
	this->re->clear();
	for (int i = 0; i < content.size(); i++)
	{


		Anime a;
		a.setTitle(content[i].at(0));

		a.setEpisodes(stoi(content[i].at(1)));

		a.setStudio(content[i].at(2));


		a.setRating(stoi(content[i].at(3)));
		this->re->add(a);


	}
	f.close();
	return false;

}

bool Ctrl::saveToFile()
{
	/**
	 * .
	 * function used the repo data into the file
	 * \return
	 */
	std::ofstream g("File.csv");

	for (auto anime : re->getAll()) {
		g << anime.getTitle() << ",";
		g << anime.getEpisodes() << ",";
		g << anime.getStudio() << ",";
		g << anime.getRating() << "\n";
	}

	return false;
}