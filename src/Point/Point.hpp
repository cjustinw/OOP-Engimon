#ifndef __POINT_HPP__
#define __POINT_HPP__

#define X_MAX_SIZE 30
#define Y_MAX_SIZE 30
#define X_MIN_SIZE 0
#define Y_MIN_SIZE 0

class Point
{
public:
    Point();
    Point(int x, int y);

    void printPoint();

    void addX();
    // menambah 1 ke sb X
    void addY();
    // menambah 1 ke sb y
    void subX();
    // mengurangi 1 ke sb x
    void subY();
    // mengurangi 1 ke sb y

    // getter
    int getX();
    int getY();

    // setter
    void setX(int x);
    void setY(int y);

    bool operator==(const Point& P);

private:
    int x;
    int y;
};

#endif