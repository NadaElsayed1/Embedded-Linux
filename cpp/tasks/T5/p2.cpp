// class Solution {
// public:
//     int addDigits(int num) {
//         int sum = 0;
//         while(num>9)
//         {
//             while(num)
//             {
//                 sum+=(num%10);
//                 num/=10;
//             }
//             num = sum;
//             sum=0;
//         }
//         return num;
//     }
// };

/*For any positive integer num, the digital root can be found using the properties of numbers in modulo 9 arithmetic
 * specifically: a number is divisible by 9 (its digits sum to 9 (or a multiple of 9))
 * if a number is not divisible by 9 (num % 9 gives the digital root directly)
 * this approach leverages mathematical properties to simplify the problem and achieve constant time complexity-> O(1)*/

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        else
            return num % 9 == 0 ? 9 : num % 9;
    }
};
