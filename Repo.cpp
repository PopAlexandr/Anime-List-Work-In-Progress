#include "Repo.h"
#include <fstream>
Repo::Repo()
{
	/**
	 * .
	 * null constructor
	 */
	this->v = {};
}


bool Repo::add(Anime a)
{
	/**
	 * .
	 * add function 
	 * \param a anime we add to the repo
	 * \return ye
	 */
	this->v.push_back(a);
	return true;
}

bool Repo::remove(int i)
{
	/**
	 * .
	 * remove function of an anime from index
	 * \param i the index of the anime we want to remove
	 * \return nah
	 */
	this->v.erase(v.begin() + i - 1);
	return false;
}

bool Repo::edit(int i, Anime a)
{
	/**
	 * .
	 * edit function
	 * \param i the index of the anime we edit
	 * \param a the new anime
	 * \return 
	 */
	this->v.at(i) = a;
	return false;
}

std::vector<Anime> Repo::getAll() const
{
	/**
	 * .
	 * getter
	 * \return all the animes from the repository 
	 */
	return this->v;
}

int Repo::getSize()
{
	/**
	 * .
	 * getter
	 * \return size of the repository 
	 */
	return this->v.size();
}

bool Repo::clear()
{
	/**
	 * .
	 * deletes all the data from the repository
	 * \return nay
	 */
	this->v.clear();
	return false;
}
