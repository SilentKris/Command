#include <iostream>
#include "exchange.h"
#include <string>
#include <fstream>

int main(int argc, char **argv) {
    using std::cout;
    using std::cin;
    bool ret = true;

    if(argc == 3) {
        exchange ex(argv[2]);
        string option(argv[1]);

        if("to" == option) {
            cout << "Translating file: " << argv[2] << " to Share folder\n";
            ret = ex.copytosingleFile();
        }
        else if("from" == option) {
            cout << "Translating file: " << argv[2] << " from Share folder\n";
            ret = ex.copyfromsingleFile();
            cout << ret << endl;
        }
        else {
            cout << "Usage: exc [to/from] [filename]" << endl;
            return -1;
        }
    }else {
        cout << "Usage: exc [to/from] [filename]" << endl;
        return -1;
    }

    if(ret)
        cout << "Finished translate!" << endl;
    else
        cout << "Failed to translate!!!" << endl;
    return 0;
}