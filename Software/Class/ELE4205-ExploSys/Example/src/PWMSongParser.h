/*
 * PWMSongParser.h
 *
 *  Created on: Aug 13, 2015
 *      Author: Lucas Malo Bélanger
 */

#ifndef PWMSONGPARSER_H_
#define PWMSONGPARSER_H_

#include "SongParser.h"
class PWMSongParser: public SongParser{
public:
	PWMSongParser();
	virtual ~PWMSongParser();

	//les chemins absolus des fichiers fréquence et run
	std::string frequencyPath;
	std::string enablePath;
private:
	//votre implémentation de la fonction tone!!!
	virtual void tone(uint32_t frequency, uint32_t length) const;
};

#endif /* PWMSONGPARSER_H_ */
