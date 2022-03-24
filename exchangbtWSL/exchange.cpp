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
    DestFilePath = filePath;
    TargetFilePath = TargetDirPath + '\\' + filePath;
}

bool exchange::copytosingleFile() {
    char byte[1024*1024]; 
    size_t readcount = -1;
    FILE *fdr = fopen(DestFilePath.data(), "rb");
    FILE *fdw = fopen(TargetFilePath.data(),"wb+");

    //debug
    cout << DestFilePath << endl;
    cout << TargetFilePath << endl;

    if(NULL == fdr) {
        cout << "Failed to open filePath: " << DestFilePath << endl;
        return false;
    }else if(NULL == fdw) {
        cout << "Failed to open Target file Path: " << TargetFilePath << endl;
        return false;
    }

    while(readcount) {
        readcount = fread(byte, 1, 1024*1024, fdr);
        fwrite(byte, 1, readcount, fdw);   
    }
    
    if(readcount == -1)
        return false;
    fclose(fdr);
    fclose(fdw);

    return true;
}

bool exchange::copyfromsingleFile() {
//    cout << "starting translate" << endl;
    char byte[1024*1024]; 
    size_t readcount = -1;
    FILE *fdr = fopen(TargetFilePath.data(), "rb");
    FILE *fdw = fopen(DestFilePath.data(),"wb+");
    //debug
    cout << DestFilePath << endl;
    cout << TargetFilePath << endl;

    if(NULL == fdr) {
        cout << "Failed to open filePath: " << DestFilePath << endl;
        return false;
    }else if(NULL == fdw) {
        cout << "Failed to open Target file Path: " << TargetFilePath << endl;
        return false;
    }

    while(readcount) {
        readcount = fread(byte, 1, 1024*1024, fdr);
        cout << 
        fwrite(byte, 1, readcount, fdw);   
    }
    if(readcount == -1)
        return false;
    fclose(fdr);
    fclose(fdw);

    return true;
}