#ifndef MAFIA_H
#define MAFIA_H
#include<string>
#include <vector>
#include"Player.h"

class Player;
class Mafia : public Player{
	public:
		Mafia(std::string );
		virtual std::string get_type();	
		virtual bool action();
};

#endif
