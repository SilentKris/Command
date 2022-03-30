#ifndef __RDIR_H
#define __RDIR_H
#include <string>

class RDIR
{
    public:
        //construct functions
        RDIR();
        RDIR(RDIR &);
        ~RDIR();
        RDIR(const RDIR &);
        //other functions
        std::string getDirName();
        std::string getFileName(long);
        void getFileList();

    private:


};


#endif