#include "Utilize.h"
#include <vector>
#include <string>
using namespace std;

void split(const string& s, char c,
		           vector<string>& v) {
		   string::size_type i = 0;
		   string::size_type j = s.find(c);
		   while (j != string::npos) {
		      v.push_back(s.substr(i, j-i));
		      i = ++j;
		      j = s.find(c, j);

		      if (j == string::npos)
		         v.push_back(s.substr(i, s.length()));
		   }
		}

bool Utilize::command_interpreter(string Command, Game &g)
		{
			bool is_day = false;
			int time = 0;
			vector<string> command_section;
			vector<string> rolles;
			split(Command, char(32), command_section);
			//Room room;
			if(command_section.size()>0)

			if(command_section[0]=="Create_room"){
					if(g.check_duplicate(command_section[1]))
						throw "Room name is duplicated";
					else
						g.create_room(command_section, rolles);
				
				return true;
			}

			else if(command_section[0]=="Switch_room"){
				g.switch_room(command_section[1]);
				return true;
			}

			else if(command_section[0]=="‫‪Get_room_state‬‬"){
 				cout<< "‫‪Mafia‬‬ = "<< g.get_rooms(g.get_current_room())-> number_of_alive_Mafia() <<endl;
 				cout<< "‫‪Villager‬‬ = " << g.get_rooms(g.get_current_room())-> number_of_alive_Villager()<<endl;
				return true;
			}			

			else if(command_section[0]=="Join"){
				if(g.get_rooms(g.get_current_room()) -> join(command_section , rolles))
				{
					cout<<"Day"<< g.get_rooms(g.get_current_room())->add_day_number(time) <<endl;
					is_day = true;

				}
				return true;
			}

			else if(is_day && command_section[0] == "Vote"){
			 	g.get_rooms(g.get_current_room())-> day_vote(command_section[1] , command_section[2]);
			 	cout<<"Day"<< g.get_rooms(g.get_current_room())-> get_day_number()<<endl;
			 	return true;
			}

			else if(is_day && command_section[0] == "‫‪End_vote‬‬"){
				g.get_rooms(g.get_current_room())-> count_day_votes();
				is_day = false;
				cout<<"Night"<<g.get_rooms(g.get_current_room())-> get_day_number()<<endl;
				return true;
			}

			else if(!is_day && command_section[0] == "Vote"){

				if(g.get_rooms(g.get_current_room())-> night_vote(command_section[1] , command_section[2]));
					g.get_rooms(g.get_current_room()) -> count_night_votes();
				cout<<"Night"<<g.get_rooms(g.get_current_room())-> get_day_number()<<endl;	
			 	return true;
			}

			else if(!is_day && command_section[0] == "Detect"){
				g.get_rooms(g.get_current_room()) -> detect(command_section[1] , command_section[2]);
				cout<<"Night"<<g.get_rooms(g.get_current_room())-> get_day_number()<<endl;
				return true;
			}

			else if(!is_day && command_section[0] == "Heal"){

				g.get_rooms(g.get_current_room()) -> heal(command_section[1] , command_section[2]);
				cout<<"Night"<<g.get_rooms(g.get_current_room())-> get_day_number()<<endl;
				return true;
			}

			else if(!is_day && command_section[0] == "Silent"){
				g.get_rooms(g.get_current_room()) ->  silent(command_section[1] , command_section[2]);
				cout<<"Day"<< g.get_rooms(g.get_current_room())->add_day_number(time) <<endl;
				return true;
			}
			
			return false;

		}
