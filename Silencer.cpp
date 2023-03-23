#include"Silencer.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Silencer::Silencer(string playername) : Mafia(playername) {
	player_name=playername;
	_has_silenced = false;
}

string Silencer::get_type(){
			return "Silencer";
		}

bool Silencer::has_silenced(){
	return _has_silenced;
}		

bool Silencer::action(){
	_has_silenced = true;
}		
