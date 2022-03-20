#ifndef __EXCHANGE_H
#define __EXCHANGE_H
#include <string>
using namespace std;

class exchange {

    public:
        exchange(char *filePath);
        ~exchange() {};
        void copytosingleFile(char *filePath);
        void copyfromsingleFile(char *filePath);

    private:
        string TargetDirPath;
        string TargetFilePath;
};


#endif