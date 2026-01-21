#include "Cube.h"

Cube::Cube() {
	this->length = 0;
	this->width = 0;
	this->height = 0;
}

Cube::Cube(double l, double w, double h) {
	this->length = l;
	this->width = w;
	this->height = h;
}

void Cube::SetLength(double l) {
	this->length = l;
}

double Cube::GetLength() {
	return this->length;
}

void Cube::SetWidth(double w) {
	this->width = w;
}

double Cube::GetWidth() {
	return this->width;
}

void Cube::SetHeight(double h) {
	this->height = h;
}

double Cube::GetHeight() {
	return this->height;
}

double Cube::CalculateVolume() {
	return this->height * this->length * this->width;
}