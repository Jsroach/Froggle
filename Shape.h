//
// Created by cn345 on 12/7/2017.
//

#ifndef MCJJ_SHAPE_H
#define MCJJ_SHAPE_H

#include <cmath>
#include <iostream>
using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

class Shape {
public:
    // Constructors
    Shape();
    Shape(int xIn, int yIn);
    Shape(color f, int xIn, int yIn);

    // getters
    color getFill() const;
    double getX() const;
    double getY() const;

    // setters
    void setFill(double r, double g, double b);
    void setFill(color f);
    double setX(int xIn);
    double setY(int yIn);

    /**
     * Pure Virtual Method
     * Set up draw method for drawing rectangle graphics, used by Rectangle child class
     */
    virtual void draw() const = 0;

protected:
    color fill;
    int x = 0;
    int y = 0;
};

class Rectangle1 : public Shape {
public:
    // Constructors
    Rectangle1();
    Rectangle1(int xIn, int yIn);
    Rectangle1(color f, int xIn, int yIn);

    /**
     * Draws a rectangle in graphics using the x and y fields to construct and position vertices
     */
    void draw() const override;

};
#endif //MCJJ_SHAPE_H
