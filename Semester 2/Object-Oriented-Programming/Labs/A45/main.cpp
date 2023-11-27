#define _CRTDBG_MAP_ALLOC
#include "domain.h"
#include "dynamicarray.h"
#include "repository.h"
#include "service.h"
#include "ui.h"
#include "tests.h"
#include <crtdbg.h>

void run() {
	Ui ui;
	ui.start();
}

int main() {
	/*auto* dynamicVector = new DynamicVector<Movie>(10);
	auto* repo = new Repository(dynamicVector);
	repo->initialiseRepo();
	auto* service = new Service(repo);
	auto* ui = new Ui(service);
	ui->start();*/
	//testAll();
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}