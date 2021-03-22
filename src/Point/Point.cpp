#include "Point.hpp"
#include <iostream>

using namespace std;

#define X_MAX_SIZE 30
#define Y_MAX_SIZE 30
#define X_MIN_SIZE 0
#define Y_MIN_SIZE 0

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    if (x < X_MIN_SIZE || x > X_MAX_SIZE || y < Y_MIN_SIZE || y > Y_MAX_SIZE)
    {
        /* throw error */
    }

    this->x = x;
    this->y = y;
}

void Point::printPoint()
{
    cout << "(" << x << "," << y << ")" << endl;
} // mencetak point dengan format (x,y)

void Point::addX()
{
    x += 1;
    if (x > X_MAX_SIZE)
    {
        x = 0;
    }
} // menambah 1 ke sb X

void Point::addY()
{
    y += 1;
    if (y > Y_MAX_SIZE)
    {
        y = Y_MAX_SIZE;
    }
} // menambah 1 ke sb y

void Point::subX()
{
    x -= 1;
    if (x < X_MIN_SIZE)
    {
        x = X_MIN_SIZE;
    }
} // mengurangi 1 ke sb x

void Point::subY()
{
    y -= 1;
    if (y < Y_MIN_SIZE)
    {
        y = Y_MIN_SIZE;
    }
} // mengurangi 1 ke sb y

// getter
int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}

// setter
void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

bool Point::operator==(const Point& P)
{
    return (x == P.x && y == P.y);
}