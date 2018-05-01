//
// Created by Administrator on 2018-05-01.
//

#ifndef CAR_CAR_H
#define CAR_CAR_H

class Car
{
public:
	double rps; // Revolutions Per Second
	double width; // distance between both car tires
	double scanerDistance; // distance between center of car tires and (ultrasonic sensor & servo motor)
	double headerDistance; // distance between center of car tires and head of car
	double footerDistance; // distance between center of car tires and tail of car

public:
	void setRPS(double rps);
	void setWidth(double width);
	void setScanerDistance(double scanerDistance);
	void setHeaderDistance(double headerDistance);
	void setFooterDistance(double footerDistance);

};

#endif //CAR_CAR_H
