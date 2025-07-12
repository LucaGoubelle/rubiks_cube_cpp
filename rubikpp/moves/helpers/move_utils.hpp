#pragma once
#include <string>
#include <vector>

using Face = std::vector< std::vector< std::string > >;

class MoveUtils{
public:
    static Face genEmptyFace(int size){
		Face face;
		for(int i=0;i<size;i++){
			std::vector< std::string > row;
			for(int j=0;j<size;j++)
				row.push_back("");
			face.push_back(row);
		}
    	return face;
    }

    static Face rotate(Face face){
		int size = face.size();
		Face newFace = genEmptyFace(size);
		for(int i=0;i<size;i++){
			int cnt = size - 1;
			for(int j=0;j<size;j++){
			newFace[i][j] = face[cnt][i];
			cnt--;
			}
		}
		return newFace;
    }

    static Face rotateAsync(Face face){
		for(int i=0;i<3;i++)
			face = rotate(face);
		return face;
    }

    static Face rotateTwice(Face face){
		for(int i=0;i<2;i++)
			face = rotate(face);
		return face;
    }

    static Face transfert(Face face, Face newFace){
		int size = face.size();
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				face[i][j] = (newFace[i][j]!="") ? newFace[i][j] : face[i][j];
		return face;
    }
};
