#pragma once
#include <map>
#include "dumpers/kilo_dumper.hpp"
#include "dumpers/mega_dumper.hpp"
#include "dumpers/mk_dumper.hpp"
#include "dumpers/giga_dumper.hpp"

class MinxDumperFactory {
    public:
        MinxDumper make(std::string puzzleType){
            std::map<std::string, int> hmapDumper;
            hmapDumper["kilominx"] = 2;
            hmapDumper["megaminx"] = 3;
            hmapDumper["masterKilominx"] = 4;
            hmapDumper["gigaminx"] = 5;

            int codeDumper = hmapDumper.count(puzzleType) ? hmapDumper[puzzleType] : 3;
            switch(codeDumper){
                case 2: KilominxDumper dumper; return dumper;
                case 3: MegaminxDumper dumper; return dumper;
                case 4: MasterKilominxDumper dumper; return dumper;
                case 5: GigaminxDumper dumper; return dumper;
                default: MegaminxDumper dumper; return dumper;
            } 
        }
};