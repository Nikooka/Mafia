#ifndef ROOM_H
#define ROOM_H
#include<string>
#include <vector>
#include "Player.h"
#include "RouinTan.h"
#include "Detective.h"
#include "Doctor.h"
#include "Godfather.h"
#include "Silencer.h"
#include "Joker.h"
#include "Villager.h"
#include "Mafia.h"

class Player;
class RouinTan;
class Detective;
class Doctor;
class Godfather;
class Silencer;
class Joker;
class Villager;
class Mafia;
class Room{

	public:

		int add_day_number(int & );
		int get_day_number();
		Room(std::string , std::vector<std::string> );
		Player* get_players(int );
		std::string get_name();
		bool name_input_is_duplicate(std::string , std::vector<std::string> & );
		bool join(std::vector <std::string>  , std::vector<std::string> & );
		void print_joined_users();
		bool check_user_available(std::string );
		bool check_user_dead(std::string );
		void day_vote(std::string , std::string );
		bool night_vote(std::string , std::string );
		void print_dead_user_day(Player* );
		void print_dead_user_night(Player* );
		int find_max(std::vector <int> );
		void count_day_votes();
		void count_night_votes();
		int number_of_alive_Mafia();
		int number_of_alive_Villager();
		bool detect(std::string , std::string );
		bool heal(std::string , std::string );
		bool silent(std::string , std::string );
		void make_alive(std::string );
		void ask(std::string );


	private:
		std::string room_name;
		std::vector<std::string> role_name;
		std::vector<Player*> players;
		std::vector<Player*> _day_vote;
		std::vector<Player*> _night_vote;
		int day_number;

};
#endif
