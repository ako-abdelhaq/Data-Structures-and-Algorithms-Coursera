#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

class Point {
    public:
    int x,y;
};

bool compX(Point a , Point b) {
    return (a.x < b.x);
}
bool compY(Point a, Point b) {
    return (a.y < b.y);
}
float dist(Point a, Point b) {
    float d = sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
    return d;
}
float bruteF(Point points[], int n) {

    float min = __FLT_MAX__;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            float d = dist(points[i], points[j]);
            if(d < min)
                min = d;
        }
    }
    return min;
}

float stripClosest(Point strip[], int n, float min) {

    sort(strip, strip + n,compY);
    for(int i = 0 ; i < n; i++) {
        for(int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; j++) {
            float d = dist(strip[i], strip[j]);
            if(d < min)
                min  = d;
        }
    }

    return min;
}


float closest(Point P[], int n) {

    if (n <= 3) {
        return bruteF(P, n);
    }

    int mid = n / 2;
    Point midPoint = P[mid];

    float dl = closest(P, mid);
    float dr = closest(P + mid, n - mid);

    float d = min(dl, dr);
    
    Point strip[n];
    int j = 0;
    for(int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d) 
            strip[j++] = P[i];
    }

    return stripClosest(strip, j, d);
}

int main () {
    int n;
    cin >> n;
    Point P[n];
    for(int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    sort(P, P + n, compX);

    cout << fixed << setprecision(9) << closest(P, n);
    
}