/*
 * Board.h
 *
 *  Created on: Oct 31, 2016
 *      Author: becker
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include "Tromino.h"
#include "bigInt.h"


class Board {
public:
	Board() {};
	Board(const int & _m,const int & _n):m(_m),n(_n) {
		elements.resize(m*n);
		clearBoard();
	}
	virtual ~Board();

	pair<size_t,pair<size_t,size_t>> key() const {
		size_t wert1=0;
		size_t wert2=0;
		size_t wert3=0;

		int i=0;
		for(auto & el: elements) {
			++i;
			if(i<=64) {
				wert1 = wert1 << 1;
				wert1+=el;
			}
			else if(i<=128){
				wert2 = wert2 << 1;
				wert2+=el;
			}
			else {
				wert3 = wert3 << 1;
				wert3+=el;
			}
		}
		return make_pair(wert1,make_pair(wert2,wert3));
	}

	bool operator==(const Board & rhs) const {
		return (this->elements==rhs.elements);
	}
	bool operator<(const Board & rhs) const {
			return (this->elements<rhs.elements);
	}
	bool operator>(const Board & rhs) const {
				return (this->elements>rhs.elements);
	}
	bool operator<=(const Board & rhs) const {
				return (this->elements<=rhs.elements);
	}
	bool operator>=(const Board & rhs) const {
				return (this->elements>=rhs.elements);
	}


	void showBoard() const;
	void clearBoard();
	bool addTromino(const Tromino &,const int &y, const int &x);
	const vector<int> & showElements() const {
		return elements;
	}


	inline bool isfull() {
		for(auto & curElement : elements) {
			if(curElement==0) return false;
		}
		return true;
	}

	int & element(const int &x,const int &y) {
		return elements[y*n+x];
	}

	const int & element(const int &x,const int &y) const {
			return elements[y*n+x];
		}

	void findfreepostion(int &x, int &y) const {
		for(int i=0;i<(int)elements.size();++i) {
			if(elements[i]==0) {
				y=i/n;
				x=i%n;
				return;
			}
		}
	}

	int markZeroArea(Board &testBoard,const int &x,const int &y,const int &n) {
		int zeros=0;
		if(x<0 || y<0 || x>=this->n || y >= this->m) return 0;
		if(testBoard.element(x,y)!=0) {
			return zeros;
		} else {
			zeros=1;
			testBoard.element(x,y)=n;
			zeros+=markZeroArea(testBoard,x+1,y,n);
			zeros+=markZeroArea(testBoard,x-1,y,n);
			zeros+=markZeroArea(testBoard,x,y+1,n);
			zeros+=markZeroArea(testBoard,x,y-1,n);
			return zeros;
		}
	}

	bool isolatedHoles() {
		Board tmpboard=*this;
		int gebiet=2;
		for(int i=0;i<tmpboard.elements.size();++i) {
			if(tmpboard.elements[i]==0) {
				//cout << "x " << i%n << " y: " << i/n << endl;
				int block=markZeroArea(tmpboard,i%n,i/n,gebiet);
				//cout << "Block: " << block << endl;
				if(block%3 != 0) return true;

				//tmpboard.showBoard();
			}
		}
		return false;
	}

private:
	int m,n; //Board size
	std::vector<int> elements;

};

#endif /* BOARD_H_ */
