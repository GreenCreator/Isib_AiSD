#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

struct Point {
    int x;
    int y;
    double d;

    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        d = std::sqrt(x * x + y * y);
    }
};

bool Compare(Point first, Point second) {
    return first.d < second.d;
}

int main() {
    size_t count;
    std::cin >> count;

    std::vector<Point> coord;
    while (count > 0) {
        --count;

        int x;
        int y;
        std::cin >> x >> y;
        coord.push_back(Point{x, y});
    }
    std::sort(coord.begin(), coord.end(), Compare);

    for (Point p: coord) {
        std::cout << p.x << " " << p.y << std::endl;
    }
}