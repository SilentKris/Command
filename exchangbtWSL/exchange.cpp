#include "exchange.h"
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

exchange::exchange(char *filePath) {
    char Lpath[] = "/mnt/c/Users/dingkris/Desktop/WSLshare";
    char Wpath[] = "C:\\Users\\dingkris\\Desktop\\WSLshare";
    TargetDirPath = Wpath;
    TargetFilePath = TargetDirPath + '\\' + filePath;
}

void exchange::copytosingleFile(char *filePath) {
    char byte[1024]; 

    open(filePath, );
    if(!fin.is_open()) {
        cout << "fout fin failed to open file" << endl;
        return;
    }

    fout.open(TargetFilePath, ios_base::out | ios_base::trunc | ios_base::binary);
    cout << TargetFilePath << endl;
    if(!fout.is_open()) {
        cout << "fout failed to open file" << endl;
        return;
    }

    while(!fin.eof()) {
        fin.read(byte, 1024);
        if(!fin.eof())
            fout.write(byte, 1024);
        cout << "translating..." << endl;
    }

    fin.close();
    fout.close();
}

void exchange::copyfromsingleFile(char *filePath) {
    ifstream fin;
    ofstream fout;
    char byte[1024]; 

    fin.open(TargetFilePath, ios_base::in | ios_base::binary);
    if(!fin.is_open()) {
        cerr << "failedto open file" << endl;
        return;
    }

    fout.open(filePath, ios_base::out | ios_base::trunc | ios_base::binary);

    while(!fin.eof()) {
        fin.read(byte, 1024);
        fout.write(byte, 1024);
    }

    fin.close();
    fout.close();
}