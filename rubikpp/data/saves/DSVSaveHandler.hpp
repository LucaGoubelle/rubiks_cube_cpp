#pragma once

#include "../cube.hpp"

class DSVSaveHandler {
    private:
        std::string filepath;
    public:
        DSVSaveHandler(){
            this->filepath = "res/data/";
        }

        void save(Cube cube, std::string filename){
            std::string fullpath = this->filepath + filename;
            //todo: implement this
        }
};
