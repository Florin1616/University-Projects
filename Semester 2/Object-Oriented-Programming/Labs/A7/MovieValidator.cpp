#include "MovieValidator.h"

void MovieValidator::validate(Movie movie) {
	vector<string> errors;
	if (movie.getTitle() == "") 
		errors.push_back("The title is empty");
	
	if (movie.getGenre() == "")
		errors.push_back("The genre is empty");
	
	if (movie.getYearOfRelease() < 1800 || movie.getYearOfRelease() > 2023)
		errors.push_back("The year is not valid");

	if (movie.getNrOfLikes() <= 0) 
		errors.push_back("The number of likes is not valid");

	if (movie.getTrailer() == "")
		errors.push_back("The link is empty");

	size_t https = movie.getTrailer().find("https:");
	if (https != 0)
		errors.push_back("The link is not valid");

	if (errors.size() > 0)
		throw MovieException(errors);
	


}	