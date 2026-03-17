#include <iostream>
#include <vector>

// 절댓값 크기 차이가 1 이하인지 판단하는 함수
bool define_harmony_number(int& first_number, int& selected_number)
{
    int gap = first_number - selected_number;
    if (gap >= -1 || gap <= 1) return true;
    else return false;
}

// 매개변수로 지정한 벡터에서 특정 수를 기준으로 1만큼 크거나 작은 수를 찾아 벡터에 집어넣은 뒤 길이 반환하는 변수 
int make_and_get_harmony_vector_length(bool is_smallest, std::vector<int>& param_vector, int first_number)
{
    int param_length = param_vector.size();
    int smallest = first_number;
    int biggest = smallest;
    std::vector<int> result;
    // 제일 작은거 기준으로 생각할 때
    if (is_smallest)
    {
        for (int i = 0; i < param_length; i++)
        {
            if (param_vector[i] == smallest) result.push_back(param_vector[i]);
            else if (param_vector[i] == smallest + 1)
            {
                result.push_back(param_vector[i]);
                biggest = param_vector[i];
            }
        }
    }
    // 제일 큰거 기준으로 생각할 때
    else if (!is_smallest)
    {
        for (int i = 0; i < param_length; i++)
        {
            if (param_vector[i] == biggest) result.push_back(param_vector[i]);
            else if (param_vector[i] == biggest - 1)
            {
                result.push_back(param_vector[i]);
                smallest = param_vector[i];
            }
        }
    }
    
    // 제일 큰거, 제일 작은거 크기 차이가 1이 아니면 0 반환
    if (biggest - smallest != 1) return 0;
    return result.size();
}

// 입력한 벡터의 조화배열 만들고, 가장 긴 조화배열 길이 반환하는 변수
int get_longest_harmony_vector_length(std::vector<int>& param_vector) 
{
    // 매개변수로 받은 벡터 크기
    int biggest_length = 0;
    int param_vector_length = param_vector.size();
    int smallest, biggest;
    std::vector<int> first_smallest;
    std::vector<int> first_biggest;
    int longest_length = 0;
    for (int i = 0; i < param_vector_length; i++)
    {
        // NOTE: 이거 그냥 길이 반환하는 함수에서 두 경우 모두 만들어보고 비교해보면 안되나?
        // 작은 수 기준으로 조화배열 만든 경우의 수
        int temporary_length = make_and_get_harmony_vector_length(true, param_vector, param_vector[i]);
        if (longest_length < temporary_length) longest_length = temporary_length;
        // 큰 수 기준으로 조화배열 만든 경우의 수
        temporary_length = make_and_get_harmony_vector_length(false, param_vector, param_vector[i]);
        if (longest_length < temporary_length) longest_length = temporary_length;
    }
    return longest_length;
}

int main()
{
    int x_length, y_length;
    std::cin >> x_length;

    //입력한 배열들 저장하는 변수
    std::vector<std::vector<int>> inputs(x_length);

    for (int i = 0; i < x_length; i++)
    {
        std::cin >> y_length;
        inputs[i].resize(y_length);
        
        for (int j = 0; j < y_length; j++)
        {
            std::cin >> inputs[i][j];
        }
    }
    
    int length = 0;
    // 배열 개수만큼 수 연산하고, 연산한 수는 바로 출력
    for (int i = 0; i < inputs.size(); i++)
    {
        length = get_longest_harmony_vector_length(inputs[i]);
        std::cout << length << std::endl;
    }
    return 0;
}