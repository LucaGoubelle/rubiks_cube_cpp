#pragma once
#include <string>
#include <map>

#include "ansi_colors.hpp"
#include "../data/cube.hpp"
#include "../exceptions/PrinterException.hpp"

using Row = std::vector<std::string>;

class CubePrinter {
    private:
        std::string rowUpDown(Row row){
            std::string content = "";
            for(std::string elem : row)
                content += " ";
            for(std::string elem : row)
                content += hmap[elem];
            for(std::string elem : row)
                content += " ";
            content += "\n";
            return content;
        }
        
        std::string rowLFRB(Row rowL, Row rowF, Row rowR, Row rowB){
            std::string content = "";
            for(std::string elem : rowL) 
                content += hmap[elem];
            for(std::string elem : rowF) 
                content += hmap[elem];
            for(std::string elem : rowR)
                content += hmap[elem];
            for(std::string elem : rowB) 
                content += hmap[elem];
            content += "\n";
            return content;
        }
    public:
        std::map<std::string, std::string> hmap;

        CubePrinter(){
            this->hmap["green"] = GREEN+" "+RESET;
            this->hmap["orange"] = MAGENTA+" "+RESET;
            this->hmap["blue"] = BLUE+" "+RESET;
            this->hmap["red"] = RED+" "+RESET;
            this->hmap["yellow"] = YELLOW+" "+RESET;
            this->hmap["white"] = WHITE+" "+RESET;
        }

        /**
         * @brief return a printable string of the 2D cube
         * @author LucaGoubelle
         * @param cube 
         * @return std::string 
         */
        std::string printCube(Cube cube){
            try{
                std::string content = "";
                for(std::vector<std::string> row : cube.up)
                    content += rowUpDown(row);
                for(int i=0;i<cube.front.size();i++)
                    content += rowLFRB(cube.left[i], cube.front[i], cube.right[i], cube.back[i]);
                for(std::vector<std::string> row : cube.down)
                    content += rowUpDown(row);
                return content;
            } catch(...){
                throw PrinterException();
            }
        }
};
