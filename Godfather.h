#ifndef GODFATHER_H
#define GODFATHER_H
#include<string>
#include <vector>
#include "Player.h"
#include "Mafia.h"

class Player;
class Mafia;
class Godfather : public Mafia{
	public:
		Godfather(std::string );
		virtual std::string get_type();
		virtual bool action();
};

#endif
