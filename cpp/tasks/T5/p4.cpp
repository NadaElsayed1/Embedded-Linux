#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        /* check if lengths are different so they cannot be anagrams*/
        if (s.size() != t.size())
        {
            return false;
        }

        /* create a hash map to count character frequencies*/
        std::unordered_map<char, int> count;

        /* count frequency of each character in both strings*/
        for (int i = 0; i < s.size(); ++i)
        {
            count[s[i]]++;
            count[t[i]]--;
        }

        /* check if all counts are zero*/
        for (const auto &entry : count)
        {
            if (entry.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
