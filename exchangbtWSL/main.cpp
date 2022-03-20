#include <iostream>
#include "exchange.h"
#include <string>
#include <fstream>

int main(int argc, char **argv) {
    using std::cout;
    using std::cin;

    if(argc == 2) {
        exchange ex(argv[1]);
        ex.copytosingleFile(argv[1]);
    }

    return 0;
}