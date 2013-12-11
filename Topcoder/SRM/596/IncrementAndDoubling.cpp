#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class IncrementAndDoubling {
public:
	int getMin(vector <int> A) {
        int N = A.size();
        int res = 0;
        int max_len = 0;
        for (int i = 0; i < N; ++i) {
            int n = A[i];
            int len = 0;
            while (n > 0) {
                if (n % 2) res += 1;
                n /= 2;
                len += 1;
            }
            if (len - 1> max_len) max_len = len - 1;
        }
        return res + max_len;
	}
};
