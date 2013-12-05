#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
        int N = A.size();
        int ac[26] = {0};
        int bc[26] = {0};
        for (int i = 0; i < N; ++i) ac[A[i] - 'A'] += 1;
        for (int i = 0; i < N; ++i) bc[B[i] - 'A'] += 1;
        for (int i = 0; i < 26; ++i) if (ac[i] != bc[i]) return -1;
        int i = N-1;
        int j = N-1;
        int res = 0;
        while (i >= 0) {
            if (A[i] == B[j]) {
                --i;
                --j;
            } else {
                --i;
                ++ res;
            }
        }
        return res;
	}
};
