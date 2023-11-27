#include <crtdbg.h>
#include <stdio.h>
#include "main.h"
#include "ui.h"
#include "tests.h"

int main() {
    setbuf(stdout, NULL);
    start();
    _CrtDumpMemoryLeaks();
    testAll();
    return 0;
}