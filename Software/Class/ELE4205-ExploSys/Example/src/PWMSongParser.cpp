/*
 * PWMSongParser.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: Lucas Malo Bélanger
 *  Modified on: Nov 8, 2016
 *           by: R. Gourdeau
 */

#include "PWMSongParser.h"

PWMSongParser::PWMSongParser() {
	//changez les chemins des fichiers fréquences et run ici!!!
	frequencyPath = "/sys/devices/pwm-ctrl.42/freq0";
	enablePath = "/sys/devices/pwm-ctrl.42/enable0";

	//Default duty cycle

	//Write Frequency to file
	std::ofstream file("/sys/devices/pwm-ctrl.42/duty0", std::ofstream::out | std::ofstream::trunc);
	file<<"512";
	file.close();

}

PWMSongParser::~PWMSongParser() {
	// TODO Auto-generated destructor stub
	//Write enable off to line
	std::ofstream file(enablePath.c_str(), std::ofstream::out | std::ofstream::trunc);
	file<<0;
	file.close();
}

void PWMSongParser::tone(uint32_t frequency, uint32_t length) const
{
	/*Mettez votre code ici!!!*/
	//Write Frequency to file
	std::ofstream file(frequencyPath.c_str(), std::ofstream::out | std::ofstream::trunc);
	file<<frequency;
	file.close();
	//Write enable on to line
	std::cout << "Note On! " << frequency << std::endl;
	std::ofstream file2(enablePath.c_str(), std::ofstream::out | std::ofstream::trunc);
	file2<<"1";
	file2.close();
	usleep(length * 1000);//1000
	//Write enable off to line
	std::cout << "Note Off!" << frequency << std::endl;
	std::ofstream file3(enablePath.c_str(), std::ofstream::out | std::ofstream::trunc);
	file3<<"0";
	file3.close();





}
