#pragma once
#include <vector>
#include "Domain.h"


//class Repository {
//
//private:
//	std::vector<Movie> dynamicArray;
//
//public:
//
//	Repository();
//	~Repository();
//
//	void add_ten_entries_Repo();
//	std::vector<Movie>& get_all_Repo();
//
//	int get_size_Repo();
//
//	void add_movie_Repo(const Movie&);
//	void delete_movie_Repo(int);
//	void update_movie_Repo(int, const Movie&);
//};


class Repository {
private:
	vector<Movie> movies;
public:
	Repository();
	~Repository();

	void generateEntries();
	vector<Movie>& getAllRepo();
	
	int getSizeRepo();
	void addRepo(const Movie& movie);
	void removeRepo(int index);
	void updateRepo(int index, const Movie& newMovie);
	int findByTitle(string title);
	void initialiseRepo();

};