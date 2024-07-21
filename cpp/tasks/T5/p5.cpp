#include <iostream>
#include <vector>
#include <algorithm> // for std::max

class Solution
{
public:
    int largestAltitude(std::vector<int> &gain)
    {
        int highest = 0;
        int current = 0;

        for (int g : gain)
        {
            current += g;
            highest = std::max(highest, current);
        }

        return highest;
    }
};