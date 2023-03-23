#ifndef VILLAGER_H
#define VILLAGER_H
#include<string>
#include <vector>
#include "Player.h"

class Player;
class Villager : public Player{
	public:
		Villager(std::string );

		virtual std::string get_type();


		virtual bool action();


};


#endif
