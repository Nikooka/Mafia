#include"Room.h"
#include<iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

Room::Room(string roomname , vector<string> rolename){
			room_name = roomname;
			role_name = rolename;
			for (int i = 0; i < rolename.size(); i++)
			{
				role_name.push_back(rolename[i]);
			}

		}



string Room::get_name(){
			return room_name;
		}

Player* Room::get_players(int i){
			
				return players[i];
		}		

bool Room::name_input_is_duplicate(string str , vector<string> & vec){
	for (int i = 0; i < vec.size(); i++)
	{
		if(str == vec[i])
			return true;
	}
	return false;
}

int Room::add_day_number(int & day_counter){
		 	day_counter ++;
		 	return day_counter;
		 	day_number = day_counter;
		}

int Room::get_day_number(){
	return day_number;
}		

bool Room::join(vector <string> command , vector<string> & roles)
		{
			bool join = false;
			vector <string> name_inputs;
			for(int i=1 ; i<command.size() ; i++){
				name_inputs.push_back(command[i]);
					if(name_input_is_duplicate( command[i] , command))
						throw "duplicated name entered";
					if(command.size() > roles.size())
						throw " many users";
					else
					{
						int random_number;    
						srand(time(0));
						random_number=rand() % roles.size();
				
						if(roles[random_number] == "-Mafia"){
							Mafia *mafia = new Mafia(command[i]);
							players.push_back(mafia);

						}
						else if(roles[random_number] == "-Villager"){
							Villager *villager = new Villager(command[i]);
							players.push_back(villager);
						}
						else if(roles[random_number] == "-Godfather"){
							Godfather *godfather = new Godfather(command[i]);
							players.push_back(godfather);
						}
						else if(roles[random_number] == "-Doctor"){
							
							Doctor *doctor = new Doctor(command[i]);
							players.push_back(doctor);
						}
						else if(roles[random_number] == "-Detective"){
							
							Detective *detective = new Detective(command[i]);
							players.push_back(detective);
						}
						else if(roles[random_number] == "-Joker"){
							
							Joker *joker = new Joker(command[i]);
							players.push_back(joker);
						}
						else if(roles[random_number] == "-Silencer"){
							
							Silencer *silencer = new Silencer(command[i]);
							players.push_back(silencer);
						}
						else if(roles[random_number] == "-RouinTan"){
							RouinTan *rouinTan = new RouinTan(command[i]);
							players.push_back(rouinTan);	
						}

					roles.erase(roles.begin() + i);	

						 if(roles.size() == 0 ){

						 	print_joined_users();
						 	join = true;

						 }
					}

			}			
			

		}

void Room::print_joined_users(){
	for (int i = 0; i <players.size() ; i++)
	{
		cout<< players[i]->get_name() <<"is"<<players[i]->get_type()<<endl;
	}
}

bool Room::check_user_available(string user_name){
	for (int i = 0; i < players.size(); i++)
	{
		if(user_name == players[i]->get_name())
			return true;
	}
	return false;
}

bool Room::check_user_dead(string user_name){
	for (int i = 0; i < players.size(); i++)
	{
		if(user_name == players[i]->get_name() && players[i] -> is_dead())
		{
			throw "‫‪Person‬‬ ‫‪is‬‬ ‫‪dead‬‬";
			return true;
		}
	}
	return false;
}

void Room::day_vote(string voter , string votee){
	if(!check_user_available(voter))
		throw "‫‪User‬‬ ‫‪not‬‬ ‫‪joined‬‬";
	if(!check_user_available(votee))
		throw "User not joined";
	for (int i = 0; i < players.size(); i++)
	{
		if(voter == players[i]->get_name())
			if(players[i] -> is_silenced())
				throw "‫‪This‬‬ ‫‪user‬‬ ‫‪has‬‬ ‫‪been‬‬ ‫‪silenced‬‬ ‫‪before‬‬";

		if(votee == players[i]->get_name())			
			if(players[i]-> is_dead() )
				throw "‫‪User‬‬ ‫‪already‬‬ ‫‪died‬‬";
			
	}

	for (int j = 0; j < players.size() ; j++)
	{
		if(players[j]-> get_name() == votee)
			_day_vote.push_back(players[j]);
	}


}

bool Room::night_vote(string voter , string votee){
	bool night_vote = false;
	if(!check_user_available(voter))
		throw "‫‪User‬‬ ‫‪not‬‬ ‫‪joined‬‬";
	if(!check_user_available(votee))
		throw "User not joined";
	for (int i = 0; i < players.size(); i++)
	{
			if(players[i] -> get_type() != "Mafia" || "Godfather" )
				throw "‫‪‫‪This‬‬ ‫‪user‬‬ ‫‪can‬‬ ‫‪not‬‬ ‫‪vote‬‬";
			else
			{
				while(players[i] -> get_name() =="Mafia" || "RouinTan")
				{	

					for (int j = 0; j < players.size(); j++)
					{
						if(players[j] -> get_name() == votee)
							_night_vote.push_back(players[j]);
					}

				}
				night_vote = true;
			}


	}

}


void Room::print_dead_user_day(Player* player)
{
	cout<<"Mafia try to kill "<<player -> get_name();
}

void Room::print_dead_user_night(Player* player)
{
	cout<<"Died "<<player -> get_name();
}

int Room::find_max(vector <int> count)
{
	int max = count[0];
	int index_of_max = 0;
	for (int i = 1; i < count.size(); i++)
	{
		if(count[i] > max)
		{
			max = count[i];
			index_of_max = i;
		}
	}

	return index_of_max;
}

void Room::count_day_votes()
{
	vector <int> count_numbers(_day_vote.size() , 0);
	for (int i = 0; i < _day_vote.size() ; i++)
	{

		++count_numbers[count (_day_vote.begin(), _day_vote.end(), _day_vote[i])];
	}

	_day_vote[find_max(count_numbers)] -> kill();

	print_dead_user_day(_day_vote[find_max(count_numbers)]);
	_day_vote.clear();
}

void Room::count_night_votes()
{
	vector <int> count_numbers(_night_vote.size() , 0);
	for (int i = 0; i < _night_vote.size() ; i++)
	{

		++count_numbers[count (_night_vote.begin(), _night_vote.end(), _night_vote[i])];
	}

	_night_vote[find_max(count_numbers)] -> kill();

	print_dead_user_night(_night_vote[find_max(count_numbers)]);
	_night_vote.clear();
}


int Room::number_of_alive_Mafia()
{
	int number_of_mafia;
	int number_of_godfather;
	int number_of_silencer;
	for (int i = 0; i < players.size(); ++i)
	{
		if(players[i] -> get_type() == "Mafia")
		{
			if(!players[i]-> is_dead())
				number_of_mafia = count (players.begin(), players.end(), players[i]);
		}
		if(players[i] -> get_type() == "Godfather")
		{
			if(!players[i]-> is_dead())
				number_of_godfather = count (players.begin(), players.end(), players[i]);
		}
		if(players[i] -> get_type() == "Silencer")
		{
			if(!players[i]-> is_dead())
				number_of_silencer = count (players.begin(), players.end(), players[i]);
		}	
	}
	int number_of_mafias = number_of_mafia + number_of_silencer + number_of_godfather;
	return number_of_mafias;
}

int Room::number_of_alive_Villager()
{
	int number_of_villager;
	int number_of_rouintan;
	int number_of_doctor;
	int number_of_detective;
	for (int i = 0; i < players.size(); ++i)
	{
		if(players[i] -> get_type() == "Villager")
		{
			if(!players[i]-> is_dead())
				number_of_villager = count (players.begin(), players.end(), players[i]);
		}
		if(players[i] -> get_type() == "RouinTan")
		{
			if(!players[i]-> is_dead())
				number_of_rouintan = count (players.begin(), players.end(), players[i]);
		}
		if(players[i] -> get_type() == "Doctor")
		{
			if(!players[i]-> is_dead())
				number_of_doctor = count (players.begin(), players.end(), players[i]);
		}	
		if(players[i] -> get_type() == "Detective")
		{
			if(!players[i]-> is_dead())
				number_of_detective = count (players.begin(), players.end(), players[i]);
		}
	}
	int number_of_villagers = number_of_villager + number_of_rouintan + number_of_doctor + number_of_detective;
	return number_of_villagers;
}

void Room::ask(string name)
{
	for (int i = 0; i < players.size(); ++i)
	{
		if(players[i] -> get_name() == name)
			if(players[i] -> get_type() == "Godfather" || players[i] -> get_type() != "Mafia")
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;

	}

}

bool Room::detect(string detective , string suspect ){
	if(!check_user_available(detective))
		throw "‫‪User‬‬ ‫‪not‬‬ ‫‪joined‬‬";
	if(!check_user_available(suspect))
		throw "User not joined";
	if(check_user_dead(suspect))
		throw "‫‪Person‬‬ ‫‪is‬‬ ‫‪dead‬‬";
	for (int i = 0; i < players.size(); i++)
	{
		if(players[i] -> get_name() == detective)
			if(players[i] -> get_type() != "Detective" || players[i] -> is_dead())
				throw "‫‪User‬‬ ‫‪can‬‬ ‫‪not‬‬ ‫‪ask‬‬";
			// if(players[i] -> has_asked())
			// 	throw "‫‪Detective‬‬ ‫‪has‬‬ ‫‪alreay‬‬ ‫‪asked‬‬";
			else
			{
				players[i] -> action();
				ask(suspect);

			}
	}
	

}

void Room::make_alive(string name)
{
	for (int i = 0; i < players.size(); ++i)
	{
		if(players[i] -> get_name() == name )
			players[i] -> live();


	}
}

bool Room::heal( string doctor , string person ){
	if(!check_user_available(doctor))
		throw "‫‪User‬‬ ‫‪not‬‬ ‫‪joined‬‬";
	if(!check_user_available(person))
		throw "User not joined";
	if(check_user_dead(person))
		throw "‫‪Person‬‬ ‫‪is‬‬ ‫‪dead‬‬";
	for (int i = 0; i < players.size(); i++)
	{
		if(players[i] -> get_name() == doctor)
			if(players[i] -> get_type() !="Doctor" || players[i] -> is_dead())
				throw "‫‪User‬‬ ‫‪can‬‬ ‫‪not‬‬ ‫‪heal‬‬";	
			// if(players[i] -> has_healed())
			// 	throw "‫‪Doctor‬‬ ‫‪has‬‬ ‫‪alreay‬‬ ‫‪healed‬‬";
			else
			{
				players[i] -> action();
				make_alive(person);

			}
	}

}

bool Room::silent(string silencer , string person ){
	if(!check_user_available(silencer))
		throw "‫‪User‬‬ ‫‪not‬‬ ‫‪joined‬‬";
	if(!check_user_available(person))
		throw "User not joined";
	if(check_user_dead(person))
		throw "‫‪Person‬‬ ‫‪is‬‬ ‫‪dead‬‬";

	for (int i = 0; i < players.size(); i++)
	{
		if(players[i] -> get_type() == silencer )
			if(players[i] -> get_name() != "Silencer" || players[i] -> is_dead() )
				throw "‫‪User‬‬ ‫‪can‬‬ ‫‪not‬‬ ‫‪silence‬‬";	
			// if(players[i] -> has_silenced())
			// 	throw "‫‪Silencer‬‬ ‫‪has‬‬ ‫‪alreay‬‬ ‫‪silenced‬‬";
			else
			{
				players[i] -> action();
				for (int j = 0; j < players.size(); ++j)
				{
					if(players[j] -> get_name() == person)
						players[j] -> make_silence();
				}

			}

	}
	
}
