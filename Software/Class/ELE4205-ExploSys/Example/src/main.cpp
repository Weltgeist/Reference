/*
 * main.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: Lucas Malo Bélanger
 */

#include "PWMSongParser.h"
int main(int argc, char** argv)
{
	//remplacez SongParser par PWMSongParser!!!
	//SongParser met les actions note on, note off ainsi que la fréquence dans l'invite de commande avec les timings précis
	PWMSongParser parser;
	//SongParser parser;
	
	//lecture du fichier song.txt
	//FAQ: si vous avez des erreurs de std::string assign, c'est que le fichier n'est pas dans le chemin de l'exécutable!
	parser.readFile("song.txt");
	
	//On joue la musique
	parser.play();
	return 0;
}

