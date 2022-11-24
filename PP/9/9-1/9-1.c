#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
} Point;

void printPoint(Point p)
{
    printf("(%.1lf,%.1lf)", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;

    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow((b.x - a.x), 2) + pow ((b.y - a.y), 2));
}

int main()
{
    printPoint(createPoint(2.0, -3.0));
    printPoint(createPoint(-4.0, 5.0));

    getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));

    return 0;
}