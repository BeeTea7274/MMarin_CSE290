#pragma once

class Cube{
public:
	Cube();
	Cube(double, double, double);
	void SetLength(double l);
	double GetLength();
	void SetWidth(double w);
	double GetWidth();
	void SetHeight(double h);
	double GetHeight();
	double CalculateVolume();
private:
	double length;
	double width;
	double height;
};