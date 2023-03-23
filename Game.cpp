#include"Game.h"
#include<iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

Room* Game::get_rooms(int i){
			
				return rooms[i];
		}

int Game::get_current_room(){
			return current_room;
		}

bool Game::check_duplicate(string str){
			for(int i=0 ; i<rooms.size() ; i++)
				{
					if(rooms[i]->get_name() == str)
						return true;
				}
			return false;
		}

bool Game::create_room(vector<string> command , vector<string> & roles)
		{
			int special_Mafia = 0;
			int special_Villager = 0;
			string rolesArr[] = {"-Mafia" , "-Villager" , "-Godfather" , "-Doctor" , "-Detective" , "-RouinTan" , "-Silencer" , "-Joker"};
			for(int i=2 ; i<command.size() ; i++)
			{
				if(command[i].at(0) == '-')
				{
					for (int j = 0; j <8 ; j++)
					{
						if(command[i]!= rolesArr[j])
							throw "Invalid role name";
						else
						{
							stringstream geek(command[i+1]);
							int number;
							geek >> number;
							if(command[i] == "-Godfather" || "-Silencer")
								special_Mafia ++ ;
							if(command[i] == "-Doctor" || "-Detective" || "-RouinTan")
								special_Villager ++;
							if(command[i] == "-Mafia" && number < special_Mafia)
								throw "Number of special Mafia is invalid";
							if(command[i] == "-Villager" && number < special_Villager)
								throw "Number of special Villager is invalid";
							else
							{
								for (int k = 0; k <number; k++)
								{
									roles.push_back(command[i]);
								}
							}	
						}	
					}		
				}
			}

					Room *room = new Room(command[1] , roles);
					rooms.push_back(room);
					current_room = 1;
		}
		

bool Game::switch_room (string str){
			for(int i=0 ; i<rooms.size() ; i++)
				if(rooms[i]->get_name() == str)
					current_room = i;
				else 
					throw "room doesn't exist";			
		}
