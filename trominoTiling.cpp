//============================================================================
// Name        : trominoTiling.cpp
// Author      : Volker Becker
// Version     :
// Copyright   : (c) 2015 by Volker Becker
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Board.h"
#include "Tromino.h"
#include "Puzzler.h"
#include "bigInt.h"

int main(void) {
//	Board board1(5,6);
//	Board board2(5,6);
//	Board board3(5,6);
//
//
////	board.showBoard();
//	Tromino trom1(1);
//	Tromino trom2(2);
//	Tromino trom3(3);
//
//	board1.addTromino(trom2,2,1);
//	board2.addTromino(trom2,4,0);
//	board3.addTromino(trom2,4,1);
//
//	cout << "key: " << board1.key() << endl;
//	cout << "key: " << board2.key() << endl;
//	cout << "key: " << board3.key() << endl;
//

//	board3.addTromino(trom3,1,0);
//	board.addTromino(trom2,1,2);
//	board.addTromino(trom3,3,3);
//	board.showBoard();
//
//	cout << "Hash: " << MyHash<const Board &>()(board) << endl;
//
//	//cout << "Gebiet: " << board.markZeroArea(board,5,0,2) << endl;
//	//board.showBoard();
//	cout << board.isolatedHoles() << endl;

//	google::sparse_hash_map<Board,bigint,MyHash<const Board &>,eqboard> tmpResults;
//	tmpResults[board1]=5;
//	tmpResults[board2]=20;

//	cout << tmpResults[board1] << endl;
//	cout << tmpResults[board2] << endl;
//	cout << tmpResults[board3] << endl;

//	google::sparse_hash_map<Board,bigint,MyHash<const Board &>,eqboard>::iterator boardIterator;
//
//
//	if(tmpResults.count(board3)!=0) {
//		cout << tmpResults[board3] << endl;
//	}

	Puzzler solver;
	Board board(14,12);
	//bigint i;
	//cout << sizeof(i) << endl;
	cout << "Result: " << solver.addNextTile(board) << endl;
	return EXIT_SUCCESS;
}

unsigned int tileBox(const int &n,const int &m)
{

	return 0;
}
