#ifndef __EXCHANGE_H
#define __EXCHANGE_H
#include <string>
using namespace std;

class exchange {

    public:
        exchange(char *filePath);
        ~exchange() {};
        bool copytosingleFile();
        bool copyfromsingleFile();

    private:
        string TargetDirPath;
        string DestFilePath;
        string TargetFilePath;
};


#endif