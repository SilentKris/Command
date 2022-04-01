#include "rdir.h"
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>

RDIR::RDIR(const char *dirPath):fileCount(0)
{
    filelist.tail = &filelist;
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

        fileList *p_cur = filelist.tail;
        fileList *p_next = new fileList;

        memcpy(&p_next->dent, dent, sizeof(dirent));
        p_next->next = nullptr;

        p_cur->next = p_next;
        filelist.tail = p_next;
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
    if(nullptr != filelist.next) {
        fileList *p_cur = filelist.next;
        fileList *p_next = p_cur->next;
        while(true) {
            if(p_next){
                delete p_cur;
                p_next = p_next->next;
            }else {
                delete p_cur;
                break;
            }
        }
    }
    cout << "deconstructe" << endl;
}