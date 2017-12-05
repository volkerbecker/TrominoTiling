/*
 * Board.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: becker
 */

#include "Board.h"

using namespace std;
Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::clearBoard() {
	for(auto &curr : elements) {
		curr=0;
	}
}

void Board::showBoard() const {
	cout << "Board:" << endl;
	for(int y=0;y<m;++y) {
		for(int x=0;x<n;++x) {
			std::cout << elements[y*n+x] << "\t";
		}
		std::cout << std::endl;
	}
}

bool Board::addTromino(const Tromino & trom,const int &x, const int &y){

	//Checken ob Tromino in die Matrix passt
	if(y+trom.getylength()>m || x+trom.getxlength()>n || y<0 || x <0)
		return false; // wenn nicht abbrechen
	 for(int yrep=0;yrep<trom.getylength();yrep++){
		 for(int xrep=0;xrep<trom.getxlength();xrep++) {
			int index=(y+yrep)*n+(x+xrep);
			if( (elements[index]+=trom.getElement(xrep,yrep)) > 1) {
				return false;
			}
		}
	}
	return true;
}
