#pragma once
#include <map>

#include "Minx.hpp"
#include "kilominx.hpp"
#include "megaminx.hpp"

#include "KilominxBuilder.hpp"
#include "MegaminxBuilder.hpp"

class MinxFactory {
    private:
        KilominxBuilder kiloBuilder;
        MegaminxBuilder megaBuilder;

    public:
        MinxFactory(){
            KilominxBuilder kiloBuilder;
            MegaminxBuilder megaBuilder;
        }

        /**
         * @brief make a puzzle corresponding to the puzzleType string
         * @author LucaGoubelle
         * @param puzzleType 
         * @return Minx 
         */
        Minx make(std::string puzzleType){
            std::map<std::string, Minx> hmap;
            hmap["kilominx"] = this->kiloBuilder.build();
            hmap["megaminx"] = this->megaBuilder.build();
            return (hmap.count(puzzleType)) ? hmap[puzzleType] : this->megaBuilder.build();
        }
};
