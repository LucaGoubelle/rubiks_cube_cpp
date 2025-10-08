#pragma once

#include "../../data/models/kilominx.hpp"

class KilominxRotateUtils {
    public:
        Face genEmptyFace(){
            Face face;
            for(int i=0;i<5;i++)
                face.push_back("");
            return face;
        }

        Face rotate(Face face){
            Face newFace = this->genEmptyFace();

            newFace[0] = face[4];
            newFace[1] = face[0];
            newFace[2] = face[1];
            newFace[3] = face[2];
            newFace[4] = face[3];
            
            return face;
        }

        Face rotateAsync(Face face){
            Face newFace = this->genEmptyFace();
            
            newFace[0] = face[1];
            newFace[1] = face[2];
            newFace[2] = face[3];
            newFace[3] = face[4];
            newFace[4] = face[0];
            
            return face;
        }

        Face rotateTwice(Face face){
            for(int i=0;i<2;i++)
                face = this->rotate(face);
            return face;
        }

        Face rotateTwiceAsync(Face face){
            for(int i=0;i<2;i++)
                face = this->rotateAsync(face);
            return face;
        }

        Face rotateThree(Face face){
            for(int i=0;i<3;i++)
                face = this->rotate(face);
            return face;
        }

        Face rotateThreeAsync(Face face){
            for(int i=0;i<3;i++)
                face = this->rotateAsync(face);
            return face;
        }

        Face transfert(Face face, Face newFace){
            for(int i=0;i<face.size();i++)
                face[i] = (newFace[i]!="") ? newFace[i] : face[i];
            return face;
        }
};
