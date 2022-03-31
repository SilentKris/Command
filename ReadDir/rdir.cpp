#include "rdir.h"
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>

RDIR::RDIR(const char *dirPath):fileCount(0)
{
    DIR *dp = opendir(dirPath);
    while(true) { 
        dirent *dent = readdir(dp);
        if(nullptr == dent)
            break;
        fileCount ++;
        addfile(dent);
    }
}

void RDIR::addfile(dirent * dent) {
        fileList *p_cur = &filelist;
        fileList *p_next = nullptr;

        while(p_cur->next)
            p_cur = p_cur->next;

        p_next = new fileList;
        p_next->next = nullptr;
        
        memcpy(&p_next->dent, dent, sizeof(dirent));
        p_cur->next = p_next;
        p_cur = p_next;
        p_next = p_next->next;
}

void RDIR::getFileList() {
    fileList *p_cur = &filelist;

    while(p_cur->next) {
        p_cur = p_cur->next;
        cout << "├──" << p_cur->dent.d_name << endl;
    }

}

RDIR::~RDIR()
{
    cout << "destruct this structure" << endl;
}