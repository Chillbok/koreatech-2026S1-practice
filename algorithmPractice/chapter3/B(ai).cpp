#include <iostream>
#include <vector>
#include <algorithm>

long long solve(const std::vector<int>& H, int left, int right) {
    if (left == right) {
        return H[left];
    }

    int mid = (left + right) / 2;
    long long ret = std::max(solve(H, left, mid), solve(H, mid + 1, right));

    int lo = mid, hi = mid + 1;
    long long height = std::min(H[lo], H[hi]);
    ret = std::max(ret, height * 2LL);

    while (lo > left || hi < right) {
        bool canMoveLeft = (lo > left);
        bool canMoveRight = (hi < right);
        
        if (canMoveRight && (!canMoveLeft || H[lo - 1] < H[hi + 1])) {
            hi++;
            height = std::min(height, (long long)H[hi]);
        } else if (canMoveLeft) {
            lo--;
            height = std::min(height, (long long)H[lo]);
        }
        ret = std::max(ret, height * (hi - lo + 1LL));
    }

    return ret;
}

void test() {
    int case_length;
    if (!(std::cin >> case_length)) return;
    std::vector<int> cases(case_length);
    for (int i = 0; i < case_length; ++i) {
        std::cin >> cases[i];
    }
    std::cout << solve(cases, 0, case_length - 1) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testcase_count;
    if (!(std::cin >> testcase_count)) return 0;
    
    while (testcase_count--) {
        test();
    }
    return 0;
}
