#pragma once
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

#include "../rubikpp/data/cube.hpp"


class ColorDetector{
    private:
        std::vector<std::string> split(std::string str, char del){
            std::vector<std::string> result;
            std::stringstream ss(str);
            std::string temp = "";
            while(getline(ss, temp, del))
                result.push_back(temp);
            return result;
        }
    public:

        /**
        * Detect a provided color on a provided face, return a matrix of binary integer
        * @author: LucaGoubelle
        */
        std::vector< std::vector<int> > detectColorOnFace(Face face, std::string color){
            std::vector<std::vector<int> > result;
            int size = face.size();
            for(int i=0;i<size;i++){
                std::vector<int> row;
                for(int j=0;j<size;j++){
                    int elem = (face[i][j]==color) ? 1 : 0 ;
                    row.push_back(elem);
                }
                result.push_back(row);
            }
            return result;
        }

        /**
        * Return true if the colors provided matches on the provided edge
        * @author: LucaGoubelle
        */
        bool detectColorsOnEdge(std::string edge, std::vector<std::string> colors){
            std::vector<std::string> results = this->split(edge, '_');
            bool cond1 = std::count(results.begin(), results.end(), colors[0]);
            bool cond2 = std::count(results.begin(), results.end(), colors[1]);
            return cond1 && cond2;
        }

        /**
        * Return true if the colors provided matches on the provided corner
        * @author: LucaGoubelle
        */
        bool detectColorsOnCorner(std::string corner, std::vector<std::string> colors){
            std::vector<std::string> results = this->split(corner, '_');
            bool cond1 = std::count(results.begin(), results.end(), colors[0]);
            bool cond2 = std::count(results.begin(), results.end(), colors[1]);
            bool cond3 = std::count(results.begin(), results.end(), colors[2]);
            return cond1 && cond2 && cond3;
        }
};
