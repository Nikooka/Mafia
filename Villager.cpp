#include"Villager.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Villager::Villager(string playername) : Player(playername)
	 {
	 	
	 }

string Villager::get_type(){
			return "Villager";
		}

bool Villager::action(){
	
}		
