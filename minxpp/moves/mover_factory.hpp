#pragma once
#include <map>

#include "minx_mover.hpp"
#include "kilo/KilominxMover.hpp"
#include "mega/MegaminxMover.hpp"

class MoverFactory {
    public:
        MinxMover make(std::string puzzleType){
            std::map<std::string, int> hmapPuzzle;
            hmapPuzzle["kilominx"] = 2;
            hmapPuzzle["megaminx"] = 3;
            hmapPuzzle["master_kilominx"] = 4;

            int codePuzzle = (hmapPuzzle.count(puzzleType)) ? hmapPuzzle[puzzleType] : 3;

            switch(codePuzzle){
                case 2:
                    KilominxMover mover;
                    return mover;
                case 3:
                    MegaminxMover mover;
                    return mover;
                default:
                    MegaminxMover mover;
                    return mover;
            }
        }
};
