#pragma once
#include "cube.hpp"

class CubeBuilder {

	private:
		/**
		 * build a rubik's cube's face based on a size and an element to fill
		 * @author: LucaGoubelle
		 * @param size 
		 * @param elem 
		 * @return Face 
		 */
		Face buildFace(int size, std::string elem){
			std::vector< std::vector< std::string > > face;
			for(int i=0;i<size;i++){
				std::vector< std::string > row;
				for(int j=0;j<size;j++)
					row.push_back(elem);
				face.push_back(row);
			}
			return face;
		}

	public:

	/**
	 * build a rubik's cube based on a size param
	 * @author: LucaGoubelle
	 * @param size 
	 * @return Cube 
	 */
    Cube build(int size){
		Face back = this->buildFace(size, "green");
		Face up = this->buildFace(size, "yellow");
		Face front = this->buildFace(size, "blue");
		Face left = this->buildFace(size, "orange");
		Face right = this->buildFace(size, "red");
		Face down = this->buildFace(size, "white");
    	return Cube(back,up,front,left,right,down);
    }
};