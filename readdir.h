#if !defined(_READDIR)
#define _READDIR

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<std::string> * readdir(const char * path){

    try{
        if (!path) throw std::runtime_error("no path is specified");

        std::vector<std::string> * vecPtr = new std::vector<std::string>{};

        for (auto const& dir_entry : std::filesystem::directory_iterator{path}) 
        {
            vecPtr->push_back(dir_entry.path().string());
        }

        return vecPtr;
    }
    catch(std::runtime_error &e){
        std::cout << "Error: " << e.what() << std::endl;
        return nullptr;
    }

}


#endif // _READDIR
