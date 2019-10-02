/*
	M. Geiger
	EECE.3220: Data Structures
	Rectangle example code for in-class composition example
	Function definitions
*/

#include "Rectangle.h"

// Default constructor
Rectangle::Rectangle() {
	height = width = 0;
	// Point default constructor called for origin
}

// Parameterized constructor
Rectangle::Rectangle(double h, double w, double x, double y) : 
	height(h), width(w), origin(x, y)
{}
	
// "Get" functions
double Rectangle::getHeight() {
	return height;
}

double Rectangle::getWidth() {
	return width;
}

Point Rectangle::getOrigin() {
	return origin;
}

// "Set" functions
void Rectangle::setHeight(double h) {
	height = h;
}

void Rectangle::setWidth(double w) {
	width = w;
}

void Rectangle::setOrigin(Point p) {
	origin = p;
}
	
// Return area of rectangle
double Rectangle::area() {
	return width * height;
}

void Rectangle::setOrigin(double x, double y) {
	origin.setX(x);
	origin.setY(y);
}