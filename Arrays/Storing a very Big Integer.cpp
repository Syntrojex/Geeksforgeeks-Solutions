#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

class Solution {
public:

    cpp_int calculateFactorial(int n)
    {
        if (n <= 1)
            return 1;

        return n * calculateFactorial(n - 1);
    }

    vector<int> factorial(int n)
    {
        cpp_int fact = calculateFactorial(n);

        vector<int> result;

        while (fact > 0)
        {
            int digit = (fact % 10).convert_to<int>();

            result.push_back(digit);

            fact /= 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
