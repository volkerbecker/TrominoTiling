/*
 * Puzzler.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: becker
 */

#include "Puzzler.h"

Puzzler::Puzzler() {
	// TODO Auto-generated constructor stub

}

Puzzler::~Puzzler() {
	// TODO Auto-generated destructor stub

}

bigint Puzzler::addNextTile(const Board  & board) {
	int xpos=0,ypos=0;
	bigint tilings=0;
	depth++;
	//cout << depth << endl;
	Board newBoard;

	map<pair<size_t,pair<size_t,size_t>>,bigint>::iterator boardIterator;

	if( (boardIterator=tmpResults.find(board.key())) != tmpResults.end() ) {
		depth--;
		return boardIterator->second;
	} // wurden das Board in dieser zusstand schon mal aufgerufen, wenn ja
	// gib das Ergebnis dieses Aufrufs zurück
	// ansonsten mache weiter

//	if(tmpResults.count(board) !=0) {
//			depth--;
//			return tmpResults[board];
//	}

	board.findfreepostion(xpos,ypos);
	for (const auto & currentTile : tiles) {
		if(depth==1) cout << currentTile.number() << endl;
		for (int xoffset = 0; xoffset < currentTile.getxlength(); xoffset++) {
			for (int yoffset = 0; yoffset < currentTile.getylength();
					yoffset++) {
				newBoard=board;
				//newBoard.showBoard();
				//board.showBoard();
				if(newBoard.addTromino(currentTile,xpos-xoffset,ypos-yoffset)) {
					if(newBoard.isfull()) {
						//tmpResults[board]=1;
						depth--;
						return (int)1;
					}
					else {
						if(!newBoard.isolatedHoles()) {
							tilings+=addNextTile(newBoard);
						}
					}
				}
			}
		}
	}
	tmpResults[board.key()]=tilings; //zwischenergebnis für akutelles Board speichern
//	if(tmpResults.size()>10000000) {
//		tmpResults.clear();
//	}
	depth--;
	return tilings;
}
