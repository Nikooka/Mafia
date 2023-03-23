#include"Detective.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Detective::Detective(string playername) : Villager(playername) {
	player_name=playername;
	_has_asked = false;
}

string Detective::get_type(){
			return "Detective";
		}

bool Detective::action(){
	_has_asked = true;
}		

bool Detective::has_asked(){
	return _has_asked;
}
