#include <iostream>
#include <string>
#include "cpuinfo.h"


int main() {
    using namespace std;

    cpuinfo cpu;
    double temp = cpu.gettemp();
    
    cout << "temp = " << temp/1000 << "度" << endl;
    return 0;
}