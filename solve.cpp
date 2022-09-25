#include "solve.h"

solve::solve() {}

int solve::orientation(const Point& a, const Point& b, const Point& c) {
    int v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) {
        return -1;
    }
    if (v > 0) {
        return +1;
    }
    return 0;
}

bool solve::cw(const Point& a, const Point& b, const Point& c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

bool solve::collinear(const Point& a, const Point& b, const Point& c) {
    return orientation(a, b, c) == 0;
}

void solve::convex_hull(bool include_collinear) {
    Point p0 = *min_element(points.begin(), points.end(), [](Point a, Point b) {
            return std::make_pair(a.y, a.x) < std::make_pair(b.y, b.x);
        });
    sort(points.begin(), points.end(), [&p0](const Point& a, const Point& b) {
           int o = orientation(p0, a, b);
           if (o == 0)
               return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                   < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
           return o < 0;
       });
    if (include_collinear) {
        int i = (int)points.size()-1;
        while (i >= 0 && collinear(p0, points[i], points.back())) i--;
        reverse(points.begin()+i+1, points.end());
    }
    std::vector<Point> st;
    for (int i = 0; i < (int)points.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), points[i], include_collinear))
            st.pop_back();
        st.push_back(points[i]);
    }
    pointsForConvex = st;
    std::cout << "Points of convex:" << std::endl;
    for (auto i : pointsForConvex) {
        std::cout << i.x << " " << i.y << std::endl;
    }
}

solve& solve::getInstance() {
    static solve instance;
    return instance;
}

void solve::setPoint(Point pt) {
    points.push_back(pt);
}

void solve::clear()
{
    points.clear();
    pointsForConvex.clear();
}
