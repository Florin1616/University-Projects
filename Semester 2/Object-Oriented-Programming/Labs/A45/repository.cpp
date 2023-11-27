#include "repository.h"

Repository::Repository() 
{

}

void Repository::initialiseRepo() {
	Movie movie1("The Shawshank Redemption", "Drama", "https://www.youtube.com/watch?v=6hB3S9bIaco", 1994, 1500);
	Movie movie2("The Godfather", "Crime", "https://www.youtube.com/watch?v=sY1S34973zA", 1972, 1300);
	Movie movie3("The Dark Knight", "Action", "https://www.youtube.com/watch?v=EXeTwQWrcwY", 2008, 1700);
	Movie movie4("12 Angry Men", "Drama", "https://www.youtube.com/watch?v=fSG38tk6TpI", 1957, 900);
	Movie movie5("Schindler's List", "Drama", "https://www.youtube.com/watch?v=gG22XNhtnoY", 1993, 1200);
	Movie movie6("The Lord of the Rings: The Return of the King", "Adventure", "https://www.youtube.com/watch?v=r5X-hFf6Bwo", 2003, 2000);
	Movie movie7("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", 1994, 1500);
	Movie movie8("The Good, the Bad and the Ugly", "Western", "https://www.youtube.com/watch?v=WCN5JJY_wiA", 1966, 800);
	Movie movie9("Fight Club", "Drama", "https://www.youtube.com/watch?v=qtRKdVHc-cE", 1999, 1400);
	Movie movie10("Forrest Gump", "Drama", "https://www.youtube.com/watch?v=bLvqoHBptjg", 1994, 1600);
	this->movies.addElem(movie1);
	this->movies.addElem(movie2);
	this->movies.addElem(movie3);
	this->movies.addElem(movie4);
	this->movies.addElem(movie5);
	this->movies.addElem(movie6);
	this->movies.addElem(movie7);
	this->movies.addElem(movie8);
	this->movies.addElem(movie9);
	this->movies.addElem(movie10);
}

void Repository::addMovieRepo(const Movie& movie) {
	this->movies.addElem(movie);
}

int Repository::getCapacityRepo() {
	return this->movies.getCapacity();
}

int Repository::getSizeRepo() {
	return this->movies.getSize();
}

void Repository::deleteMovieRepo(int index) {
	this->movies.deleteElem(index);
}

void Repository::updateMovieRepo(int index, const Movie& new_movie) {
	this->movies.updateElem(index, new_movie);
}

Repository::~Repository() {

}

int Repository::findByName(string title) {
	int searched_index = -1;
	int index = 0;
	int length = this->getSizeRepo();
	while (index < length && searched_index == -1) {
		Movie randomMovie = this->movies.getAll()[index];
		string TitleOfRandomMovie = randomMovie.getTitle();
		if (TitleOfRandomMovie == title)
			searched_index = index;
		index++;
	}
	return searched_index;
}
DynamicVector<Movie> Repository::getAllRepo() {
	return this->movies;
}