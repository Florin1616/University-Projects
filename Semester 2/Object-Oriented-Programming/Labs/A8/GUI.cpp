#include "GUI.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include "RepositoryExceptions.h"
#include "MovieValidator.h"
using namespace std;

GUI::GUI(Service& s) : service {s}
{
	//this->service.readFromFile();
	this->initGUI();
	this->populateList();
	this->connectSignalsAndSlots();
}

void GUI::initGUI()
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	//Movie(string title = "empty", string genre = "empty", string trailer = "empty", int yearOfRelease = 0, int nrOfLikes = 0);

	this->moviesListWidget = new QListWidget();

	this->titleLineEdit = new QLineEdit();
	this->genreLineEdit = new QLineEdit();
	this->trailerLineEdit = new QLineEdit();
	this->releaseYearLineEdit = new QLineEdit();
	this->nrLikesLineEdit = new QLineEdit();


	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->clearButton = new QPushButton("Clear");


	mainLayout->addWidget(moviesListWidget);

	QFormLayout* formLayout = new QFormLayout();
	formLayout->addRow("Title: ", this->titleLineEdit);
	formLayout->addRow("Genre: ", this->genreLineEdit);
	formLayout->addRow("Trailer: ", this->trailerLineEdit);
	formLayout->addRow("Year: ", this->releaseYearLineEdit);
	formLayout->addRow("Likes: ", this->nrLikesLineEdit);

	mainLayout->addLayout(formLayout);

	QGridLayout* buttonsLayout = new QGridLayout();
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 0, 2);
	buttonsLayout->addWidget(this->clearButton, 0, 3);

	mainLayout->addLayout(buttonsLayout);

}

void GUI::populateList()
{
	moviesListWidget->clear();

	vector<Movie> movies = this->service.getAllService();

	for (auto& movie : movies)
	{
		moviesListWidget->addItem(QString::fromStdString(movie.getTitle()) + " | " + QString::fromStdString(movie.getGenre()) + " | " + QString::fromStdString(movie.getTrailer()) + " | " + QString::fromStdString(to_string(movie.getYearOfRelease())) + " | " + QString::fromStdString(to_string(movie.getNrOfLikes())));
		//moviesListWidget->addItem(QString::fromStdString(to_string(movie.getYearOfRelease()) + " | " + to_string(movie.getNrOfLikes())));
	}
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(moviesListWidget, &QListWidget::clicked, this, [&]() {
		int index = getSelectedIndex();

		if (index == -1) {
			this->titleLineEdit->clear();
			this->genreLineEdit->clear();
			this->releaseYearLineEdit->clear();
			this->nrLikesLineEdit->clear();
			this->trailerLineEdit->clear();
		}
		else {
			Movie movie = service.getAllService().at(index);

			titleLineEdit->setText(QString::fromStdString(movie.getTitle()));
			genreLineEdit->setText(QString::fromStdString(movie.getGenre()));
			trailerLineEdit->setText(QString::fromStdString(movie.getTrailer()));
			releaseYearLineEdit->setText(QString::fromStdString(to_string(movie.getYearOfRelease())));
			nrLikesLineEdit->setText(QString::fromStdString(to_string(movie.getNrOfLikes())));
		}
		});

	QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addMovie);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &GUI::deleteMovie);
	QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateMovie);
	QObject::connect(this->clearButton, &QPushButton::clicked, this, &GUI::clearFields);

}

int GUI::getSelectedIndex()
{
	QModelIndexList indexList = this->moviesListWidget->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		this->titleLineEdit->clear();
		this->genreLineEdit->clear();
		this->releaseYearLineEdit->clear();
		this->nrLikesLineEdit->clear();
		this->trailerLineEdit->clear();
		return -1;
	}

	int index = indexList.at(0).row();
	return index;
}

void GUI::clearFields() {
	this->titleLineEdit->clear();
	this->genreLineEdit->clear();
	this->releaseYearLineEdit->clear();
	this->nrLikesLineEdit->clear();
	this->trailerLineEdit->clear();
}

void GUI::addMovie()
{
	string title = titleLineEdit->text().toStdString();
	string genre = genreLineEdit->text().toStdString();
	string trailer = trailerLineEdit->text().toStdString();
	string yearString = releaseYearLineEdit->text().toStdString();
	string nrLikesString = nrLikesLineEdit->text().toStdString();


	if (title.empty() || genre.empty() || trailer.empty() || yearString.empty() || nrLikesString.empty())
	{
		QMessageBox::warning(this, "Warning", "Please fill in all the fields!");
		return;
	}

	try {
		this->service.validate_year(yearString);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}

	try {
		this->service.validate_likes(nrLikesString);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}
	try {
		this->service.validate_likes(nrLikesString);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}


	int yearOfRelease = stoi(yearString);
	int nrLikes = stoi(nrLikesString);


	try {

		this->service.addService(title, genre, trailer, yearOfRelease, nrLikes);
		this->populateList();
	}
	catch (MovieException& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.getErrors()[0]));

	}
	catch (RepositoryException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}

}

void GUI::deleteMovie()
{
	int index = getSelectedIndex();
	if (index == -1)
	{
		QMessageBox::critical(this, "Error", "No movie selected!");
		return;
	}


	string title = this->titleLineEdit->text().toStdString();
	string genre = this->genreLineEdit->text().toStdString();
	string trailer = this->trailerLineEdit->text().toStdString();
	string year_of_realease_string = this->releaseYearLineEdit->text().toStdString();
	string number_of_likes_string = this->nrLikesLineEdit->text().toStdString();


	try {
		this->service.validate_likes(year_of_realease_string);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}
	try {
		this->service.validate_likes(number_of_likes_string);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}


	if (index < 0 || index >= this->service.getAllService().size())
	{
		QMessageBox::critical(this, "Error", "No movie was selected!");
		return;
	}


	try
	{
		this->service.removeService(title);
		this->populateList();
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
	}
	catch (RepositoryException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}


}


void GUI::updateMovie() {

	int selectedIndex = getSelectedIndex();
	if (selectedIndex == -1)
	{
		QMessageBox::critical(this, "Error", "You have to select a movie!");
		return;
	}

	string title = titleLineEdit->text().toStdString();
	string genre = genreLineEdit->text().toStdString();
	string source = trailerLineEdit->text().toStdString();
	string year_of_release_string = this->releaseYearLineEdit->text().toStdString();
	string number_of_likes_string = this->nrLikesLineEdit->text().toStdString();


	try {
		this->service.validate_likes(year_of_release_string);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}
	try {
		this->service.validate_likes(number_of_likes_string);
	}
	catch (MovieException& e)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(e.getErrors()[0]));
		return;
	}



	int year_of_release = stoi(this->releaseYearLineEdit->text().toStdString());
	int nubmer_of_likes = stoi(this->nrLikesLineEdit->text().toStdString());

	if (selectedIndex < 0 || selectedIndex >= this->service.getAllService().size())
	{
		QMessageBox::critical(this, "Error", "No movie was selected!");
		return;
	}

	try {
		this->service.updateService(title, genre, source, year_of_release, nubmer_of_likes);
		this->populateList();
	}
	catch (MovieException& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.getErrors()[0]));
	}
	catch (RepositoryException &e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}
	
}
