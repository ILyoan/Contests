#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

long long area(long long x1, long long y1,
               long long x2, long long y2,
               long long x3, long long y3) {
    return abs((x2 - x1) * (y3- y1) - (x3 - x1) * (y2 - y1));
}

long long colinear(long long x1, long long y1,
                   long long x2, long long y2,
                   long long x3, long long y3) {
    return area(x1, y1, x2, y2, x3, y3) == 0;
}

class ConvexPolygonGame {
public:
	string winner(vector <int> X, vector <int> Y) {
        int N = X.size();
        int minx = X[0];
        int maxx = X[0];
        for (int i = 0; i < N; ++i) {
            if (minx > X[i]) minx = X[i];
            if (maxx < X[i]) maxx = X[i];
        }
        bool linear = true;
        long long count = 0;
        vector<pair<int, int> > ps;
        for (int x = minx; x <= maxx; ++x) {
            int uy, ly;
            for (int i = 0; i < N; ++i) {
                int x1 = X[i];
                int y1 = Y[i];
                int x2 = i + 1 < N ? X[i + 1] : X[0];
                int y2 = i + 1 < N ? Y[i + 1] : Y[0];
                if (x < min(x1, x2) || x > max(x1, x2)) continue;
                if (x1 < x2) {
                    ly = ceil((double)(y1 - y2) / (x1 - x2) * (x - x1) + y1);
                    if (x == x1 && ly == y1 || x == x2 && ly == y2) ly += 1;
                }
                else if (x1 > x2) {
                    uy = floor((double)(y1 - y2) / (x1 - x2) * (x - x1) + y1);
                    if (x == x1 && uy == y1 || x == x2 && uy == y2) uy -= 1;
                }
                else {
                    uy = max(y1, y2) - 1;
                    ly = min(y1, y2) + 1;
                }
            }
            if (uy >= ly) {
                int cnt = uy - ly + 1;
                if (cnt >= 2) {
                    linear = false;
                    count += 2;
                }
                if (cnt == 1) {
                    ps.push_back(make_pair(x, uy));
                    count += 1;
                }
            }
        }
        if (linear) {
            for (int i = 2; i < ps.size(); ++i) {
                if (!colinear(ps[0].first, ps[0].second,
                              ps[1].first, ps[1].second,
                              ps[i].first, ps[i].second)) {
                    linear = false;
                    break;
                }
            }
        }
        return count >= 3 && !linear ? "Masha" : "Petya";
	}
};
