#include"Doctor.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Doctor::Doctor(string playername) : Villager(playername) {
	player_name=playername;
	_has_healed = false;
}

string Doctor::get_type(){
			return "Doctor";
		}	

bool Doctor::has_healed(){
	return _has_healed;
}

bool Doctor::action(){
	_has_healed = true;
	
}
