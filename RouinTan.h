#ifndef ROUINTAN_H
#define ROUINTAN_H
#include<string>
#include <vector>
#include "Player.h"
#include "Villager.h"

class Villager;
class Player;
class RouinTan : public Villager{
	public:
		RouinTan(std::string );
		virtual std::string get_type();
		virtual bool action();
	private:
		bool extra_life;	
};

#endif
