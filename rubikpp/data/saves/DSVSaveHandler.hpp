#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "../cube.hpp"

class DSVSaveHandler {
    private:
        std::string filepath;

        std::vector<std::string> split(std::string str, char del){
            std::vector<std::string> result;
            std::stringstream ss(str);
            std::string temp = "";
            while(getline(ss, temp, del))
                result.push_back(temp);
            return result;
        }

        std::string castFaceToChars(Face face){
            std::string content = "";
            for(int i=0;i<face.size();i++){
                for(int j=0;j<face[i].size();j++){
                    std::string delim = (j==face[i].size()-1) ? "" : ",";
                    content += face[i][j] + delim;
                }
                content += (i==face.size()-1) ? "":";";
            }
            content += "\n";
            return content;
        }

        Face loadFace(std::string record){
            Face face;
            std::vector<std::string> rows = this->split(record, ';');
            for(int i=0;i<rows.size();i++){
                std::vector<std::string> cols = this->split(rows[i], ',');
                face.push_back(cols);
            }
            return face;
        }

    public:
        DSVSaveHandler(){
            this->filepath = "res/data/";
        }

        void save(Cube cube, std::string filename){
            std::string fullpath = this->filepath + filename;
            std::ofstream fissier(fullpath);
            fissier << this->castFaceToChars(cube.back);
            fissier << this->castFaceToChars(cube.up);
            fissier << this->castFaceToChars(cube.front);
            fissier << this->castFaceToChars(cube.left);
            fissier << this->castFaceToChars(cube.right);
            fissier << this->castFaceToChars(cube.down);
            fissier.close();
        }

        Cube loadSave(std::string filename){
            std::string fullpath = this->filepath + filename;
            std::ifstream fissier(fullpath);
            std::vector<std::string> lines;
            std::string line;
            while(std::getline(fissier, line))
                lines.push_back(line);
            fissier.close();

            Face backLoaded = this->loadFace(lines[0]);
            Face upLoaded = this->loadFace(lines[1]);
            Face frontLoaded = this->loadFace(lines[2]);
            Face leftLoaded = this->loadFace(lines[3]);
            Face rightLoaded = this->loadFace(lines[4]);
            Face downLoaded = this->loadFace(lines[5]);

            return Cube(
                backLoaded, upLoaded, frontLoaded, leftLoaded, rightLoaded, downLoaded
            );
        }
        
};
