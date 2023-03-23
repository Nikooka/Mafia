#include"RouinTan.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

RouinTan::RouinTan(string playername) : Villager(playername) {
	player_name=playername;
	extra_life = true;
}

string RouinTan::get_type(){
			return "RouinTan";
		}
bool RouinTan::action(){
	
}
