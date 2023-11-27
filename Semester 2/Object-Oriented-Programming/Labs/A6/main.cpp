#include "ui.h"
#include "tests.h"
void run() {
	Ui ui;
	ui.start();
}

int main() {
	testAll();
	/*auto* dynamicVector = new DynamicVector<Movie>(10);
	auto* repo = new Repository(dynamicVector);
	repo->initialiseRepo();
	auto* service = new Service(repo);
	auto* ui = new Ui(service);
	ui->start();*/
	run();
	return 0;
}