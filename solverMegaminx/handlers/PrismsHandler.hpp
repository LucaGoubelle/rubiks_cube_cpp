#pragma once

#include "../../minxpp/data/megaminx.hpp"

#include "prisms/MagentaPrismHandler.hpp"
#include "prisms/LimePrismHandler.hpp"
#include "prisms/BeigePrismHandler.hpp"
#include "prisms/OrangePrismHandler.hpp"
#include "prisms/CyanPrismHandler.hpp"


class PrismsHandler {
    private:
        MagentaPrismHandler magentaPrismHandler;
        LimePrismHandler limePrismHandler;
        BeigePrismHandler beigePrismHandler;
        OrangePrismHandler orangePrismHandler;
        CyanPrismHandler cyanPrismHandler;
    public:
        PrismsHandler(){
            MagentaPrismHandler magentaPrismHandler;
            LimePrismHandler limePrismHandler;
            BeigePrismHandler beigePrismHandler;
            OrangePrismHandler orangePrismHandler;
            CyanPrismHandler cyanPrismHandler;
        }

        Megaminx handle(Megaminx minx){
            minx = this->magentaPrismHandler.handle(minx);
            minx = this->limePrismHandler.handle(minx);
            minx = this->beigePrismHandler.handle(minx);
            minx = this->orangePrismHandler.handle(minx);
            minx = this->cyanPrismHandler.handle(minx);
            return minx;
        }
};
