#include <iostream>
#include<fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include<map>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include "Board.h"


using namespace std;


Board::Board(void) { 

	for(int i =0; i <10; i++)  {
		for(int j=0; j < 10; j++)  {
			score[i][j] = ' ';
		}
	}
		
}


void Board::addShip(char type, int x1, int y1, int x2, int y2)  {

	if(shipList.size() != 10) {
		shipList.push_back(Ship::makeShip(type, x1,y1,x2,y2));
	}
	
}


void Board::print(void)  {

	
	cout << "   a b c d e f g h i j" << endl;
	cout << "  +-------------------+" << endl;

	for(int i = 0; i < 10; i++)  {
		cout << " " << i << '|';
			for(int j = 0; j <10; j++)  {
				cout << score[i][j];
				if(j !=9)  {
					cout<< " ";
				}
			}
			cout << '|' << endl; 
	}

	
	cout << "  +-------------------+" << endl; 


}


void Board::hit(char c, int i)  {

	Ship* sh = NULL;

	map<char, int> convert;

	convert['a'] = 0;
	convert['b'] = 1;
	convert['c'] = 2;
	convert['d'] = 3;
	convert['e'] = 4;
	convert['f']=  5;
	convert['g'] = 6;
	convert['h'] = 7;
	convert['i'] = 8;
	convert['j'] = 9;

	if( c <=  'j' && c >= 'a' && i <= 9 && i >= 0) {

		if(shipAt(convert[c], i) != NULL && score[i][convert[c]] == ' ') {
			sh = shipAt(convert[c], i);
			sh->decreaseLevel();
			score[i][convert[c]] = '*';

				if(sh->level() == 0) {
					cout << sh->name() << " sunk" << endl;
				}
		}

		else if (shipAt(convert[c],i) == NULL) {
			score[i][convert[c]] = 'x';
		}
	}

	else 
		throw invalid_argument("invalid input");

}
 

int Board::level(void)  {

	int sum;

	for(vector<Ship*>::iterator iter = shipList.begin(); iter != shipList.end(); ++iter) {
    		sum = sum+(*iter)->level();
	}

	return sum;
      
} 


Ship * Board::shipAt(int x, int y)  {

	for(int i =0; i < 10; i++)  {
		if(shipList.at(i)->includes(x,y) == true)  {
			return shipList.at(i);
		}
	}
	return 0;	
}




