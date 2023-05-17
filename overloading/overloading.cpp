// Overload the plus(+) operator such that two points added together create a new point with the coordinates added together.

#include <stdio.h>

class Point {
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };
    void print() {
        printf("(%d, %d)\n", this->x, this->y);
    }
    Point operator+(Point ducky) {
        int x = this->x + ducky.x;
        int y = this->y + ducky.y;
        return Point(x, y);
    }

    int x;
    int y;
};

int main()
{
    Point point1(7, 10);
    Point point2(3, -13);

    Point point3 = point1 + point2;
    point3.print(); // should print (10, -3)
}