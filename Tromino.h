/*
 * Tromino.h
 *
 *  Created on: Oct 31, 2016
 *      Author: becker
 */

#ifndef TROMINO_H_
#define TROMINO_H_

#include<vector>
#include <stdio.h>

using namespace std;

class Tromino {
public:
	Tromino() {};
	Tromino(const int & typ) {
		initTromino(typ);
	};
	virtual ~Tromino() {};

	int & number() {
		return _number;
	}
	const int & number() const {
		return _number;
	}

	const int & getxlength() const { return _lx;}
	const int & getylength() const { return _ly;}

	void initTromino(const int &);
	void showTromino();

	const int & getElement(const int & x,const int &y) const {
		return elements[y*_lx+x];
	}

private:
	int _number=-1;
	int _lx=-1;
	int _ly=-1;
	vector<int> elements;



};
#endif /* TROMINO_H_ */
