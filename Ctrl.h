#pragma once
#include "Repo.h"
#include "Undo.h"
#include <cstring>
#include <stack>

enum class ActionType {
	ADD,
	REMOVE,
	EDIT
};
class Ctrl
{
	
public:
	Ctrl();
	Ctrl(Repo* re);
	bool add(int e, std::string t, std::string s, int r);
	bool display();
	bool remove(int i);
	bool edit(int i, int e, std::string t, std::string s, int r);
	bool undo();
	bool redo();
	bool readFromFile();
	bool saveToFile();
private:
	Repo* re;
	std::stack<ActionType> undoStack;
	std::stack<ActionType> redoStack;
	std::vector<Undo*> undoList;
	std::vector<Redo*> redoList;
};