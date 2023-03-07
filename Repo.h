#pragma once
#include "Anime.h"
#include <vector>
#include <fstream>
class Repo
{
public:
	Repo();

	bool add(Anime a);
	bool remove(int i);
	bool edit(int i, Anime a);
	std::vector<Anime> getAll()const;
	int getSize();
	bool clear();


private:
	std::vector<Anime> v;

};