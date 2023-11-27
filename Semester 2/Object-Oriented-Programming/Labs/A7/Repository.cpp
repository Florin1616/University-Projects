#include "Repository.h"
#include "RepositoryExceptions.h"
#include <fstream>
#include <exception>
#include <string>
#include <iostream>
#include <sstream>
//Repository::Repository()
//{
//}

Repository::Repository(string& filename)
{
	this->movie_filename = filename;
}

Repository::~Repository()
{
}

void Repository::initialiseRepo()
{
	this->readFromFile();
}

//void Repository::initialiseRepo() {
//	Movie movie1("The Shawshank Redemption", "Drama", "https://www.youtube.com/watch?v=6hB3S9bIaco", 1994, 1500);
//	Movie movie2("The Godfather", "Crime", "https://www.youtube.com/watch?v=sY1S34973zA", 1972, 1300);
//	Movie movie3("The Dark Knight", "Action", "https://www.youtube.com/watch?v=EXeTwQWrcwY", 2008, 1700);
//	Movie movie4("12 Angry Men", "Drama", "https://www.youtube.com/watch?v=fSG38tk6TpI", 1957, 900);
//	Movie movie5("Schindler's List", "Drama", "https://www.youtube.com/watch?v=gG22XNhtnoY", 1993, 1200);
//	Movie movie6("The Lord of the Rings: The Return of the King", "Adventure", "https://www.youtube.com/watch?v=r5X-hFf6Bwo", 2003, 2000);
//	Movie movie7("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", 1994, 1500);
//	Movie movie8("The Good, the Bad and the Ugly", "Western", "https://www.youtube.com/watch?v=WCN5JJY_wiA", 1966, 800);
//	Movie movie9("Fight Club", "Drama", "https://www.youtube.com/watch?v=qtRKdVHc-cE", 1999, 1400);
//	Movie movie10("Forrest Gump", "Drama", "https://www.youtube.com/watch?v=bLvqoHBptjg", 1994, 1600);
//
//	this->movies.push_back(movie1);
//	this->movies.push_back(movie2);
//	this->movies.push_back(movie3);
//	this->movies.push_back(movie4);
//	this->movies.push_back(movie5);
//	this->movies.push_back(movie6);
//	this->movies.push_back(movie7);
//	this->movies.push_back(movie8);
//	this->movies.push_back(movie9);
//	this->movies.push_back(movie10);
//}

vector<Movie>& Repository::getAllRepo() {

	return this->movies;
}


int Repository::getSizeRepo() {

	return this->movies.size();
}

void Repository::addRepo(Movie& movie_to_add) {
	if (findByTitle(movie_to_add.getTitle()) != -1)
		throw DuplicateMovieException();
	this->movies.push_back(movie_to_add);
}

void Repository::removeRepo(int delete_index) {
	this->movies.erase(this->movies.begin() + delete_index);
}

void Repository::updateRepo(int update_index, const Movie& new_movie) {
	this->movies[update_index] = new_movie;
}



int Repository::findByTitle(string title) {
	//int searched_index = -1;
	//int index = 0;
	//int length = this->getSizeRepo();
	//while (index < length && searched_index == -1)
	//{
	//	if (this->movies[index].getTitle() == title)
	//		searched_index = index;
	//	index++;
	//}
	//return searched_index;
	auto it = std::find_if(movies.begin(), movies.end(), [&](Movie movie) {
		return movie.getTitle() == title;
		});

	if (it != movies.end()) {
		return std::distance(movies.begin(), it);
	}
	else {
		return -1;
	}
}


void Repository::readFromFile() {
	ifstream file(this->movie_filename);

	if (file.peek() == EOF)
	{
		file.close();
		return;
	}

	do
	{
		Movie movie; 
		file >> movie;
		this->movies.push_back(movie);
	} while (!file.eof());

	file.close();
}


void Repository::writeToFile() {
	ofstream file(this->movie_filename);
	if (!file.is_open())
		throw exception("The file could not be opened!");
	for (auto it = movies.begin(); it != movies.end(); ++it)
	{
		file << *it;
		if (it != movies.end() - 1)
			file << "\n";
	}
	file.close();
}