#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct TestCase {
    std::vector<int> data;
    std::vector<int> sorted;
};

int main() {
    int testcase_size;
    cin >> testcase_size;
    std::vector<TestCase> inputs;
    inputs.resize(testcase_size);
    
    for (int i = 0; i < testcase_size; i++) {
        int numbers_amount;
        cin >> numbers_amount;
        inputs[i].data.resize(numbers_amount);

        for (int j = 0; j < numbers_amount; j++) {
            cin  >> inputs[i].data[j];
        }
    }

    return 0;
}