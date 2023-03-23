#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <vector>


class Player{
	public:
		Player(std::string );

		std::string get_name();

		virtual std :: string get_type()=0;

		bool is_dead();

		bool is_silenced();

		void kill();

		void live();

		virtual bool action()=0;

		void make_silence();

	protected:
		std::string player_name;
		bool _is_dead;
		bool _is_silenced;

};

#endif
