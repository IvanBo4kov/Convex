#ifndef SOLVE_H
#define SOLVE_H

#include <vector>
#include <iostream>

struct Point {
    int x;
    int y;
};

class solve
{
public:
    static int orientation(const Point& a, const Point& b, const Point& c);
    bool cw(const Point& a, const Point& b, const Point& c, bool include_collinear);
    bool collinear(const Point& a, const Point& b, const Point& c);
    void convex_hull(bool include_collinear = false);

    static solve& getInstance();
    solve(solve const &) = delete;
    void operator = (solve const &) = delete;
    std::vector<Point> getAllPoints() { return points; }
    std::vector<Point> getConvexPoints() { return pointsForConvex; }
    void setPoint(Point pt);
    void clear();
private:
    solve();
    std::vector<Point> points;
    std::vector<Point> pointsForConvex;
};

#endif // SOLVE_H
