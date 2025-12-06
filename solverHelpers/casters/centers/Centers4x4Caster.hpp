#pragma once
#include "CentersCaster.hpp"

class Centers4x4Caster : public CentersCaster {
    protected:
        Face extractCenters(Face actualFace){
            Face centers = {
                {actualFace[1][1], actualFace[1][2]},
                {actualFace[2][1], actualFace[2][2]}
            };
            return centers;
        }

    public:
        Centers5x5Caster(){
            this->size = 4;
        }
};