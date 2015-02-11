#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include "Ship.h"

using namespace std; 

AircraftCarrier::AircraftCarrier(int x1, int y1, int x2, int y2) {
	setPos(x1, y1, x2, y2);
	lev = 5;
}

BattleShip::BattleShip(int x1, int y1, int x2, int y2) {
	setPos(x1, y1, x2, y2);
	lev = 4;
}

Cruiser::Cruiser(int x1, int y1, int x2, int y2) {
	setPos(x1, y1, x2, y2);
	lev = 3;
}

Destroyer::Destroyer(int x1, int y1, int x2, int y2) {
	setPos(x1, y1, x2, y2);
	lev = 2;
}



int Ship::getX(int i) const {
	
	if(x1 == x2) { //the ship is vertical
		return x1;
	} else if(x1< x2) { //the ship is horizontal
		return x1+i;
		}
		else {
		return x2+i;
		}
	}


int Ship::getY(int i) const {

	if(x1 == x2) { // the ship is vertical
		if(y1 < y2) {
		return y1+i;
		}
		else {
		return y2+i;
		}
	} else { // the ship is horizontal
		return y1;
	}
}

void Ship::print(void) const {

	if(size() == 5) {
		cout << "AircraftCarrier" << " " << "from" << " " << "(" << x1 << "," << y1 << ")" << " " << "to" << " " << "(" << x2 << "," << y2 << ")" << endl;
	}

	if(size() == 4) {
		cout << "BattleShip" << " " << "from" << " " << "(" << x1 << "," << y1 << ")" << " " << "to" << " " << "(" << x2 << "," << y2 << ")" <<  endl;
	}

	if(size() == 3) {
		cout << "Cruiser" << " " << "from" << " " << "(" << x1 << "," << y1 << ")" << " " << "to" << " " << "(" << x2 << "," << y2 << ")" << endl;
	}

	if(size() == 2) {
		cout << "Destroyer" << " " << "from" << " " << "(" << x1 << "," << y1 << ")" << " " << "to" << " " << "(" << x2 << "," << y2 << ")" << endl;
	}

}

bool Ship::includes(int x, int y){

	//cout << x1 << " " << x << " " << x2 << " " << y1 << " " << y << " " << y2 << endl;
	if(x1 == x2 && x1 == x) {
		if( (y1 >= y && y2 <= y) || (y2 >= y && y1 <= y)) {
			//cout << "ssegeg" << endl;
			return true;
		}
	}

	if(y2 == y1 && y2 == y) {
		if( (x1 >= x && x2 <= x) || (x2 >= x && x1 <= x)) {
			//cout << "opjuip" << endl;
			return true;
		}
	}

	if(x1 == x2) {
		if( ( y1 < y || y2 < y || y2 > y || y1 > y)) {
			return false;
		}
	}

	if(y2 == y1) {
		if( ( x1 < x || x2 < x || x2 > x || x1 < x )) {
			return false;
		}
	}

	if(x1 != x2 && y2 != y2) {
		return false;
	}



	return false;	
		
}

int Ship::level(void) const{

	return lev;

}

void Ship::decreaseLevel(void){

	if(lev <= 0) {
		lev = lev;
	}
		else {
			lev = lev - 1;
		}

}


Ship* Ship::makeShip(char ch, int x1, int y1, int x2, int y2){

	Ship* j;

	
	if(ch == 'A') {
		j = new AircraftCarrier(x1, y1, x2, y2);
	}
	if(ch == 'B') {
		j = new BattleShip(x1, y1, x2, y2);
	}
	if(ch == 'C') {
		j = new Cruiser(x1, y1, x2, y2);
	}
	if(ch == 'D') {
		j = new Destroyer(x1, y1, x2, y2);
	}


	if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D') {
		throw invalid_argument("invalid configuration");
      	}
	


		

	return j;
}

void Ship::setPos(int a1, int b1, int a2, int b2){

	if(checkConfig(a1, b1, a2, b2) == false) {
		throw invalid_argument("invalid configuration");
      	}
	
	if(checkConfig(a1, b1, a2, b2) == true) {
		x1 = a1;
  		y1 = b1;
		x2 = a2;
		y2 = b2;
	}
} 

bool Ship::checkConfig(int x1, int y1, int x2, int y2){

	
      int s;

	if(x1 == x2) { 
		s = abs(y2 - y1);
	}
	else if (y2 == y1) {
		s = abs(x2 - x1);
	}
			
	
	if(name() == (char *)"AircraftCarrier" && size() >= s + 1) {
		return true;
	}
	if(name() == (char *)"BattleShip" && size() >= s + 1) {
		return true;
	}
	if(name() == (char *)"Cruiser" && size() >= s + 1) {
		return true;
	}
	if(name() == (char *)"Destroyer" && size() >= s + 1) {
		return true;
	}
	
		
	return false; 
		

}

const char* AircraftCarrier::name(void) const {

	return "AircraftCarrier";

}

int AircraftCarrier::size(void) const {

	return 5;

}

const char* BattleShip::name(void) const {

	return "BattleShip";


}

int BattleShip::size(void) const {

	return 4;

}

const char* Cruiser::name(void) const {

	return "Cruiser";

}

int Cruiser::size(void) const {

	return 3;

}

const char* Destroyer::name(void) const {

	return "Destroyer";
	
}

int Destroyer::size(void) const {

	return 2;

}


