#pragma once

#include "Repo.h"
#include "Redo.h"
class Undo {
public:
	virtual void doUndo() = 0;

	virtual ~Undo() {};
};

class UndoAdd : public Undo {
private:
	Repo* re;
	int pos;
public:
	UndoAdd(Repo* re, int pos) : re{re}, pos{pos} {}
	void doUndo() override {
		Anime a;
		a = re->getAll().at(pos);
		re->remove(pos);
	}
};

class UndoDelete : public Undo {
private:
	Repo* re;
	Anime anime;
public:
	UndoDelete(Repo* re, const Anime& anime) : re{re}, anime{anime} {}
	void doUndo() override {
		re->add(anime);
	}
};

class UndoEdit : public Undo {
private:
	Repo* re;
	int pos;
	Anime anime;
public:
	UndoEdit(Repo* re, int pos, const Anime& anime) : re{ re }, pos{ pos }, anime{ anime } {}
	void doUndo() override {
		re->edit(pos, anime);
	}
};
class UndoUndo : public Undo {
private:
	Repo* re;
	int i;
	Anime anime;
public:
	UndoUndo(Repo* re, int pos, const Anime& anime):re{re},i{i},anime{anime}{}
	void doUndo() override {

	}
};
