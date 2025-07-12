#pragma once

#include "../../data/kilominx.hpp"

class KilominxRotateUtils {
    public:
        static Face genEmptyFace(){
            Face face;
            for(int i=0;i<5;i++)
                face.push_back("");
            return face;
        }

        static Face rotate(Face face){
            Face newFace = genEmptyFace();

            newFace[0] = face[4];
            newFace[1] = face[0];
            newFace[2] = face[1];
            newFace[3] = face[2];
            newFace[4] = face[3];
            
            return face;
        }

        static Face rotateAsync(Face face){
            Face newFace = genEmptyFace();
            
            newFace[0] = face[1];
            newFace[1] = face[2];
            newFace[2] = face[3];
            newFace[3] = face[4];
            newFace[4] = face[0];
            
            return face;
        }

        static Face rotateTwice(Face face){
            for(int i=0;i<2;i++)
                face = rotate(face);
            return face;
        }

        static Face rotateTwiceAsync(Face face){
            for(int i=0;i<2;i++)
                face = rotateAsync(face);
            return face;
        }

        static Face rotateThree(Face face){
            for(int i=0;i<3;i++)
                face = rotate(face);
            return face;
        }

        static Face rotateThreeAsync(Face face){
            for(int i=0;i<3;i++)
                face = rotateAsync(face);
            return face;
        }

        static Face transfert(Face face, Face newFace){
            for(int i=0;i<face.size();i++)
                face[i] = (newFace[i]!="") ? newFace[i] : face[i];
            return face;
        }
};