#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MoviesQT.h"

class MoviesQT : public QMainWindow
{
    Q_OBJECT

public:
    MoviesQT(QWidget *parent = nullptr);
    ~MoviesQT();

private:
    Ui::MoviesQTClass ui;
};
