#pragma once
#include "FileUserRepo.h"

class HTMLWatchList : public FileUserRepo
{
public:
	HTMLWatchList(const string& filename) : FileUserRepo{ filename } {}
	~HTMLWatchList() {}

	void writeToFile() override;
	void displayWatchlist() override;
};