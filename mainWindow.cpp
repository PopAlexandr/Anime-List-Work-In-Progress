#include "mainWindow.h"

#include <QMainWindow>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QLabel.h>
#include "Anime.h"
#include "Ctrl1.h"
#include "ctype.h"
#include <QMessageBox>

void mainWindow::refreshList()
{
	this->listWidget->clear();
	for (int i = 0; i < this->c.returnAll().size(); i++) {
		std::string str=this->c.returnAll().at(i).getTitle() + " " + std::to_string(this->c.returnAll().at(i).getEpisodes()) + " " + this->c.returnAll().at(i).getStudio() + " " + std::to_string(this->c.returnAll().at(i).getRating()); //
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(str));
		listWidget->addItem(item);
	}
}

void mainWindow::handleAdd() {
	qDebug() << "handleAdd";
	for (int i = 0; i < episodesText->text().length(); i++) {
		qDebug() << episodesText->text()[i];
		if (episodesText->text()[i].isDigit() == false)

		{
			QMessageBox m;
			m.critical(0, "Error", "Invalid number of episodes!");
			m.setFixedSize(500, 200);
			return;
		}
	}
	for (int i = 0; i < ratingText->text().length(); i++)
		if (ratingText->text()[i].isDigit() == false)

		{
			QMessageBox m;
			m.critical(0, "Error", "Invalid rating!");
			m.setFixedSize(500, 200);
			return;
		}
	


	this->c.add(stoi(episodesText->text().toStdString()), titleText->text().toStdString(), studioText->text().toStdString(), stoi(ratingText->text().toStdString()));
	refreshList();
}

void mainWindow::handleRemove()
{

	qDebug() << "handleRemove";
	
	
	qDebug() << this->listWidget->currentRow();
	this->c.remove(this->listWidget->currentRow());
	

	refreshList();
}

void mainWindow::handleEdit()
{
	qDebug() << "handleEdit";
	for (int i = 0; i < episodesText->text().length(); i++)
		if (episodesText->text()[i].isDigit() == false)

		{
			QMessageBox m;
			m.critical(0, "Error", "Invalid number of episodes!");
			m.setFixedSize(500, 200);
			return;
		}
	for (int i = 0; i < ratingText->text().length(); i++)
		if (ratingText->text()[i].isDigit() == false)

		{
			QMessageBox m;
			m.critical(0, "Error", "Invalid rating!");
			m.setFixedSize(500, 200);
			return;
		}
	for (int i = 0; i < indexText->text().length(); i++)
		if (indexText->text()[i].isDigit() == false)

		{
			QMessageBox m;
			m.critical(0, "Error", "Invalid index!");
			m.setFixedSize(500, 200);
			return;
		}
	if (indexText->text().toInt() < -1 or indexText->text().toInt() > c.returnAll().size())
	{
		QMessageBox m;
		m.critical(0, "Error", "Invalid Index!");
		m.setFixedSize(500, 200);
		return;
	}
	this->c.edit(indexText->text().toInt(), episodesText->text().toInt(), titleText->text().toStdString(), studioText->text().toStdString(), ratingText->text().toInt());
	refreshList();

}

void mainWindow::handleUndo()
{
	qDebug() << "handleUndo";
	this->c.undo();
	refreshList();
}

void mainWindow::createUI()
{
	this->setLayout(mainLayout);
	mainLayout->addWidget(listWidget);
	mainLayout->addLayout(formLayout);
	formLayout->addWidget(addButton);
	formLayout->addWidget(undoButton);
	formLayout->addWidget(removeButton);
	formLayout->addWidget(editButton);
	formLayout->addWidget(indexText);
	formLayout->addWidget(titleText);
	formLayout->addWidget(episodesText);
	formLayout->addWidget(studioText);
	formLayout->addWidget(ratingText);
	QObject::connect(addButton, &QPushButton::clicked, this, &mainWindow::handleAdd);
	QObject::connect(editButton, &QPushButton::clicked, this, &mainWindow::handleEdit);
	QObject::connect(removeButton, &QPushButton::clicked, this, &mainWindow::handleRemove);
	QObject::connect(undoButton, &QPushButton::clicked, this, &mainWindow::handleUndo);
	QObject::connect(this, &mainWindow::ZPressed, this, &mainWindow::handleUndo);
	//QObject::connect()
	
}

void mainWindow::keyPressEvent(QKeyEvent* e)
{
	if ((e->key() == Qt::Key_Z) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
	{
		emit ZPressed();
	}
}

//void GUI::initGUI() {
//	QHBoxLayout* mainLayout = new QHBoxLayout();
//
//	// List details (Left side)
//	QWidget* listWidget = new QWidget();
//	QVBoxLayout* listLayout = new QVBoxLayout();
//	carsList = new QListWidget();
//	listLayout->addWidget(carsList);
//
//	// Filter buttons
//	QWidget* filterWidget = new QWidget();
//	QHBoxLayout* filterLayout = new QHBoxLayout();
//	filterWidget->setLayout(filterLayout);
//	filterByManufacturerButton = new QPushButton("Filter by Manufacturer");
//	filterLayout->addStretch();
//	filterLayout->addWidget(filterByManufacturerButton);
//	filterLayout->addStretch();
//	filterByTypeButton = new QPushButton("Filter by Type");
//	filterLayout->addWidget(filterByTypeButton);
//	filterLayout->addStretch();
//	listLayout->addWidget(filterWidget);
//
//	// Sort buttons
//	QWidget* sortWidget = new QWidget();
//	QHBoxLayout* sortLayout = new QHBoxLayout();
//	sortWidget->setLayout(sortLayout);
//	sortByRegNumberButton = new QPushButton("Sort by Registration Number");
//	sortLayout->addStretch();
//	sortLayout->addWidget(sortByRegNumberButton);
//	sortByTypeButton = new QPushButton("Sort by Type");
//	sortLayout->addStretch();
//	sortLayout->addWidget(sortByTypeButton);
//	sortByManModelButton = new QPushButton("Sort by Manufacturer and Model");
//	sortLayout->addStretch();
//	sortLayout->addWidget(sortByManModelButton);
//	listLayout->addWidget(sortWidget);
//
//	// Report buttons
//	QWidget* reportWidget = new QWidget();
//	QHBoxLayout* reportLayout = new QHBoxLayout();
//	reportWidget->setLayout(reportLayout);
//	reportLayout->addStretch();
//	reportManufacturerButton = new QPushButton("Report Manufacturer");
//	reportLayout->addWidget(reportManufacturerButton);
//	reportLayout->addStretch();
//	listLayout->addWidget(reportWidget);
//
//	mainLayout->addLayout(listLayout);
//
//	// Car details (Right side)
//	QWidget* carWidget = new QWidget();
//	QFormLayout* carLayout = new QFormLayout();
//	carWidget->setLayout(carLayout);
//	regNumberLabel = new QLabel("Registration number: ");
//	manufacturerLabel = new QLabel("Manufacturer: ");
//	modelLabel = new QLabel("Model: ");
//	typeLabel = new QLabel("Type: ");
//	regNumberText = new QLineEdit();
//	carLayout->addRow(regNumberLabel, regNumberText);
//	manufacturerText = new QLineEdit();
//	carLayout->addRow(manufacturerLabel, manufacturerText);
//	modelText = new QLineEdit();
//	carLayout->addRow(modelLabel, modelText);
//	typeText = new QLineEdit();
//	carLayout->addRow(typeLabel, typeText);
//
//	// Add button with stretch
//	QWidget* addWidget = new QWidget();
//	QHBoxLayout* addLayout = new QHBoxLayout();
//	addLayout->addStretch();
//	addButton = new QPushButton("Add");
//	addLayout->addWidget(addButton);
//	addLayout->addStretch();
//	addWidget->setLayout(addLayout);
//	carLayout->addRow(addWidget);
//
//	// Find, Delete, Update buttons
//	QWidget* FDUWidget = new QWidget();
//	QHBoxLayout* FDULayout = new QHBoxLayout();
//	findButton = new QPushButton("Find");
//	FDULayout->addWidget(findButton);
//	deleteButton = new QPushButton("Delete");
//	FDULayout->addWidget(deleteButton);
//	updateButton = new QPushButton("Update");
//	FDULayout->addWidget(updateButton);
//	FDUWidget->setLayout(FDULayout);
//	carLayout->addRow(FDUWidget);
//
//	// Undo button
//	QWidget* undoWidget = new QWidget();
//	QHBoxLayout* undoLayout = new QHBoxLayout();
//	undoWidget->setLayout(undoLayout);
//	undoLayout->addStretch();
//	undoButton = new QPushButton("Undo");
//	undoLayout->addWidget(undoButton);
//	undoLayout->addStretch();
//	carLayout->addRow(undoWidget);
//
//	// Wash list button
//	QWidget* washListWidget = new QWidget();
//	QHBoxLayout* washListLayout = new QHBoxLayout();
//	washListWidget->setLayout(washListLayout);
//	washListLayout->addStretch();
//	washListButton = new QPushButton("Wash List");
//	washListLayout->addWidget(washListButton);
//	washListLayout->addStretch();
//	carLayout->addRow(washListWidget);
//
//	mainLayout->addWidget(carWidget);
//
//	// Manufacturer buttons
//	QWidget* manufWidget = new QWidget();
//	manufLayout = new QVBoxLayout();
//	manufWidget->setLayout(manufLayout);
//	for (const auto& entry : carsSrv.reportManufacturerCount()) {
//		QPushButton* button = new QPushButton(QString::fromStdString(entry.first));
//		manufButtons.push_back(button);
//		manufLayout->addWidget(button);
//	}
//	mainLayout->addWidget(manufWidget);
//
//	this->setLayout(mainLayout);
//}
//
//void GUI::connectSignalsSlots() {
//	QObject::connect(carsList, &QListWidget::itemSelectionChanged, [&]() {
//		auto selected{ carsList->selectedItems() };
//		if (selected.isEmpty()) {
//			regNumberText->setText("");
//			manufacturerText->setText("");
//			modelText->setText("");
//			typeText->setText("");
//		}
//		else {
//			auto selectedRegNumber{ selected.at(0) };
//			auto regNumber{ selectedRegNumber->text().toStdString() };
//			auto car{ carsSrv.findCarByRegistrationNumber(regNumber) };
//			regNumberText->setText(QString::fromStdString(car.getRegNumber()));
//			manufacturerText->setText(QString::fromStdString(car.getManufacturer()));
//			modelText->setText(QString::fromStdString(car.getModel()));
//			typeText->setText(QString::fromStdString(car.getType()));
//		}
//		});
//
//	QObject::connect(addButton, &QPushButton::clicked, this, &GUI::storeCar);
//	QObject::connect(findButton, &QPushButton::clicked, this, &GUI::findCar);
//	QObject::connect(deleteButton, &QPushButton::clicked, this, &GUI::deleteCar);
//	QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateCar);
//	QObject::connect(filterByManufacturerButton, &QPushButton::clicked, this, &GUI::filterByManufacturer);
//	QObject::connect(filterByTypeButton, &QPushButton::clicked, this, &GUI::filterByType);
//	QObject::connect(sortByRegNumberButton, &QPushButton::clicked, this, [&]() {
//		refreshCarsList(carsSrv.sortByRegistrationNumber());
//		});
//	QObject::connect(sortByTypeButton, &QPushButton::clicked, this, [&]() {
//		refreshCarsList(carsSrv.sortByType());
//		});
//	QObject::connect(sortByManModelButton, &QPushButton::clicked, this, [&]() {
//		refreshCarsList(carsSrv.sortByManufacturerModel());
//		});
//	QObject::connect(reportManufacturerButton, &QPushButton::clicked, this, &GUI::reportManufacturer);
//	QObject::connect(undoButton, &QPushButton::clicked, this, [&]() {
//		try {
//			carsSrv.undo();
//			updateManufacturerButtons();
//			refreshCarsList(carsSrv.getAll());
//		}
//		catch (const RepositoryException& re) {
//			QMessageBox::warning(this, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//		}
//		});
//
//	for (auto button : manufButtons) {
//		QObject::connect(button, &QPushButton::clicked, this, [=]() {
//			for (const auto& entry : carsSrv.reportManufacturerCount()) {
//				if (entry.first == button->text().toStdString()) {
//					QMessageBox::information(this, "Manufacturer Count", QString::number(entry.second));
//				}
//			}
//			});
//	}
//
//	QObject::connect(washListButton, &QPushButton::clicked, this, &GUI::washListManagement);
//}
//
//void GUI::refreshCarsList(const vector<Car>& cars) {
//	carsList->clear();
//	for (const auto& car : cars) {
//		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(car.getRegNumber()));
//		carsList->addItem(item);
//	}
//}
//
//void GUI::updateManufacturerButtons() {
//	// check if manufacturers match buttons (delete, update)
//	auto manufacturerReport{ carsSrv.reportManufacturerCount() };
//	for (auto it = manufButtons.begin(); it < manufButtons.end(); it++) {
//		QPushButton* button = *it;
//		if (manufacturerReport.find((*it)->text().toStdString()) == manufacturerReport.end()) {
//			manufButtons.erase(it);
//			delete button;
//			break;
//		}
//	}
//	// check if buttons match manufacturers (store)
//	for (const auto& entry : manufacturerReport) {
//		auto manufacturer{ entry.first };
//		auto count{ entry.second };
//		bool found{ false };
//		for (auto it = manufButtons.begin(); it < manufButtons.end(); it++) {
//			if (manufacturer == (*it)->text().toStdString()) {
//				found = true;
//				break;
//			}
//		}
//		if (!found) {
//			QPushButton* button = new QPushButton(QString::fromStdString(manufacturer));
//			manufButtons.push_back(button);
//			manufLayout->addWidget(button);
//			QObject::connect(button, &QPushButton::clicked, this, [=]() {
//				for (const auto& pair : carsSrv.reportManufacturerCount()) {
//					if (pair.first == button->text().toStdString()) {
//						QMessageBox::information(this, "Manufacturer Count", QString::number(pair.second));
//					}
//				}
//				});
//		}
//	}
//}
//
//void GUI::storeCar() {
//	try {
//		carsSrv.storeCar(regNumberText->text().toStdString(), manufacturerText->text().toStdString(), modelText->text().toStdString(), typeText->text().toStdString());
//		updateManufacturerButtons();
//		refreshCarsList(carsSrv.getAll());
//		regNumberText->setText("");
//		manufacturerText->setText("");
//		modelText->setText("");
//		typeText->setText("");
//	}
//	catch (const ValidationException& ve) {
//		QMessageBox::warning(this, "Validation Error", QString::fromStdString(ve.getErrorMsg()));
//	}
//	catch (const RepositoryException& re) {
//		QMessageBox::warning(this, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//	}
//}
//
//void GUI::findCar() {
//	try {
//		Car car{ carsSrv.findCarByRegistrationNumber(regNumberText->text().toStdString()) };
//		QMessageBox::information(this, "Found Car", QString::fromStdString(car.toString()));
//	}
//	catch (const RepositoryException& re) {
//		QMessageBox::warning(this, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//	}
//}
//
//void GUI::deleteCar() {
//	try {
//		carsSrv.deleteCar(regNumberText->text().toStdString());
//		updateManufacturerButtons();
//		refreshCarsList(carsSrv.getAll());
//	}
//	catch (const RepositoryException& re) {
//		QMessageBox::warning(this, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//	}
//}
//
//void GUI::updateCar() {
//	try {
//		carsSrv.updateCar(regNumberText->text().toStdString(), manufacturerText->text().toStdString(), modelText->text().toStdString(), typeText->text().toStdString());
//		updateManufacturerButtons();
//		refreshCarsList(carsSrv.getAll());
//		regNumberText->setText("");
//		manufacturerText->setText("");
//		modelText->setText("");
//		typeText->setText("");
//	}
//	catch (const ValidationException& ve) {
//		QMessageBox::warning(this, "Validation Error", QString::fromStdString(ve.getErrorMsg()));
//	}
//	catch (const RepositoryException& re) {
//		QMessageBox::warning(this, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//	}
//}
//
//void GUI::filterByManufacturer() {
//	QWidget* window = new QWidget();
//	QVBoxLayout* windowLayout = new QVBoxLayout();
//	window->setLayout(windowLayout);
//	QWidget* substring = new QWidget();
//	QHBoxLayout* substringLayout = new QHBoxLayout();
//	substring->setLayout(substringLayout);
//	QLabel* substringLabel = new QLabel("Manufacturer to filter by: ");
//	substringLayout->addWidget(substringLabel);
//	QLineEdit* substringText = new QLineEdit();
//	substringLayout->addWidget(substringText);
//	QPushButton* okButton = new QPushButton("Ok");
//	windowLayout->addWidget(substring);
//	windowLayout->addWidget(okButton);
//	window->show();
//	QObject::connect(okButton, &QPushButton::clicked, this, [=]() {
//		QWidget* filtered = new QWidget();
//		QHBoxLayout* filteredLayout = new QHBoxLayout();
//		filtered->setLayout(filteredLayout);
//		QListWidget* filteredItems = new QListWidget();
//		filteredLayout->addWidget(filteredItems);
//		for (const auto& car : carsSrv.filterByManufacturer(substringText->text().toStdString())) {
//			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(car.toString()));
//			filteredItems->addItem(item);
//		}
//		filtered->show();
//		delete window;
//		});
//}
//
//void GUI::filterByType() {
//	QWidget* window = new QWidget();
//	QVBoxLayout* windowLayout = new QVBoxLayout();
//	window->setLayout(windowLayout);
//	QWidget* substring = new QWidget();
//	QHBoxLayout* substringLayout = new QHBoxLayout();
//	substring->setLayout(substringLayout);
//	QLabel* substringLabel = new QLabel("Type to filter by:");
//	substringLayout->addWidget(substringLabel);
//	QLineEdit* substringText = new QLineEdit();
//	substringLayout->addWidget(substringText);
//	windowLayout->addWidget(substring);
//	QPushButton* okButton = new QPushButton("Ok");
//	windowLayout->addWidget(okButton);
//	window->show();
//	QObject::connect(okButton, &QPushButton::clicked, this, [=]() {
//		QWidget* filtered = new QWidget();
//		QHBoxLayout* filteredLayout = new QHBoxLayout();
//		filtered->setLayout(filteredLayout);
//		QListWidget* filteredItems = new QListWidget();
//		filteredLayout->addWidget(filteredItems);
//		for (const auto& car : carsSrv.filterByType(substringText->text().toStdString())) {
//			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(car.toString()));
//			filteredItems->addItem(item);
//		}
//		filtered->show();
//		delete window;
//		});
//}
//
//void GUI::reportManufacturer() {
//	QWidget* window = new QWidget();
//	QHBoxLayout* windowLayout = new QHBoxLayout();
//	window->setLayout(windowLayout);
//	QListWidget* report = new QListWidget();
//	for (const auto& entry : carsSrv.reportManufacturerCount()) {
//		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(entry.first) + ": " + QString::number(entry.second));
//		report->addItem(item);
//	}
//	report->show();
//}
//
//void GUI::washListManagement() {
//	washListWindow = new QWidget();
//	QHBoxLayout* washListLayout = new QHBoxLayout();
//	washListWindow->setLayout(washListLayout);
//
//	// List Widget
//	QWidget* listWidget = new QWidget();
//	QVBoxLayout* listLayout = new QVBoxLayout();
//	listWidget->setLayout(listLayout);
//	washList = new QListWidget();
//	listLayout->addWidget(washList);
//	refreshWashListButton = new QPushButton("Refresh");
//	listLayout->addWidget(refreshWashListButton);
//	washListLayout->addWidget(listWidget);
//
//	// Edit Wash List Widget
//	QWidget* editWashListWidget = new QWidget();
//	QVBoxLayout* editWashListLayout = new QVBoxLayout();
//	editWashListWidget->setLayout(editWashListLayout);
//	emptyWashListButton = new QPushButton("Empty Wash List");
//	editWashListLayout->addWidget(emptyWashListButton);
//
//	QWidget* addWashListWidget = new QWidget();
//	QHBoxLayout* addWashListLayout = new QHBoxLayout();
//	addWashListWidget->setLayout(addWashListLayout);
//	washListRegNumberLabel = new QLabel("Registration number:");
//	addWashListLayout->addWidget(washListRegNumberLabel);
//	washListRegNumberText = new QLineEdit();
//	addWashListLayout->addWidget(washListRegNumberText);
//	washListAddButton = new QPushButton("Add to Wash List");
//	addWashListLayout->addWidget(washListAddButton);
//	editWashListLayout->addWidget(addWashListWidget);
//
//	QWidget* generateCarsWidget = new QWidget();
//	QHBoxLayout* generateCarsLayout = new QHBoxLayout();
//	generateCarsWidget->setLayout(generateCarsLayout);
//	generateCarsLabel = new QLabel("Number of cars to generate:");
//	generateCarsLayout->addWidget(generateCarsLabel);
//	generateCarsText = new QLineEdit();
//	generateCarsLayout->addWidget(generateCarsText);
//	generateCarsButton = new QPushButton("Generate Wash List");
//	generateCarsLayout->addWidget(generateCarsButton);
//	editWashListLayout->addWidget(generateCarsWidget);
//
//	QWidget* exportWashListWidget = new QWidget();
//	QHBoxLayout* exportWashListLayout = new QHBoxLayout();
//	exportWashListWidget->setLayout(exportWashListLayout);
//	exportWashListLabel = new QLabel("HTML file name:");
//	exportWashListLayout->addWidget(exportWashListLabel);
//	exportWashListText = new QLineEdit();
//	exportWashListLayout->addWidget(exportWashListText);
//	exportWashListButton = new QPushButton("Export to File");
//	exportWashListLayout->addWidget(exportWashListButton);
//	editWashListLayout->addWidget(exportWashListWidget);
//
//
//	washListLayout->addWidget(editWashListWidget);
//	washListWindow->show();
//
//	connectSignalsSlotsWashList();
//	refreshWashList(carsSrv.getWashList());
//}
//
//void GUI::refreshWashList(const vector<Car>& cars) {
//	washList->clear();
//	for (const auto& car : cars) {
//		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(car.getRegNumber()));
//		washList->addItem(item);
//	}
//}
//
//void GUI::connectSignalsSlotsWashList() {
//	QObject::connect(refreshWashListButton, &QPushButton::clicked, this, [&]() {
//		refreshWashList(carsSrv.getWashList());
//		});
//	QObject::connect(emptyWashListButton, &QPushButton::clicked, this, [&]() {
//		carsSrv.emptyWashList();
//		refreshWashList(carsSrv.getWashList());
//		});
//	QObject::connect(washListAddButton, &QPushButton::clicked, this, [&]() {
//		try {
//			carsSrv.addToWashList(washListRegNumberText->text().toStdString());
//			refreshWashList(carsSrv.getWashList());
//		}
//		catch (const RepositoryException& re) {
//			QMessageBox::warning(washListWindow, "Repository Error", QString::fromStdString(re.getErrorMsg()));
//		}
//		});
//QObject:connect(generateCarsButton, &QPushButton::clicked, this, [&]() {
//	carsSrv.generateWashList(generateCarsText->text().toInt());
//	refreshWashList(carsSrv.getWashList());
//	});
//QObject::connect(exportWashListButton, &QPushButton::clicked, this, [&]() {
//	try {
//		carsSrv.exportWashListToFile(exportWashListText->text().toStdString());
//		exportWashListText->setText("");
//	}
//	catch (const FileException& fe) {
//		QMessageBox::warning(washListWindow, "File Error", QString::fromStdString(fe.getErrorMsg()));
//	}
//	});
//}
