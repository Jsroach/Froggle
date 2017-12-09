//
// Created by cn345 on 12/7/2017.
//
#include "Shape.h"
#include "graphics.h"

Shape::Shape() {
    fill = {0, 0, 0};
}

Shape::Shape(int xIn, int yIn) {
    x = xIn;
    y = yIn;
}

Shape::Shape(color f, int xIn, int yIn){
    x = xIn;
    y = yIn;
    fill = f;
}

color Shape::getFill() const {
    return fill;
}
double Shape::getX() const {
    return x;
}
double Shape::getY() const {
    return y;
}

void Shape::setFill(double r, double g, double b) {
    fill = {r, g, b};
}
void Shape::setFill(color f) {
    fill = f;
}

double Shape::setX(int xIn) {
    x = xIn;
}
double Shape::setY(int yIn) {
    y = yIn;
}

//-------------------------------------------------------------------------------------------

Rectangle1::Rectangle1() {
    setFill(0,0,0);
    setX(0);
    setY(0);
}
Rectangle1::Rectangle1(int xIn, int yIn) {
    setX(xIn);
    setY(yIn);
}
Rectangle1::Rectangle1(color f, int xIn, int yIn) {
    setFill(f);
    setX(xIn);
    setY(yIn);
}

void Rectangle1::draw() const {
    glColor3f(fill.red, fill.green, fill.blue); // set color
    glBegin(GL_QUADS);
    glVertex2i(getX(), getY()); //set vertex
    glVertex2i(getX()+150,getY());
    glVertex2i(getX()+150, getY()+50);
    glVertex2i(getX(), getY()+50);
    glEnd();
}
