#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
using namespace std;

Shape::Shape()
{
    // Start at a random position and speed
    x = (float)(rand() % WIDTH);
    y = (float)(rand() % HEIGHT);
    deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
    deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}

Shape::~Shape()
{
}

void Shape::updateCoordinates()
{
    x += deltaX;
    y += deltaY;

    // Check if we hit the edge of the screen and if we did
    // move it back so it fits and then change the direction
    if (x >= WIDTH)
    {
        x -= deltaX;
        // deltaX is positive, so make it negative
        deltaX *= -1;
    }
    else if (x < 0)
    {
        deltaX *= -1; // deltaX is negative, so make it positive
        x += deltaX; // add it in so we are not off the edge
    }
    if (y >= HEIGHT)
    {
        y -= deltaY; // Same for the Y directions
        deltaY *= -1;
    }
    else if (y < 0)
    {
        deltaY *= -1;
        y += deltaY;
    }
}

Square::Square(int value)
{
    diameter = value;
}

Square::~Square()
{
}

void Square::draw()
{
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(x - (diameter / 2), y - (diameter / 2));
    glVertex2f(x + (diameter / 2), y - (diameter / 2));
    glVertex2f(x + (diameter / 2), y + (diameter / 2));
    glVertex2f(x - (diameter / 2), y + (diameter / 2));
    glEnd();
}

Circle::Circle(int value)
{
    radius = value;
}

Circle::~Circle()
{
}

void Circle::draw()
{
    glColor3f(0, 5, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float angle = 0; angle < 360; angle += 1)
    {
        glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
    }
    glEnd();
}

MultiColorCircle::MultiColorCircle(int value)
{
    radius = value;
}

MultiColorCircle::~MultiColorCircle()
{
}

void MultiColorCircle::draw()
{
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float angle = 0; angle < 360; angle += 1)
    {
        glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
    }
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float angle = 0; angle < 360; angle += 1)
    {
        glVertex2f(x + sin(angle) * radius * 2.0 / 3, y + cos(angle) * radius * 2.0 / 3);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (float angle = 0; angle < 360; angle += 1)
    {
        glVertex2f(x + sin(angle) * radius * 1.0 / 3, y + cos(angle) * radius * 1.0 / 3);
    }
    glEnd();
}

