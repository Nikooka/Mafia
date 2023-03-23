#ifndef SILENCER_H
#define SILENCER_H
#include<string>
#include <vector>
#include "Player.h"
#include "Mafia.h"

class Player;
class Mafia;
class Silencer : public Mafia{
	public:
		Silencer(std::string );
		virtual std::string get_type();
		virtual bool action();
		bool has_silenced();
	private:
		bool _has_silenced;	
};

#endif
