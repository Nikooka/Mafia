#include"Mafia.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Mafia::Mafia(string playername) : Player(playername){
	playername = player_name;
}

string Mafia::get_type(){
			return "Mafia";
		}	

bool Mafia::action(){
	
}
