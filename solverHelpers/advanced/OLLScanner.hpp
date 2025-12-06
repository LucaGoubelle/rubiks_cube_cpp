#pragma once
#include "../scanners/CrownScanner.hpp"
#include "../casters/CrownCaster.hpp"

class OLLScanner {
    private:
        CrownScanner crownScanner;
        CrownCaster crownCaster;
    public:
        OLLScanner(){
            CrownScanner crownScanner;
            CrownCaster crownCaster;
        }

        /**
        * scan an OLL (Orienting Last Layer) config then return a binary crown
        * @author: LucaGoubelle
        */
        std::string scanOLL(Cube cube){
            Crown crown = this->crownScanner.scanCrown(cube);
            std::string result = this->crownCaster.cast(crown);
            return result;
        }
};
