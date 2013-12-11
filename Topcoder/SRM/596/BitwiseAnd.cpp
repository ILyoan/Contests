#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

static const int BITS = 60;

class BitwiseAnd {
public:
	vector<long long> lexSmallest(vector<long long> subset, int N) {
        vector<vector<bool> > table;
        vector<int> sum(BITS);
        vector<int> ref(BITS);
        vector<long long> res;
        int max_bit = 0;
        for (int i = 0; i < subset.size(); ++i) {
            for (int j = i + 1; j < subset.size(); ++j) {
                if ((subset[i] & subset[j]) == 0) return res;
            }
        }
        for (int i = 0; i < subset.size(); ++i) {
            long long n = subset[i];
            int bit = 0;
            int count = 0;
            vector<bool> entry(BITS);
            while ((1ll << bit) <= n) {
                if (n & (1ll << bit)) {
                    entry[bit] = true;
                    ref[bit] = i;
                    sum[bit] += 1;
                    count += 1;
                }
                ++bit;
                if (bit > max_bit) max_bit = bit;
            }
            if (count < N - 1) return res;
            table.push_back(entry);
        }
        for (int i = 0; i < BITS; ++i) if (sum[i] >= 3) return res;
       
        while (table.size() < N) {
            vector<bool> entry(BITS);
            vector<bool> connect(table.size());
            int required = N - 1;
            for (int i = 0; i < BITS; ++i) {
                if (sum[i] == 1 && !connect[ref[i]]) {
                    entry[i] = true;
                    connect[ref[i]] = true;
                    ++sum[i];
                    --required;
                }
                if (required == 0) break;
            }
            int bit = 0;
            while (required > 0 && bit < BITS) {
                if (sum[bit] == 0) {
                    entry[bit] = true;
                    ref[bit] = table.size();
                    sum[bit] = 1;
                    --required;
                }
                ++bit;
            }
            if (required == 0) {
                table.push_back(entry);
            } else {
                return res;
            }
        }

        for (int i = 0; i < table.size(); ++i) {
            long long n = 0;
            for (int j = 0; j < BITS; ++j) {
                if (table[i][j]) n |= (1ll<<j);
            }
            res.push_back(n);
        }
        sort(res.begin(), res.end());

        return res;
	}
};
