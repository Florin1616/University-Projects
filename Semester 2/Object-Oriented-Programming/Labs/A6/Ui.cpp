#include "Ui.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


constexpr auto ADMIN_MODE = "1";
constexpr auto USER_MODE = "2";
constexpr auto EXIT_NUMBER = "0";

constexpr auto LIST_MOVIES_ADMIN = "1";
constexpr auto ADD_MOVIE_ADMIN = "2";
constexpr auto DELETE_MOVIE_ADMIN = "3";
constexpr auto UPDATE_MOVIE_ADMIN = "4";

constexpr auto START_WATCHLIST = "1";
constexpr auto DELETE_MOVIE_WATCHLIST = "2";
constexpr auto VIEW_WATCHLIST = "3";

Ui::Ui()
{
}

Ui::~Ui()
{
}

void Ui::printAdminMenu() {
	cout << "----------------Admin Menu---------------" << endl;
	cout << "1. List all the movies from the datanbase" << endl;
	cout << "2. Add a new movie to the database" << endl;
	cout << "3. Remove a movie from the database" << endl;
	cout << "4. Update an existing movie from the database" << endl;
	cout << "0. Exit the program" << endl;
	cout << "Choose an option: " << endl;
}

void Ui::printUserMenu() {
	cout << "-------User Menu----------" << endl;
	cout << "0. Exit" << endl;
	cout << "1. View all the movies from the database of a given genre, one by one. If the genre is empty all movies will be viewed:" << endl;
	cout << "2. Delete a movie from the watch list" << endl;
	cout << "3. View the watch list " << endl;
	cout << "Choose an option: " << endl;
}

void Ui::printMainMenu() {
	cout << "----MAIN MENU----" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Administrator mode. " << endl;
	cout << "2. User Mode" << endl;
	cout << "Choose your option: " << endl;
}

bool Ui::validateString(string input) {
	for (int i = 0; i < input.length(); i++)
		if (isdigit(input[i]) != false)
			return false;
	return true;
}


void Ui::listAllElements() {
	vector <Movie> movie_list = this->service.getAllService();
	int numberOfMovies = this->service.getSizeService();
	if (numberOfMovies == 0)
		cout << "No movies in the database!" << endl;

	for (auto& movie : movie_list)
	{
		cout << movie.toString() << "\n";
	}
}


void Ui::addElemUi() {
	string newTitle;
	string newGenre;
	string newYearOfRelease;
	string newNumberOfLikes;
	string trailer;
	cout << "Introduce the title of the movie: " << endl;
	getline(cin, newTitle);
	if ((!validateString(newTitle)) || (newTitle.length() == 0))
		throw"The title you entered is not valid";
	cout << "Introduce the genre of the movie: " << endl;
	getline(cin, newGenre);
	if ((!validateString(newGenre)) || (newGenre.length() == 0))
		throw"The genre you entered is not valid";
	cout << "Introduce the trailer link: " << endl;
	getline(cin, trailer);
	if (trailer.length() == 0 || trailer.find("www") == string::npos)
		throw "The trailer you introduced is not valid!";
	cout << "Introduce the release year of the movie: " << endl;
	getline(cin, newYearOfRelease);
	int yearOfReleaseInteger;
	if (!validateString(newYearOfRelease) && newYearOfRelease.length() != 0)
		yearOfReleaseInteger = stoi(newYearOfRelease);
	else {
		throw "The year of release you introduced is not valid! ";
	}
	if (yearOfReleaseInteger < 1900 || yearOfReleaseInteger > 2023)
		throw "Year of release must be between 1900 and 2023";
	cout << "Introduce the number of likes for the movie: " << endl;
	getline(cin, newNumberOfLikes);
	int numberrOfLikesInteger;
	if (!validateString(newNumberOfLikes) && newNumberOfLikes.length() != 0)
		numberrOfLikesInteger = stoi(newNumberOfLikes);
	else {
		throw "Number of likes is not valid!";
	}
	if (numberrOfLikesInteger < 0)
		throw "Number of likes cannot be smaller than 0";
	int was_added_successfully = this->service.addService(newTitle, newGenre, trailer, yearOfReleaseInteger, numberrOfLikesInteger);
	if (was_added_successfully == 1)
		throw "This movie already is in the database!";
	else if (was_added_successfully == 0)
		cout << "Movie added with success!" << endl;
}


void Ui::removeElemUi() {
	string delete_title;
	cout << "Type the title of the movie you want to delete from the database: " << endl;
	getline(cin, delete_title);
	if(!validateString(delete_title) || delete_title.length() == 0)
		throw"The title you introduced is not valid!";
	int wasRemovedSuccesfully = this->service.removeService(delete_title);
	if (wasRemovedSuccesfully == 0)
		cout << "The movie was removed succesfully!" << endl;
	else
		cout << "The movie you introduced does not exist in our databases!" << endl;

}


void Ui::updateElemUi() {
	string oldTitle;
	string newTitle;
	string newGenre;
	string newYearOfReleaseString;
	string newNumberOfLikesString;
	string newTrailer;
	cout << "Introduce the old title of the movie:" << endl;
	getline(cin, oldTitle);
	if (!validateString(oldTitle) || oldTitle.length() == 0)
		throw "The title you introduced is not valid";
	cout << "Introduce the new title: " << endl;
	getline(cin, newTitle);
	if (!validateString(newTitle) || newTitle.length() == 0)
		throw "The title you introduced is not valid!";
	cout << "Introduce the new genre" << endl;
	getline(cin, newGenre);
	if (!validateString(newGenre) || newGenre.length() == 0)
		throw "The genre you introduced is not valid";
	cout << "Introduce the year of release:" << endl;
	getline(cin, newYearOfReleaseString);
	int yearOfRelease;
	if (!validateString(newYearOfReleaseString) && newYearOfReleaseString.length() != 0)
		yearOfRelease = stoi(newYearOfReleaseString);
	else {
		throw "Year of release is not valid!";
	}
	if (yearOfRelease < 1900 || yearOfRelease > 2023)
		throw "Year of release cannot be before 1900 or after 2023";
	cout << "Introduce the number of likes for the movie:" << endl;
	getline(cin, newNumberOfLikesString);
	int numberOfLikes;
	if (!validateString(newNumberOfLikesString) && newNumberOfLikesString.length() != 0)
		numberOfLikes = stoi(newNumberOfLikesString);
	else {
		throw "Number of likes is not valid!";
	}
	if (numberOfLikes < 0)
		throw "Number of likes cannot be smaller than 0";
	cout << "Type the trailer link: " << endl;
	getline(cin, newTrailer);
	if (newTrailer.length() == 0 || newTrailer.find("www") == string::npos)
		throw "The trailer you introduced is not valid! ";
	int was_updated_successfully = this->service.updateService(oldTitle, newTitle, newGenre, newTrailer, numberOfLikes, yearOfRelease);
	if (was_updated_successfully == -1)
		throw "The movie does not exist!";
	else if (was_updated_successfully == 0)
		cout << "Movie was updated successfully!" << endl;
}



void Ui::startWatchList() {
	cout << "Select a genre: " << endl;
	string selectedGenre;
	string choice;
	getline(cin, selectedGenre);
	if (selectedGenre == "\0") {
		bool done = false;
		int index = 0;
		int length = this->service.getSizeService();
		if (length == 0)
			throw "There are no movies in the database";
		while (!done) {
			if (length == 0)
				throw "There are no movies remaining";
			if (index == length)
				index = 0;

			cout<<this->service.getAllService()[index].toString()<<endl;
			cout << "Add to watch list? [Yes / No / Exit]" << endl;
			string link = string("start ").append(this->service.getAllService()[index].getTrailer());
			system(link.c_str());
			getline(cin, choice);
			if (choice == "Yes") {
				Movie movie = this->service.getAllService()[index];
				this->userService.addUserService(movie);
				length = this->service.getSizeService();
				index++;
			}
			else if (choice == "No") {
				index++;
			}
			else if (choice == "Exit") {
				done = true;
			}
			if (length == 0)
				done = true;
		}
	}
	else {
		if (!validateString(selectedGenre))
			throw "The genre you introduced is not valid";
		vector<Movie> validMovies;
		validMovies = this->userService.listMoviesByGenre(validMovies, selectedGenre, this->service.getAllService());
		int length = validMovies.size();
		if (length == 0)
			throw "There are no movies with the selected genre";
		string choice;
		bool done = false;
		int index = 0;
		while (!done) {
			if (length == 0) {
				cout << "No more movies remaining! " << endl;
				break;
			}
			if (index == length)
				index = 0;

			cout<<validMovies[index].toString()<<endl;
			cout << "Add to watch list? [Yes / No / Exit]" << endl;

			string link = string("start ").append(validMovies[index].getTrailer());
			system(link.c_str());

			getline(cin, choice);
			if (choice == "Yes") {
				Movie movie = validMovies[index];
				this->userService.addUserService(movie);
				validMovies.erase(validMovies.begin() + index);
				length--;
			}
			else if (choice == "No")
				index++;
			else if (choice == "Exit")
				done = true;

		}
	}
}


void Ui::listAllUser() {
	vector<Movie> watchList = this->userService.getAllUserService();
	int length = watchList.size();
	if (length == 0)
		throw "There are no movies in the watch list";
	//print all the movies from the watch list using C++11 range-based for loop

	for (auto& movie : watchList)
		cout << movie.toString() << endl;
}


void Ui::deleteMovieFromWatchlist() {
	cout << "Remove a movie from the watch list" << endl;
	string title;
	string like;
	cout << "Introduce the title of the movie you want to remove: ";
	getline(cin, title);
	if (!validateString(title) || title.length() == 0)
		throw "the title you introduced is not valid";
	cout << "do you want to like the movie? [yes / no]" << endl;
	getline(cin, like);
	bool removed = this->userService.deleteMovieFromWatchlist(title);
	if (like == "yes")
		this->service.updateLikesService(title);
	if (removed == true)
		cout << "The movie was removed from the watch list" << endl;
	else
		cout << "The movie could not be removed from the watch list" << endl;
}



void Ui::AdminMode() {
	cout << "Admin mode" << endl;
	bool done = false;
	while (!done) {
		try {
			printAdminMenu();
			string option;
			getline(cin, option);
			if (option == LIST_MOVIES_ADMIN)
				listAllElements();
			else if (option == ADD_MOVIE_ADMIN)
				addElemUi();
			else if (option == DELETE_MOVIE_ADMIN)
				removeElemUi();
			else if (option == UPDATE_MOVIE_ADMIN)
				updateElemUi();
			else if (option == EXIT_NUMBER) {
				done = true;
				cout << "Bye!" << endl;
			}
			else
				cout << "wrong input!" << endl;
		}
		catch (const char* message) {
			cout << message << endl;
		}
		catch (const exception& exception) {
			cerr << exception.what();
			cout << endl;
		}
	}
}


void Ui::UserMode() {
	cout << "User mode" << endl;
	bool done = false;

	while (!done) {
		try {
			printUserMenu();
			string option;
			getline(cin, option);
			if (option == START_WATCHLIST)
				startWatchList();
			else if (option == DELETE_MOVIE_WATCHLIST)
				deleteMovieFromWatchlist();
			else if (option == VIEW_WATCHLIST)
				listAllUser();
			else if (option == "0") {
				done = true;
				cout << "Bye!" << endl;
			}
			else
				cout << "Wrong input!" << endl;
		}
		catch (const char* message) {
			cout << message << endl;
		}
		catch (const exception& exception) {
			cerr << exception.what();
			cout << endl;
		}
	}
}

void Ui::start() {
	cout << "So many movies, so little time" << endl;
	bool done = false;
	this->service.initialiaseService();
	while (!done) {
		printMainMenu();
		string option;
		getline(cin, option);
		if (option == ADMIN_MODE)
			AdminMode();
		else if (option == USER_MODE)
			UserMode();
		else if (option == EXIT_NUMBER) {
			done = true;
			cout << "Bye" << endl;
		}
		else
			cout << "Wrong Input!" << endl;
	}
}