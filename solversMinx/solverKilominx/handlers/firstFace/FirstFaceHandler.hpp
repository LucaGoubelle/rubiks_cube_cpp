#pragma once

#include "../../../../minxpp/data/models/kilominx.hpp"
#include "../handler.hpp"

class FirstFaceHandler : public Handler {
    public:
        Kilominx handle(Kilominx minx){
            return minx;
        }
};
