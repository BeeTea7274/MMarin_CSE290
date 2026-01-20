#pragma once

class Square {
public:
	Square(double, double);
	Square();
	double CalculateArea();
	void SetWidth(double);
	double GetWidth();
	void SetLength(double);
	double GetLength();
private:
	double width;
	double length;
};