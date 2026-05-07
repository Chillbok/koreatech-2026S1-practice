#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector;

struct Work {
    int id;
    int D;
    int P;
};

void test() {
    int N;
    if (!(cin >> N)) return;

    vector<Work> testcase(N);
    for (int i = 0; i < N; ++i) {
        testcase[i].id = i + 1;
        cin >> testcase[i].D >> testcase[i].P;
    }

    vector<Work> sortedWorks = testcase;
    std::sort(sortedWorks.begin(), sortedWorks.end(), [](const Work& a, const Work& b) {
        if (a.P != b.P) return a.P > b.P;
        return a.id < b.id;
    });

    vector<Work> S;

    for (const auto& w : sortedWorks) {
        vector<Work> nextS = S;
        nextS.push_back(w);
        
        std::sort(nextS.begin(), nextS.end(), [](const Work& a, const Work& b) {
            return a.D < b.D;
        });

        bool feasible = true;
        for (int i = 0; i < (int)nextS.size(); ++i) {
            if (nextS[i].D < i + 1) { 
                feasible = false;
                break;
            }
        }

        if (feasible) {
            S = nextS;
        }
    }

    std::sort(S.begin(), S.end(), [](const Work& a, const Work& b) {
        return a.id < b.id;
    });

    for (int i = 0; i < (int)S.size(); ++i) {
        cout << S[i].id << (i == (int)S.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        test();
    }
    return 0;
}
