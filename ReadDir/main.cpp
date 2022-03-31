#include "rdir.h"
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    const string dirPath = "./";
    RDIR mdir(dirPath.data());
    mdir.getFileList();

    return 0;
}