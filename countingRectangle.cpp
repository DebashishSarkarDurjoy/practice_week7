#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Compare {
public:
    bool operator()(Point a, Point b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        else return a.x < b.x;
    }
};

int findRectangles(vector<Point> &inputs) {
    set<Point, Compare> s;

    for (auto p: inputs) {
        s.insert(p);
    }

    int count = 0;
    for (auto it = s.begin(); it != prev(s.end()); it++) {
        for (auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if (p1.x == p2.x || p1.y == p2.y) continue;

            Point p3 = Point(p1.x, p2.y);
            Point p4 = Point(p2.x, p1.y);


            if ( (s.find(p3) != s.end()) && (s.find(p4) != s.end()) ) {
                count++;
            }
        }
    }

    return count / 2;
}

int main(void) {
    vector<Point> inputs;

    int nums;
    cin >> nums;
    for (int i = 0; i < nums; i++) {
        int x, y;
        cin >> x >> y;
        inputs.push_back({x, y});
    }

    cout << findRectangles(inputs) << endl;

    return 0;
}