#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int D[51];
vector<vector<int> > adj;
vector<bool> visit;

int go(int u) {
    if (visit[u]) return 0;
    visit[u] = true;
    int beacons = 0;
    int no_beacons = 0;
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        if (visit[v]) continue;
        int r = go(v);
        if (r == 0) no_beacons += 1;
        else beacons += r;
    }
    if (no_beacons >= 2) beacons += no_beacons - 1;
    return beacons;
}

class TPS {
public:
	int minimalBeacons(vector <string> linked) {
        N = linked.size();
        if (N == 1) return 0;
        if (N == 2) return 1;
        int root = -1;
        adj.assign(N, vector<int>());
        visit.assign(N, false);
        for (int i = 0; i < N; ++i) {
            int deg = 0;
            for (int j = 0; j < N; ++j) {
                if (linked[i][j] == 'Y') {
                    adj[i].push_back(j);
                    deg += 1;
                }
            }
            if (deg > 2) root = i;
        }
        if (root == -1) return 1;
        return go(root);
	}
};
