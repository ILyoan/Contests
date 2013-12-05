#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

static int MOD = 1000000007;

vector<int> factorials(int n, int m) {
    vector<int> res(n + 1, 0);
    res[0] = 1;
    for (int i = 1; i <= n; ++i) {
        res[i] = ((long long)res[i-1] * i) % m;
    }
    return res;
}
vector<int> modular_inverses(int n, int m) {
    vector<int> res(n + 1, 0);
    res[1] = 1;
    for (int i = 2; i <= n; ++i) {
        res[i] = m - ((m / i) * (long long)res[m % i]) % m;
    }
    res[0] = 1;
    return res;
}
vector<int> factorial_inverses(int n, int m) {
    vector<int> inv = modular_inverses(n, m);
    vector<int> res(n + 1, 0);
    res[0] = res[1] = 1;
    for (int i = 2; i <= n; ++i) {
        res[i] = ((long long)res[i-1] * inv[i]) % m;
    }
    return res;
}


class LittleElephantAndBoard {
public:
    vector<int> F;
    vector<int> I;

    int Combination(int n, int k) {
        int res = ((long long)F[n] * ((long long)I[k] * (long long)I[n-k] % MOD)) % MOD;
        return res;
    }
    int countCombination(int X, int Y, int Z) {
        int res = 0;
        for (int G = max(1, X - 1); G <= X; ++G) {
            long long exp = 1;
            for (int E = 0; E <= G; ++E) {
                int O = G - E;
                int Oy = (O + Y - Z) / 2;
                int Oz = O - Oy;
                int R = Y - E - Oy;
                if ((O + Y - Z) % 2 == 0 && Y >= Oy && Z >= Oz && Oy >= 0 && Oz >= 0 && R >= 0) {
                    long long Cge = (Combination(G, E) * exp) % MOD;
                    long long Cgo = Combination(O, Oy);
                    long long Cr = Combination(G + R - 1, R);
                    res = (res + (((Cge * Cgo) % MOD) * Cr) % MOD) % MOD;
                }
                exp = (exp * 2) % MOD;
            }
        }
        return res;
    }
	int getNumber(int M, int R, int G, int B) {
        F = factorials(M, MOD);
        I = factorial_inverses(M, MOD);

        int res = 0;
        res = (res + countCombination(M - R, M - G, M - B)) % MOD;
        res = (res + countCombination(M - G, M - B, M - R)) % MOD;
        res = (res + countCombination(M - B, M - R, M - G)) % MOD;
        return (2 * res) % MOD;
	}
};
