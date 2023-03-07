#pragma once
#include "Undo.h"
class Redo {
public:
	virtual void doRedo() = 0;

	virtual ~Redo() {};
};

class RedoUndoAdd:public Redo{
private:
	Repo* re;
	Anime a;
public:
	RedoUndoAdd(Repo* re, Anime a): re{re},a{a}{}
	void doRedo()override {
		re->add(a);
	}
};
