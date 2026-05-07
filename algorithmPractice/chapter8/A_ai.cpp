#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector;

// 작업을 나타내는 구조체: ID, 마감시간(D), 이득(P)을 저장합니다.
struct Work {
    int id; // 입력된 순서 (1부터 시작)
    int D;  // 마감 시간 (Deadline)
    int P;  // 이득 (Profit)
};

void test() {
    int N;
    // 작업의 개수 N을 입력받습니다. 입력이 실패하면 함수를 종료합니다.
    if (!(cin >> N)) return;

    // N개의 작업을 저장할 배열(vector)을 생성합니다.
    vector<Work> testcase(N);
    for (int i = 0; i < N; ++i) {
        testcase[i].id = i + 1; // 입력 순서대로 ID 부여 (1, 2, 3...)
        cin >> testcase[i].D >> testcase[i].P;
    }

    /* 
     * 1단계: 그리디 알고리즘을 위해 작업들을 정렬합니다.
     * 가장 많은 이득을 얻기 위해 '이득(P)이 큰 순서'로 정렬합니다.
     * 만약 이득이 같다면 요구사항대로 '작업 ID가 작은 순서'로 정렬합니다.
     */
    vector<Work> sortedWorks = testcase;
    std::sort(sortedWorks.begin(), sortedWorks.end(), [](const Work& a, const Work& b) {
        if (a.P != b.P) return a.P > b.P; // 이득 내림차순
        return a.id < b.id;              // ID 오름차순
    });

    // 선택된 작업들을 담을 리스트 S
    vector<Work> S;

    /*
     * 2단계: 정렬된 작업들을 하나씩 확인하며 선택 여부를 결정합니다.
     * 이득이 큰 작업부터 "내가 이 작업을 현재 스케줄에 끼워 넣을 수 있는가?"를 확인합니다.
     */
    for (const auto& w : sortedWorks) {
        // 임시로 현재 작업 w를 추가해봅니다.
        vector<Work> nextS = S;
        nextS.push_back(w);
        
        /*
         * 3단계: 타당성(Feasibility) 검사
         * 선택된 작업들이 모두 마감 시간을 지킬 수 있는지 확인하기 위해
         * '마감 시간(D)이 빠른 순서'로 정렬해 봅니다.
         */
        std::sort(nextS.begin(), nextS.end(), [](const Work& a, const Work& b) {
            return a.D < b.D;
        });

        // 정렬된 상태에서 i번째 작업은 최소한 (i+1) 시간 안에는 끝나야 합니다.
        // 예: 1번째 작업은 시간 1 이내, 2번째 작업은 시간 2 이내...
        bool feasible = true;
        for (int i = 0; i < (int)nextS.size(); ++i) {
            if (nextS[i].D < i + 1) { 
                // 만약 어떤 작업의 마감 시간이 그 순서보다 빠르다면, 수행 불가능한 스케줄입니다.
                feasible = false;
                break;
            }
        }

        // 수행 가능한 스케줄이라면, 임시로 추가했던 상태를 확정(S = nextS)합니다.
        if (feasible) {
            S = nextS;
        }
    }

    /*
     * 4단계: 최종 결과 출력
     * 최적의 작업 집합 S가 결정되었습니다. 
     * 문제 요구사항에 따라 작업 ID의 오름차순으로 정렬하여 출력합니다.
     */
    std::sort(S.begin(), S.end(), [](const Work& a, const Work& b) {
        return a.id < b.id;
    });

    for (int i = 0; i < (int)S.size(); ++i) {
        cout << S[i].id << (i == (int)S.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // 첫 줄에 테스트 케이스의 개수 T를 입력받습니다.
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        test();
    }
    return 0;
}
