#pragma once
#include <QWidget>
#include "Service.h"
#include <QListWidget>
#include <QPushButton>

class GUI : public QWidget
	
{	
private:
	Service& service;

	QListWidget* moviesListWidget;

	QLineEdit* titleLineEdit;

	QLineEdit* genreLineEdit;

	QLineEdit* trailerLineEdit;

	QLineEdit* releaseYearLineEdit;
	
	QLineEdit* nrLikesLineEdit;

	QPushButton* updateButton;

	QPushButton* addButton;

	QPushButton* deleteButton;
	
	QPushButton* clearButton;

	void initGUI();

	void populateList();

	void connectSignalsAndSlots();

	int getSelectedIndex();

	void addMovie();
	void deleteMovie();
	void updateMovie();
	void clearFields();
public:
	GUI(Service&);
};