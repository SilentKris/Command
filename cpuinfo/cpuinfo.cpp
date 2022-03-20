#include <iostream>
#include <fstream>
#include <string>

#include "cpuinfo.h"

using namespace std;

const char* cpuinfoPath = "/sys/class/thermal/thermal_zone0/temp";
string tempPath = "./cpuinfo.cpp";

cpuinfo::cpuinfo() {
    char cputemp[10];
    FILE *fp = fopen(cpuinfoPath, "r");
    if(fp == NULL) {
        cout << "failed to open file" << endl;
    }
    fgets(cputemp, 10, fp);
    temp = stoi(string(cputemp));
    fclose(fp);
}

int cpuinfo::gettemp() {
    return temp;
}