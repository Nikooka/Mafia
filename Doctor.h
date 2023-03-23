#ifndef DOCTOR_H
#define DOCTOR_H
#include<string>
#include <vector>
#include "Player.h"
#include "Villager.h"

class Player;
class Villager;
class Doctor : public Villager{
	public:
		Doctor(std::string );
		virtual std::string get_type();
		virtual bool action();
		bool has_healed();
	private:
		bool _has_healed;	
};


#endif
