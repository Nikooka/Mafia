#include"Godfather.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Godfather::Godfather(string playername) :Mafia(playername){
	player_name=playername;
}

string Godfather::get_type(){
			return "Godfather";
		}

bool Godfather::action(){
	
}		
