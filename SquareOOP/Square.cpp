#include "Square.h"

Square::Square() {
	this->length = 0;
	this->width = 0;
}

Square::Square(double l, double w) {
	this->length = l;
	this->width = w;
}

double Square::CalculateArea() {
	return this->length * this->width;
}

void Square::SetLength(double l) {
	this->length = l;
}

void Square::SetWidth(double w) {
	this->width = w;
}

double Square::GetLength() {
	return this->length;
}

double Square::GetWidth() {
	return this->width;
}