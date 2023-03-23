#ifndef DETECTIVE_H
#define DETECTIVE_H
#include<string>
#include <vector>
#include "Player.h"
#include "Villager.h"

class Player;
class Villager;
class Detective : public Villager{
	public:
		Detective(std::string );
		virtual std::string get_type();
		virtual bool action();
		bool has_asked();

	private:
		bool _has_asked;	

};

#endif
