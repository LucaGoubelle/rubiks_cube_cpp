#pragma once
#include "CentersCaster.hpp"

class Centers6x6Caster : public CentersCaster {
    protected:
        Face extractCenters(Face actualFace){
            Face centers = {
                {actualFace[1][1], actualFace[1][2], actualFace[1][3], actualFace[1][4]},
                {actualFace[2][1], actualFace[2][2], actualFace[2][3], actualFace[2][4]},
                {actualFace[3][1], actualFace[3][2], actualFace[3][3], actualFace[3][4]},
                {actualFace[4][1], actualFace[4][2], actualFace[4][3], actualFace[4][4]}
            };
            return centers;
        }

    public:
        Centers5x5Caster(){
            this->size = 6;
        }
};
