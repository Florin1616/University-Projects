#include <iostream>
#include "Repository.h"
using namespace std;

class FakeRepo :public Repository
{
private:
	string filename;
public:
	
	bool movieInRepo;
	void set_bool_value(bool new_bool) {
		this->movieInRepo = new_bool;
	}
	FakeRepo(string& filename) :Repository(filename) {
		this->filename = filename;
		movieInRepo = false;
	}
	void addRepo(Movie& movie) override {
		if (movieInRepo == true)
			throw exception("Duplicate Movie");
	}
};