#include"Player.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;

Player::Player(string playername){
			_is_dead = false;
			_is_silenced = false;
		}
bool Player::is_dead(){
	return _is_dead;
}

bool Player::is_silenced(){
	return _is_silenced;
}

string Player::get_name(){
			return player_name;
		}		

void Player::kill(){
	_is_dead = true;
}

void Player::live(){
	_is_dead =false;
}

void Player::make_silence(){
	_is_silenced = true;
}

