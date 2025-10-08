#pragma once
#include <map>
#include "models/Minx.hpp"

#include "builders/KilominxBuilder.hpp"
#include "builders/MegaminxBuilder.hpp"
#include "builders/MasterKilominxBuilder.hpp"
#include "builders/GigaminxBuilder.hpp"

class MinxFactory {
    private:
        KilominxBuilder kiloBuilder;
        MegaminxBuilder megaBuilder;
        MasterKilominxBuilder mkBuilder;
        GigaminxBuilder gigaBuilder;

    public:
        MinxFactory(){
            KilominxBuilder kiloBuilder;
            MegaminxBuilder megaBuilder;
            MasterKilominxBuilder mkBuilder;
            GigaminxBuilder gigaBuilder;
        }

        /**
         * make a puzzle corresponding to the puzzleType string
         * @author LucaGoubelle
         * @param puzzleType 
         * @return Minx 
         */
        Minx make(std::string puzzleType){
            std::map<std::string, Minx> hmap;
            hmap["kilominx"] = this->kiloBuilder.build();
            hmap["megaminx"] = this->megaBuilder.build();
            hmap["masterKilominx"] = this->mkBuilder.build();
            hmap["gigaminx"] = this->gigaBuilder.build();
            return (hmap.count(puzzleType)) ? hmap[puzzleType] : this->megaBuilder.build();
        }
};
