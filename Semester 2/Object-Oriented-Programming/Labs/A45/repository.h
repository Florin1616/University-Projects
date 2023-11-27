#pragma once
#include "dynamicarray.h"
#include "domain.h"
class Repository {
private:
	DynamicVector<Movie> movies ;
public:
	Repository();
	~Repository();

	void initialiseRepo();
	void addMovieRepo(const Movie& movie);
	void updateMovieRepo(int update_index,const Movie& new_movie);
	void deleteMovieRepo(int delete_index);
	int findByName(string name);
	int getCapacityRepo();
	int getSizeRepo();
	DynamicVector<Movie> getAllRepo();
};