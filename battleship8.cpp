#include "battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;


void initialize(ship[]){
	ship fleet[FLEET_SIZE];
	for (int i = 0; i < FLEET_SIZE; i++){
		fleet[i].loc.x = -1;
		fleet[i].loc.y = '*';
	}
}

location pick(){
	srand(1);
	//srand(time(nullptr));

	location loc;
	loc.x = rand() % FLEET_SIZE + 1;
	loc.y = rand() % FLEET_SIZE + 1;
	switch (loc.y) {
		case 1:
			loc.y = 'a';
			break;
		case 2:
			loc.y = 'b';
			break;
		case 3:
			loc.y = 'c';
			break;
		case 4:
			loc.y = 'd';
			break;
		case 5:
			loc.y = 'e';
			break;
	}
	return loc;
} 

bool match(ship shipLoc, location loc){
	if (loc.x == shipLoc.loc.x && loc.y == shipLoc.loc.y){
		return true;
	}
	else{
		return false;
	}
}

int check(const ship fleet[], location loc){
	for (int i = 0; i < FLEET_SIZE; i++){
		if (match(fleet[i], loc) == true){
			return loc.x, loc.y;
		}
		else{
			return -1;
		}
	}
}

void deploy(ship fleet[]){
	int deployedFleet = 0;
	location loc;
	ship fleet[FLEET_SIZE];
	do {
		pick();
		if (!match(fleet[deployedFleet], loc)){
			fleet[FLEET_SIZE] == deployedFleet;
			fleet.sunk = false;
			deployedFleet++;
		}
	} while (deployedFleet < FLEET_SIZE);
}

void printShip(ship s){
	cout << "Your ship is located at " << s.loc.x << s.loc.y << " and is " << s.sunk << ".\n";
}

void printFleet(const ship fleet[]){
	for (int i = 0; i < FLEET_SIZE; i++){
		cout << fleet[i].loc << " "<< fleet.sunk << ", ";
	}
}

bool operational(const ship fleet[]){
	for (int i = 0; i < FLEET_SIZE; i++){
		if (fleet[i].sunk == false)
			return true;
	}
	return false;
}

location fire(){
	cout << "Please pick a location: ";
	cin >> loc.y >> loc.x;
}

void sink(ship& s){
	s.sunk = true;
}
