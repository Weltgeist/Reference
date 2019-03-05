/*
 * SongParser.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: Lucas Malo Bélanger
 */

#include "SongParser.h"

SongParser::SongParser() {
	// TODO Auto-generated constructor stub
	readFile("song.txt");
}

SongParser::~SongParser() {
	// TODO Auto-generated destructor stub
	_commands.clear();

}

void SongParser::readFile(std::string filename)
{
	std::string data1,data2,data3, data4, data5, frequency, length, delay;
	_commands.clear();

	command c;

	std::ifstream file(filename.c_str(), std::ifstream::in);
	while(!file.eof())
	{
		file >> data1 >> data2 >> data3;
		file.ignore(1);

		file >> data4 >> data5;
		file.ignore(1);

		frequency.assign(data2, 10,3);
		length.assign(data3,7,3);
		delay.assign(data5, 0, 3);

		c.frequency = atoi(frequency.c_str());
		c.delay = atoi(delay.c_str());
		c.length = atoi(length.c_str());

		_commands.push_back(c);
	}
}
const std::vector<SongParser::command>& SongParser::getCommands() const
{
	return _commands;
}
void SongParser::play() const
{
	const std::vector<command>& commands = getCommands();
	for(std::vector<command>::const_iterator it = commands.begin(); it != commands.end(); it++)
	{
		tone(it->frequency,it->length);
		usleep((it->delay - it->length) * 1000);
	}
}

void SongParser::tone(uint32_t frequency, uint32_t length) const
{
	std::cout << "Note On! " << frequency << std::endl;
	usleep(length * 1000);

	//note if off
	std::cout << "Note Off!" << frequency << std::endl;
}
