#pragma once

#include "../../data/models/masterKilominx.hpp"

class MasterKilominxRotateUtils {
    public:
        Face genEmptyFace(){
            Face face;
            std::vector<std::string> row;
            std::vector<std::string> row2;
            for(int i=0;i<15;i++)
                row.push_back("");
            for(int i=0;i<5;i++)
                row2.push_back("");
            face.push_back(row);
            face.push_back(row2);
            return face;
        }

        Face rotate(Face face){
            Face newFace = this->genEmptyFace();

            newFace[0][0] = face[0][12];
            newFace[0][1] = face[0][13];
            newFace[0][2] = face[0][14];
            newFace[0][3] = face[0][0];
            newFace[0][4] = face[0][1];
            newFace[0][5] = face[0][2];
            newFace[0][6] = face[0][3];
            newFace[0][7] = face[0][4];
            newFace[0][8] = face[0][5];
            newFace[0][9] = face[0][6];
            newFace[0][10] = face[0][7];
            newFace[0][11] = face[0][8];
            newFace[0][12] = face[0][9];
            newFace[0][13] = face[0][10];
            newFace[0][14] = face[0][11];

            newFace[1][0] = face[0][4];
            newFace[1][1] = face[0][0];
            newFace[1][2] = face[0][1];
            newFace[1][3] = face[0][2];
            newFace[1][4] = face[0][3];

            return newFace;
        }

        Face rotateAsync(Face face){
            Face newFace = this->genEmptyFace();
            
            newFace[0][0] = face[0][3];
            newFace[0][1] = face[0][4];
            newFace[0][2] = face[0][5];
            newFace[0][3] = face[0][6];
            newFace[0][4] = face[0][7];
            newFace[0][5] = face[0][8];
            newFace[0][6] = face[0][9];
            newFace[0][7] = face[0][10];
            newFace[0][8] = face[0][11];
            newFace[0][9] = face[0][12];
            newFace[0][10] = face[0][13];
            newFace[0][11] = face[0][14];
            newFace[0][12] = face[0][0];
            newFace[0][13] = face[0][1];
            newFace[0][14] = face[0][2];

            newFace[1][0] = face[0][1];
            newFace[1][1] = face[0][2];
            newFace[1][2] = face[0][3];
            newFace[1][3] = face[0][4];
            newFace[1][4] = face[0][0];

            return newFace;
        }

        Face transfert(Face face, Face newFace){
            for(int i=0;i<face[0].size();i++)
                face[0][i] = (newFace[0][i]!="") ? newFace[0][i] : face[0][i];
            for(int i=0;i<face[1].size();i++)
                face[1][i] = (newFace[1][i]!="") ? newFace[1][i] : face[1][i];
            return face;
        }
};
