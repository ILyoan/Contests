#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long i64;
const i64 INF = 1000000000001;

class SparseFactorial {
public:
    vector<pair<i64, i64> > primeFactor(i64 m) {
        vector<pair<i64, i64> > res;
        i64 factor = 2;
        i64 count = 0;
        while (m > 1) {
            if ((m % factor) == 0) {
                m /= factor;
                ++count;
            } else {
                if (count > 0) res.push_back(make_pair(factor, count));
                ++factor;
                count = 0;
            }
        }        
        if (count > 0) res.push_back(make_pair(factor, count));
        return res;
    }
	i64 getCount(i64 lo, i64 hi, i64 divisor) {
        vector<pair<i64, i64> > factors = primeFactor(divisor);
        vector<vector<i64> > minn;
        for (int i = 0; i < factors.size(); ++i) {
            i64 p = factors[i].first;
            i64 q = factors[i].second;
            i64 f = 1;
            for (i64 r = 0; r < q; ++r) f *= p;
            vector<i64> mins(f, INF);
            vector<i64> cnt(f, 0);
            for (i64 k = 0; k <= p * q; ++k) {
                i64 a = (k * k) % p;
                for (i64 t = a; t < f; t += p) {
                    if (mins[t] < INF) continue;
                    i64 b = ((k * k) + 1) / f * f + t;
                    if (b <= k * k) b += f;
                    i64 bb = b - k * k;
                    while ((bb % p) == 0) {
                        bb /= p;
                        ++cnt[t];
                    }
                    if (cnt[t] >= q) mins[t] = b;
                }
            }
            minn.push_back(mins);
        }
        i64 res = 0;
        for (i64 i = 0; i < divisor; ++i) {
            i64 min = 0;
            for (int j = 0; j < factors.size(); ++j) {
                i64 p = factors[j].first;
                i64 q = factors[j].second;
                i64 f = 1;
                for (i64 r = 0; r < q; ++r) f *= p;
                min = max(min, minn[j][i % f]);
            }
            if ((min % divisor) != i) {
                i64 tmp = (min / divisor) * divisor + i;
                while (tmp < min) tmp += divisor;
                min = tmp;
            }
            i64 first = lo / divisor * divisor + i;
            while (first < lo) first += divisor;
            if (first < min) first = min;
            if (first <= hi) {
                res += (hi - first) / divisor + 1;
            }
        }
        return res;
	}
};
