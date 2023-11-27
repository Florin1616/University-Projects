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

bool MovieValidator::checkForDigits(std::string stringToCheck)
{
	for (auto character : stringToCheck)
	{
		if (isdigit(character) == false)
			return 0;
	}
	return 1;
}


void MovieValidator::validate_genre(string genre)
{
	if (genre.find_first_of("0123456789") != std::string::npos)
		throw MovieException(std::vector<std::string>{ "The genre name cannot contain numbers!\n" });
}

void MovieValidator::validate_year(string year_of_release)
{
	if (stoi(year_of_release) < 1900)
		throw MovieException(std::vector<std::string>{ "The year of release cannot be less than 1900!\n" });
}

void MovieValidator::validate_likes(string likes)
{
	if (checkForDigits(likes) == false)
		throw MovieException(std::vector<std::string>{ "The number of likes must be a number!\n" });
	if (stoi(likes) < 0)
		throw MovieException(std::vector<std::string>{ "The number of likes cannot be negative!\n" });
}