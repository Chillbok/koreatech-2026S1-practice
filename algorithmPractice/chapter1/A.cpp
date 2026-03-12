#include <iostream>
#include <vector>

// 절댓값 크기 차이가 1 이하인지 판단하는 함수
bool define_harmony_number(int& first_number, int& selected_number)
{
    int gap = first_number - selected_number;
    if (gap >= -1 || gap <= 1) return true;
    else return false;
}

int main()
{
    int x_length, y_length;
    std::cin >> x_length;

    std::vector<std::vector<int>> result(x_length);

    for (int i = 0; i < x_length; i++)
    {
        std::cin >> y_length;
        result[i].resize(y_length);
        
        std::cout << i << "행 입력: ";
        for (int j = 0; j < y_length; j++)
        {
            std::cin >> result[i][j];
        }
    }
    return 0;
}