#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Utilize.h"

using namespace std;

int main()
{
	Game game;
	string line="";
	while(getline(cin,line))
	{
		try{
			if(!Utilize::command_interpreter(line,game))
				throw "Invalid Command";
		}	
		catch(const char* msg){
			cerr << msg << endl;
		}

	}
return 0;
}
