#pragma once
#include <map>
#include "dumpers/kilo_dumper.hpp"
#include "dumpers/mega_dumper.hpp"

class MinxDumperFactory {
    public:
        MinxDumper make(std::string puzzleType){
            std::map<std::string, int> hmapDumper;
            hmapDumper["kilominx"] = 2;
            hmapDumper["megaminx"] = 3;

            int codeDumper = hmapDumper.count(puzzleType) ? hmapDumper[puzzleType] : 3;
            switch(codeDumper){
                case 2: KilominxDumper dumper; return dumper;
                case 3: MegaminxDumper dumper; return dumper;
                default: MegaminxDumper dumper; return dumper;
            } 
        }
};