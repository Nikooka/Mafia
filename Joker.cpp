#include"Joker.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Joker::Joker(string playername) : Player(playername){
	player_name=playername;
}

string Joker::get_type(){
			return "Joker";
		}

bool Joker::action(){
	
}
