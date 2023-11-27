#pragma once
#include "user_repo.h"
#include "repository.h"
class UserService {
	private:
		UserRepo userRepo;
		Repository repo;
	public:	
		UserService();
		~UserService();
		DynamicVector<Movie> getAllUserService();
		void addUserService(Movie movie);
		DynamicVector<Movie> listMoviesByGenre(DynamicVector<Movie> validMovies, string givenGenre, DynamicVector<Movie> repo);
		bool deleteMovieFromWatchlist(string title);
 };
