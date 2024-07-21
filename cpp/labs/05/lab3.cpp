#include <iostream>
#include <vector>

std::vector<std::vector<int>> trancpose_arr()
{
    std::vector<std::vector<int>> v = {{1, 2, 3},
                                       {4, 5, 6},
                                       {7, 8, 9}};

    int size = v.size();
    std::vector<std::vector<int>> T(size, std::vector<int>(size, 0));

    std::cout << "The original matrix:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            T[i][j] = v[j][i];
        }
    }

    return T;
}

int main()
{
    std::vector<std::vector<int>> transpose = trancpose_arr();
    int size = transpose.size();

    std::cout << "After transposing:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << transpose[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
