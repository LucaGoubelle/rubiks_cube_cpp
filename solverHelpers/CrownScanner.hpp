#pragma once
#include "../rubikpp/data/cube.hpp"

using Crown = std::vector<std::vector<std::string> >;
using Row = std::vector<std::string>;

class CrownScanner {
    private:
        Row scanBackOfCrown(Cube cube){
            int size = cube.up.size();
            Row row;
            for(int i=size-1; i>=0;i--)
                row.push_back(cube.back[0][i]);
            return row;
        }

        Row scanFrontOfCrown(Cube cube){
            int size = cube.up.size();
            Row row;
            for(int i=0; i<size; i++)
                row.push_back(cube.front[0][i]);
            return row;
        }

        Row scanUpOfCrown(Cube cube, int index){
            // todo: implement to reduce nb of lines
            int last = cube.up.size() - 1;
            Row row;
            row.push_back(cube.left[0][index]);
            for(int i=0;i<last+1;i++)
                row.push_back(cube.up[index][i]);
            row.push_back(cube.right[0][last-index]);
            return row;
        }
    public:

        /**
        * Return the top crown scanned
        * @author: LucaGoubelle
        */
        Crown scanCrown(Cube cube){
            Crown result;

            result.push_back(this->scanBackOfCrown(cube));
            for(int i=0;i<cube.up.size();i++)
                result.push_back(this->scanUpOfCrown(cube, i));
            result.push_back(this->scanFrontOfCrown(cube));

            return result;
        }
};
