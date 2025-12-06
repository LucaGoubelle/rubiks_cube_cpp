#pragma once
#include "CentersCaster.hpp"

class Centers5x5Caster : public CentersCaster {
    protected:
        Face extractCenters(Face actualFace){
            Face centers = {
                {actualFace[1][1], actualFace[1][2], actualFace[1][3]},
                {actualFace[2][1], actualFace[2][2], actualFace[2][3]},
                {actualFace[3][1], actualFace[3][2], actualFace[3][3]}
            };
            return centers;
        }

    public:
        Centers5x5Caster(){
            this->size = 5;
        }
};
