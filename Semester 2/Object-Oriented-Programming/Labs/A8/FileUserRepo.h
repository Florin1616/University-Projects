#pragma once
#include "UserRepo.h"

class FileUserRepo : public UserRepository
{
protected:
	string filename;
public:
	FileUserRepo(const string& filename) {
		this->filename = filename;
	}
	virtual ~FileUserRepo() {};

	virtual void writeToFile() = 0;
	virtual void displayWatchlist() = 0;
};
