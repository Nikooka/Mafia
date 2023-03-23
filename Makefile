COMPILER = g++
COMPILER_FLAGS = --std=c++98
a.out: main.o Utilize.o Game.o Room.o Player.o Joker.o Mafia.o Villager.o Godfather.o Silencer.o Detective.o Doctor.o RouinTan.o
	${COMPILER} ${COMPILER_FLAGS} main.o Utilize.o Game.o Room.o Player.o Joker.o Mafia.o Villager.o Godfather.o Silencer.o Detective.o Doctor.o RouinTan.o	

main.o: main.cpp Utilize.o Game.h
	${COMPILER} ${COMPILER_FLAGS} -c main.cpp

Utilize.o: Utilize.cpp Utilize.h Game.h
	${COMPILER} ${COMPILER_FLAGS} -c Utilize.cpp

Game.o: Game.cpp Game.h Room.h
	${COMPILER} ${COMPILER_FLAGS} -c Game.cpp

Room.o: Room.cpp Room.h Player.h
	${COMPILER} ${COMPILER_FLAGS} -c Room.cpp

Player.o: Player.cpp Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Player.cpp

Mafia.o: Mafia.cpp Mafia.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Mafia.cpp

Villager.o: Villager.cpp Villager.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Villager.cpp

Joker.o: Joker.cpp Joker.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Joker.cpp

Godfather.o: Godfather.cpp Godfather.h Mafia.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Godfather.cpp

Silencer.o: Silencer.cpp Silencer.h Mafia.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Silencer.cpp

Detective.o: Detective.cpp Detective.h Villager.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Detective.cpp

Doctor.o: Doctor.cpp Doctor.h Villager.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c Doctor.cpp

RouinTan.o: RouinTan.cpp RouinTan.h Villager.h Player.h 
	${COMPILER} ${COMPILER_FLAGS} -c RouinTan.cpp

clean:
	rm *.o
	rm a.out
