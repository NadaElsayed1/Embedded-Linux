#include <iostream>
#include <string>
#include <algorithm>
class Solution
{
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        std::string result = "";

        /* Iterate through both strings from right to left*/
        for (int i = 0; i < std::max(n1, n2); i++)
        {
            int digit1 = i < n1 ? num1[n1 - 1 - i] - '0' : 0;
            int digit2 = i < n2 ? num2[n2 - 1 - i] - '0' : 0;

            /*If the sum of two digits (plus any *carry*) is 10 or more
             *store the remainder (sum % 10) and carry over the quotient (sum / 10) to the next iteration.*/
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        /* check iff there's a carry left or not*/
        if (carry)
        {
            result.push_back(carry + '0');
        }

        /* The result is currently reversed, reverse it back*/
        std::reverse(result.begin(), result.end());
        return result;
    }
};