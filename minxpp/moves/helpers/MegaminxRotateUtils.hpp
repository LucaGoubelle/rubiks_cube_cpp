#pragma once

#include "../../data/models/megaminx.hpp"

class MegaminxRotateUtils {
    public:
        Face genEmptyFace(){
            Face face;
            std::vector<std::string> row;
            std::vector<std::string> row2;
            for(int i=0;i<10;i++)
                row.push_back("");
            row2.push_back("");
            face.push_back(row);
            face.push_back(row2);
            return face;
        }

        Face rotate(Face face){
            Face newFace = genEmptyFace();

            newFace[0][0] = face[0][8];
            newFace[0][1] = face[0][9];
            newFace[0][2] = face[0][0];
            newFace[0][3] = face[0][1];
            newFace[0][4] = face[0][2];
            newFace[0][5] = face[0][3];
            newFace[0][6] = face[0][4];
            newFace[0][7] = face[0][5];
            newFace[0][8] = face[0][6];
            newFace[0][9] = face[0][7];

            newFace[1][0] = face[1][0];

            return newFace;
        }

        Face rotateAsync(Face face){
            Face newFace = genEmptyFace();
            
            newFace[0][0] = face[0][2];
            newFace[0][1] = face[0][3];
            newFace[0][2] = face[0][4];
            newFace[0][3] = face[0][5];
            newFace[0][4] = face[0][6];
            newFace[0][5] = face[0][7];
            newFace[0][6] = face[0][8];
            newFace[0][7] = face[0][9];
            newFace[0][8] = face[0][0];
            newFace[0][9] = face[0][1];

            newFace[1][0] = face[1][0];

            return newFace;
        }

        Face rotateTwice(Face face){
            for(int i=0;i<2;i++)
                face = rotate(face);
            return face;
        }

        Face rotateTwiceAsync(Face face){
            for(int i=0;i<2;i++)
                face = rotateAsync(face);
            return face;
        }

        Face rotateThree(Face face){
            for(int i=0;i<3;i++)
                face = rotate(face);
            return face;
        }

        Face rotateThreeAsync(Face face){
            for(int i=0;i<3;i++)
                face = rotateAsync(face);
            return face;
        }

        Face transfert(Face face, Face newFace){
            for(int i=0;i<face[0].size();i++)
                face[0][i] = (newFace[0][i]!="") ? newFace[0][i] : face[0][i];
            face[1][0] = (newFace[1][0]!="") ? newFace[1][0] : face[1][0];
            return face;
        }
};
