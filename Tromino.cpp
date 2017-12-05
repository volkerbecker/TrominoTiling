/*
 * Tromino.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: becker
 */

#include "Tromino.h"
#include <iostream>


void Tromino::initTromino(const int &typ) {
		switch (typ) {
		case 1:
			// Straigt Tromino horizontal ***
			_number = 1;
			_lx = 3;
			_ly = 1;
			elements = vector<int> { 1, 1, 1 };
			break;
		case 2:
			// Straigt Tromino vertical *
			//                          *
			//							*
			_number = 2;
			_lx = 1;
			_ly = 3;
			elements = vector<int> { 1, 1, 1 };
			break;
		case 3:
			// L Tromino 1
			//                          *
			//							**
			_number = 3;
			_lx = 2;
			_ly = 2;
			elements = vector<int> { 1, 0,
				                     1, 1 };
			break;
		case 4:
			// L Tromino 2
			//                          **
			//							*
			_number = 4;
			_lx = 2;
			_ly = 2;
			elements = vector<int> { 1, 1,
				                     1, 0 };
			break;
		case 5:
			// L Tromino 3
			//                          **
			//							 *
			_number = 5;
			_lx = 2;
			_ly = 2;
			elements = vector<int> { 1, 1,
									0, 1 };
			break;
		case 6:
			// L Tromino 4
			//                           *
			//							**
			_number = 6;
			_lx = 2;
			_ly = 2;
			elements = vector<int> { 0, 1,
									 1, 1 };
			break;

		default:
			_number=-1;
			_lx=-1;
			_ly=-1;
			cerr << "Tromino type " << typ << " do not exist, debugging necessary" << endl;
			exit(1);
			break;
		}
	}

void Tromino::showTromino() {
	for(int y=0;y<_ly;++y) {
		for(int x=0;x<_lx;++x) {
			cout << elements[y*_lx+x] << "\t";
		}
		cout << endl;
	}
}

