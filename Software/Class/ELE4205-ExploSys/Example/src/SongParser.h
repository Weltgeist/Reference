/*
 * SongParser.h
 *
 *  Created on: Aug 13, 2015
 *      Author: Lucas Malo Bélanger
 */

#ifndef SONGPARSER_H_
#define SONGPARSER_H_

#include <string>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>

class SongParser {
public:
	SongParser();
	virtual ~SongParser();

	//lecture du fichier qui contien la musique
	void readFile(std::string filename);
	
	//la musique est jouée
	virtual void play() const;

private:
	//les commandes possible
	struct command
	{
		uint32_t frequency;
		uint32_t length;
		uint32_t delay;
	};
	
	//la liste des commandes qui composent la musique
	std::vector<command> _commands;
protected:
	const std::vector<command>& getCommands() const;

	//la fonction tone!! Vous devez héritez de cette fonction dans PWMTest
	virtual void tone(uint32_t frequency, uint32_t length) const;
};

#endif /* SONGPARSER_H_ */
