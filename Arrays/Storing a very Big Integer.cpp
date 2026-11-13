#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

cpp_int calculateFactorial(int n)
{
    if (n <= 1)
        return 1;

    return n * calculateFactorial(n - 1);
}

int main()
{
    cpp_int fact = calculateFactorial(n);
}
