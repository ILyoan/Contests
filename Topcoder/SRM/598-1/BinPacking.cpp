#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class BinPacking {
public:
	int minBins(vector <int> item) {
        sort(item.rbegin(), item.rend());
        int N = item.size();
        vector<bool> used(N);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (used[i]) continue;
            used[i] = true;
            int w = item[i];
            for (int j = i + 1; j < N; ++j) {
                if (used[j]) continue;
                if (w + item[j] <= 300) {
                    w = w + item[j];
                    used[j] = true;
                }
            }
            ++ res;
        }
        return res;
	}
};
