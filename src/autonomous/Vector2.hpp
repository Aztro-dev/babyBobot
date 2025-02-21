#pragma once

#include <cmath>

struct Vector2{
    double x;
    double y;

	Vector2(double x = 0.0, double y = 0.0):x(x),y(y){}
	
	Vector2 operator+(Vector2 otherVector){
		return {x + otherVector.x, y + otherVector.y};
	}

	Vector2 operator-(Vector2 otherVector){
		return {x - otherVector.x, y - otherVector.y};
	}

	Vector2 operator*(Vector2 otherVector){
		return {x * otherVector.x, y * otherVector.y};
	}

	Vector2 operator/(Vector2 otherVector){
		return {x / otherVector.x, y / otherVector.y};
	}

	inline double distanceTo(Vector2 otherVector) {
		double dx = otherVector.x-x;
		double dy = otherVector.y-y;
		return sqrt((dx*dx)+(dy*dy));
	}

	inline double degreesTo(double currentHeading, Vector2 pointToFace) {
		Vector2 dvec = (pointToFace-*this);
		return std::atan2(dvec.y,dvec.x) - currentHeading;
	}
};