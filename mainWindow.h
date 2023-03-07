#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QListWidget>
#include <QKeyEvent>
#include "Ctrl1.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
/*
QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE
*/
class mainWindow:public QWidget
{
	Q_OBJECT
signals:
	void ZPressed();
public:
	
	mainWindow(Ctrl c) :c{ c }
	{
		createUI();
		refreshList();
	}

private:
	Ctrl c;
	
	QHBoxLayout* mainLayout = new QHBoxLayout();
	QListWidget* listWidget = new QListWidget();
	QFormLayout* formLayout = new QFormLayout();
	QWidget* widget = new QWidget();
	QPushButton* addButton = new QPushButton("Add an anime");
	QPushButton* removeButton = new QPushButton("Remove an anime");
	QPushButton* undoButton = new QPushButton("Undo");
	QPushButton* editButton = new QPushButton("Edit an anime");
	QLineEdit* titleText = new QLineEdit("Title");
	QLineEdit* episodesText = new QLineEdit("Episodes");
	QLineEdit* studioText = new QLineEdit("Studio");
	QLineEdit* ratingText = new QLineEdit("Rating");
	QLineEdit* indexText = new QLineEdit("Index");
	QLabel* titleLabel = new QLabel("TITLE");
	QLabel* episodesLabel = new QLabel("EPISODES");
	QLabel* studioLabel = new QLabel("STUDIO");
	QLabel* ratingLabel = new QLabel("RATING");
	void handleAdd();
	void handleRemove();
	void handleEdit();
	void handleUndo();
	void refreshList();
	void createUI();
	void keyPressEvent(QKeyEvent* e);




};

#endif //MAINWINDOW_H
/*
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qformlayout.h>
#include "Anime.h"
#include <qmessagebox.h>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include "Ctrl1.h"


class GUI : public QWidget {
private:
	Ctrl& c;
	QListWidget* carsList;
	QLabel* regNumberLabel;
	QLabel* manufacturerLabel;
	QLabel* modelLabel;
	QLabel* typeLabel;
	QLineEdit* regNumberText;
	QLineEdit* manufacturerText;
	QLineEdit* modelText;
	QLineEdit* typeText;
	QPushButton* addButton;
	QPushButton* findButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterByTypeButton;
	QPushButton* filterByManufacturerButton;
	QPushButton* sortByRegNumberButton;
	QPushButton* sortByTypeButton;
	QPushButton* sortByManModelButton;
	QPushButton* reportManufacturerButton;
	QPushButton* undoButton;
	QVBoxLayout* manufLayout;
	vector<QPushButton*> manufButtons;

	QWidget* washListWindow;
	QPushButton* washListButton;
	QListWidget* washList;
	QPushButton* refreshWashListButton;
	QPushButton* emptyWashListButton;
	QLabel* washListRegNumberLabel;
	QLineEdit* washListRegNumberText;
	QPushButton* washListAddButton;
	QLabel* generateCarsLabel;
	QLineEdit* generateCarsText;
	QPushButton* generateCarsButton;
	QLabel* exportWashListLabel;
	QLineEdit* exportWashListText;
	QPushButton* exportWashListButton;

	void initGUI();
	void connectSignalsSlots();
	void refreshCarsList(const vector<Anime>&);
	void updateManufacturerButtons();

	void storeCar();
	void findCar();
	void deleteCar();
	void updateCar();
	void filterByManufacturer();
	void filterByType();
	void reportManufacturer();
	void washListManagement();

	void refreshWashList(const vector<Anime>&);
	void connectSignalsSlotsWashList();
; public:
	GUI(Ctrl& c) : c{ c } {
		this->initGUI();
		this->connectSignalsSlots();
		this->refreshCarsList(c.getAll());
	}
};
*/