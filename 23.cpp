#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double len() const {return hypot(x,y);}
    double phi() const {return atan2(y,x);}
    Point operator+(Point p) const {return {x + p.x,y + p.y};}
    Point operator-(Point p) const {return {x - p.x,y - p.y};}
    double operator*(Point p) const {return x * p.x + y * p.y;}
    double operator^(Point p) const {return x * p.y - y * p.x;}
    Point operator*(double a) const {return  {a *x ,a * y};}
};
inline Point operator*(double a, Point p) {
    return p * a;
}

class Triangle {
    Point A, B, C;
public:
    Triangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}
    bool IsPointIn (Point p)
    {
        double vecABP = (B - A) ^ (p - A);
        double vecBCP = (C - B) ^ (p - B);
        double vecCAP = (A - C) ^ (p - C);

        if (vecABP * vecBCP < 0 || vecBCP * vecCAP < 0 || vecCAP * vecABP < 0)
            return false;
        return true;
    }
};

int main()
{
    Point tri[3];
    int xP, yP;
    cin >> xP >> yP;
    Point point(xP, yP);

    for (int i = 0; i < 3; i++)
    {
        cin >> xP >> yP;
        Point temp(xP, yP);
        tri[i] = temp;
    }


    return 0;
}