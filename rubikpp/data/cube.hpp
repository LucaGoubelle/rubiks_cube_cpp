#pragma once
#include <string>
#include <vector>

using Face = std::vector< std::vector< std::string > >;

/**
 * Rubik's cube data model, each attributes is a face,
 * a face is a std::vector< std::vector< std::string > >
 * considering a std::string 2D matrix
 * @author: LucaGoubelle
 */
class Cube{
public:
    Face up;
    Face front;
    Face left;
    Face right;
    Face down;
    Face back;

    Cube(Face b, Face u, Face f, Face l, Face r, Face d){
		this->back = b;
		this->up = u;
		this->front = f;
		this->left = l;
		this->right = r;
		this->down = d;
    }
};

