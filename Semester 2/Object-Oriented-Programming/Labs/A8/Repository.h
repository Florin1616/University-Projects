#pragma once
#include <vector>
#include "Domain.h"


class Repository {
private:
	vector<Movie> movies;
	string movie_filename;
public:
	//Repository();
	Repository(string& filename);
	~Repository();

	//void generateEntries();
	vector<Movie>& getAllRepo();

	int getSizeRepo();
	void addRepo(Movie& movie);
	void removeRepo(int index);
	void updateRepo(int index, const Movie& newMovie);
	int findByTitle(string title);
	void initialiseRepo();

	void readFromFile();
	void writeToFile();

};


