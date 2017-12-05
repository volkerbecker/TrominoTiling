/*
 * Puzzler.h
 *
 *  Created on: Nov 1, 2016
 *      Author: becker
 */

#ifndef PUZZLER_H_
#define PUZZLER_H_

#include<vector>
#include"Board.h"
#include"Tromino.h"
#include<map>
#include "bigInt.h"
#include <functional>
//#include <sparsehash/sparse_hash_map>
#include <functional>

template<class T> class MyHash;

template<>
class MyHash<const Board &> {
public:
    size_t operator()(const Board &board) const
    {
    	vector<int> inhalt=board.showElements();
    	vector<bool> inhalt2;
    	inhalt2.resize(inhalt.size());
        for(unsigned int i=0;i<inhalt.size();++i) {
        	inhalt2[i]=(bool)inhalt[i];
        }
        size_t h=std::hash<std::vector<bool>>()(inhalt2);
        return h;
    }
};

struct eqboard
{
  bool operator()(const Board & s1, const Board & s2) const
  {
    return (s1.showElements()==s2.showElements());
  }
};

class Puzzler {
public:
	Puzzler();
	virtual ~Puzzler();

	bigint addNextTile(const Board &);

private:
//List elements to tile the board
		//todo initialise by user, then one can potentially
		// use trmino Tilings
	vector<Tromino> tiles = {Tromino(1),Tromino(2),
			Tromino(3),Tromino(4),Tromino(5),Tromino(6)};

	map<pair<size_t,pair<size_t,size_t>>,bigint> tmpResults;
	//google::sparse_hash_map<Board,bigint,MyHash<const Board &>,eqboard> tmpResults;
	int depth=0;
};

#endif /* PUZZLER_H_ */
