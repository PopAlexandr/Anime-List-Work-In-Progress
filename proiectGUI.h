#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_proiectGUI.h"

class proiectGUI : public QMainWindow
{
    Q_OBJECT

public:
    proiectGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::proiectGUIClass ui;
};
