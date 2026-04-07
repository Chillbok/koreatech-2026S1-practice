#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

struct Bucket {
    int lowest, highest;
    bool data_exists = false;
};

void get_lowest_and_biggest(const vector<int>& arr, int& lowest, int& biggest) {
    lowest = arr[0], biggest = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (lowest > arr[i]) lowest = arr[i];
        if (biggest < arr[i]) biggest = arr[i];
    }
}

void test() {
    // 크기 입력하고, 각 배열 입력하는 과정
    int length; cin >> length;
    vector<int> one_case(length);
    for (int i = 0; i < length; i++) cin >> one_case[i];

    // 정수가 하나만 주어지면 0을 출력
    if (length == 1) {
        cout << 0 << endl;
        return;
    }
    
    // 입력값에서 가장 작은 값, 가장 큰 값
    int lowest, biggest;
    get_lowest_and_biggest(one_case, lowest, biggest);
    // 최소값 == 최대값이라면 굳이 고민할 필요 없이 0을 출력하면 되기 때문에 다음 코드 실행
    if (lowest == biggest) {
        cout << 0 << endl;
        return;
    }
    // 예를 들어, 제일 작은 게 1, 제일 큰 게 9일 때 숫자가 5개라면, 숫자는 1, 3, 5, 7, 9이고, 일정한 간격은 2임
    int gap = (biggest - lowest) / (length - 1);
    if (gap == 0) gap++;
    
    // 버킷 개수를 결정해야 함. 전체 데이터 범위를 버킷 크기로 나누면 필요한 버킷의 대략적인 개수가 나온다.
    int buckets_size = ((biggest - lowest) / gap) + 1;
    vector<Bucket> buckets(buckets_size);
    // 제공된 입력값의 모든 값마다 해당하는 버킷을 찾아서 연산을 수행해야 함.
    for (int x : one_case) {
        // 버킷의 위치를 구하려면 제일 작은 값에서 간격을 몇 번 더했는지 구해야 함.
        // 예를 들어서, 간격이 2인데 숫자가 7이고, 제일 작은 수가 1이라면 1에 2를 세 번 더해야 함. 따라서 인덱스의 위치는 3임.
        int index = (x - lowest) / gap;
        Bucket& selected_bucket = buckets[index];
        
        // 버킷의 데이터가 존재하지 않는 경우, 첫 시도이므로 데이터를 집어넣음
        if (selected_bucket.data_exists == false) {
            selected_bucket.data_exists = true;
            selected_bucket.lowest = x;
            selected_bucket.highest = x;
        }
        // 버킷의 데이터가 존재한다면, 이미 한 번 데이터를 넣은 적이 있으므로 값을 비교해서 집어넣어주어야 함.
        if (selected_bucket.data_exists == true) {
            if (x < selected_bucket.lowest) selected_bucket.lowest = x;
            if (x > selected_bucket.highest) selected_bucket.highest = x;
        }
    }
    // 이제 여기에서 버킷에 값을 집어넣는 과정을 완수함. 첫번째로 집어넣는 것이 아닌 경우를 따로 찾아두었기 때문에 알아서 다 채워질 것임.
    
    // 최종 정답을 담는 변수임.
    int max_gap = 0;
    // 모든 벡터를 확인하면서 비어 있지 않은 버킷 간의 간격을 계산하기 위해 '이전 비어 있지 않은 버킷'의 최대값을 저장하는 역할을 함.
    // 버킷 안에 있는 값들끼리만 간격을 계산하면 안될 것임. 이전 버킷의 가장 큰 값과, 현재 버킷의 가장 작은 값도 비교해야함.
    int previous_highest = lowest;
    // 버킷끼리 비교해야지
    for(Bucket& x : buckets) {
        // 현재의 간격을 기록하는 변수
        int current_gap;
        // 데이터가 존재하는 경우에만 실행
        if (x.data_exists == true) {
            // 먼저 이전의 가장 높은 값과 현재의 가장 낮은 값을 비교하고
            current_gap = x.lowest - previous_highest;
            // 만약 max_gap보다 그 비교값이 더 크면 대체하기
            if (current_gap > max_gap) max_gap = current_gap;
            // 다음 버킷과 현재 버킷을 비교하기 위해, 현재의 가장 큰 값을 변수에 집어넣기
            previous_highest = x.highest;
        }
    }
    // 최종 결과 출력
    cout << max_gap << endl;
}

int main() {
    int T; cin >> T;
    while (T--) test();
    return 0;
}