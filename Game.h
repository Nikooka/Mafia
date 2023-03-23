#ifndef GAME_H
#define GAME_H
#include<string>
#include <vector>
#include "Room.h"

class Room;
class Game{
	public:
		Room* get_rooms(int );
		int get_current_room();
		bool check_duplicate(std::string );
		bool create_room(std::vector<std::string> ,std::vector<std::string> &  );
		bool switch_room (std::string );
	

	private:
		std::vector<Room*> rooms;
		int current_room;	

};

#endif
