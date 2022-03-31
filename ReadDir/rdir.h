#ifndef __RDIR_H
#define __RDIR_H
#include <string>
#include <dirent.h>
using namespace std;

typedef struct filelist {
    dirent dent;

    struct filelist *next;
} fileList;

class RDIR
{
    public:
        //construct functions
        RDIR(const char *dirPath);
        RDIR(RDIR &);
        ~RDIR();
        RDIR(const RDIR &);
        //other functions
        std::string getDirName();
        void getFileName(long);
        void getFileList();

    private:
        void addfile(dirent *);

        string dirPath;
        int fileCount;
        fileList filelist;
};


#endif