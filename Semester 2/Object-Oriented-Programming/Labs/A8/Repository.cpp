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
	this->writeToFile();
}

void Repository::removeRepo(int delete_index) {
	if (delete_index == -1) {
		string error;
		error += string("\nThe movies does not exist!\n");
		if (!error.empty())
			throw RepositoryException(error);
	}

	else {
		this->movies.erase(this->movies.begin() + delete_index);
		this->writeToFile();
	}
}

void Repository::updateRepo(int update_index, const Movie& new_movie) {
	if (update_index == -1) {
		string error;
		error += string("\nThe movies does not exist!\n");
		if (!error.empty())
			throw RepositoryException(error);
	}
	else {
		this->movies[update_index] = new_movie;
		this->writeToFile();
	}
}

int Repository::findByTitle(string title) {
	/*int searched_index = -1;
	int index = 0;
	int length = this->getSizeRepo();
	while (index < length && searched_index == -1)
	{
		if (this->movies[index].getTitle() == title)
			searched_index = index;
		index++;
	}
	return searched_index;*/
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

void Repository::initialiseRepo()
{
	this->readFromFile();
}

void Repository::readFromFile() {
	//ifstream file(filePath.c_str());
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


//void Repository::writeToFile(string filename) {
//	ofstream file(filename);
//	if (!file.is_open())
//		throw exception("The file could not be opened!");
//	for (auto it = movies.begin(); it != movies.end(); ++it)
//	{
//		file << *it;
//		if (it != movies.end() - 1)
//			file << "\n";
//	}
//	file.close();
//}

void Repository::writeToFile() {
	ofstream file(this->movie_filename);
	if (!file.is_open())
		throw exception("The file could not be opened!");

	auto lastMovie = movies.end() - 1;
	for (auto it = movies.begin(); it != movies.end(); ++it)
	{
		file << *it;	
		if (it != lastMovie)
			file << "\n";
	}
	file.close();
}

