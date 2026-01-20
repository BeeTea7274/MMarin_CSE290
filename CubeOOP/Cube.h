#pragma once

class Cube() {
public:
	Cube(double, double, double);
	void CalculateVolume();

private:
	double length;
	double height;
	double width;
};