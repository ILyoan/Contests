#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class FoxAndFencing {
public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
        if (mov1 + rng1 >= d) return "Ciel";
        if (mov1 + d <= mov2 + rng2) return "Liss"; 
        if (mov1 > mov2) {
            if (mov2 + mov2 + rng2 < mov1 + rng1) return "Ciel";
            return "Draw";
        } else if (mov1 < mov2) {
            if (mov1 + mov1 + rng1 < mov2 + rng2) return "Liss";
            return "Draw";
        }
        return "Draw";
	}
};
