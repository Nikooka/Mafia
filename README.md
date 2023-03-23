# Mafia
This project was for my Advanced Programming course - Dec. 2018

In this project, a system is presented to help the god of the mafia game to manage it. This program saves all the events and flow of the game and helps the god of the game in announcing the result.


## Game description:
The mafia game consists of a number of roles that are randomly assigned to players. The roles implemented in this program are:
Joker, Villager, Detective, Doctor, RouinTan, Mafia, GodFather, Silencer

In the classic game, people are divided into two categories: mafia and citizen. People do not know each other's role in the game and the roles are confidential. The game continues in 2 phases, day and night. In the day phase, all the people who are still alive start to discuss and try to find the mafia members. After that, they can kill one of the people they suspect with the majority vote of the living. On the other hand, mafia members try to distract the other players in the day phase so that they can survive. But in the night phase, mafia members can know each other and with each other's complicity and voting, kill one person and remove them from the game. In the night phase, the rest of the mafia members and citizens have different functions according to their specific role, which will be explained below.

### Roles of citizens:
• **Detective:** He can choose a person every night and ask the program if this person is a mafia or not. The program should always give the correct answer, except when the person asked is a godfather. 


• **Doctor:** He can kill a person every night by choosing him, so if the person who has become immortal is chosen to be killed by the mafia, he will be saved and will not be killed in that night. Also, no one realizes that this person was chosen by the mafia to be killed.


• **RouinTan:** If he is chosen by the mafia to be killed at night because he has an extra life, he will be saved and no one (not even himself) will know that he was going to be killed by the mafia. But the second time he is chosen by the mafias, he will not have extra lives and will really die.


### Roles of mafia members:
• **GodFather:** He is a member of the mafia, if the detective asks about his membership in the mafia in the program, even though he is a mafia member, the detective is informed that he is not a member of the mafia.

• **Silencer:** He can choose a person every night and the person who is chosen cannot speak or comment during the next day and the voting of that day.


• **Joker:** Joker is not in any of the mafia and citizen groups. Also, he breaks the rules of winning and losing the game! If the Joker is in the game and is killed within a day of voting, he wins the game! And all other players lose.
Install Makefile

## Part 1: Creating a new game
First, God must create a new room with the `room_Create` command. Each room specifies a round of the game and all the information of a complete round of the game is kept inside the corresponding room. This command first takes the name of the room and then for each role, it receives the name and number of players who are placed in that role.
The roles in this order can be any of the roles introduced at the beginning and appear in any desired order.
command format `Create_room <room_name> (- <role_name> <number>)`


## Part 2: Switching Rooms 
Following command switches between the available rooms. At any moment during the execution of the program, God can execute any of the commands `room_Switch` and `room_Create.`
command format `Switch_room <room_name>`


## Part 3: Adding Players
After creating and selecting the desired room, God will add the players using their names using the `Join` command. When the number of players is exactly equal to the number of defined roles, the program randomly assigns a role to each player.
command format `Join (<user_name>)`

## Part 4: Voting on the day
At the beginning of each day, God specifies who each player has voted for.
command format `Vote <voter_name> <votee_name>`

## Part 5: End of the day's voting and announcing the results
command format `End_vote`

## Part 6: Mafia voting at night
command format `Vote <voter name> <votee_name>`


## Part 7: The detective's inquiry
command format `Detect <detective_name> <suspect_name>`


## Part 8: Saving the doctor
command format `Heal <doctor_name> <person_name>`

## Part 9: Silencing the silencer
command format `Silent <silencer name> <person>`

## Room State: 
With this command, you can get the number of mafia members and polices in each part of the game:
command format `Get_room_state`

Install Makefile and then run main.cpp


Enjoy! 


