#ifndef JOKER_H
#define JOKER_H
#include<string>
#include <vector>
#include "Player.h"

class Player;
class Joker : public Player{
	public:
		Joker(std::string );
		virtual std::string get_type();	
		virtual bool action();
};

#endif
