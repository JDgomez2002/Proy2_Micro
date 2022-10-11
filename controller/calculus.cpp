
using namespace std;

namespace calculus
{
    /// @brief Separate n into equal parts based on m
    /// @param arr
    /// @param m
    /// @param n
    /// @return return an array with the distribution
    int *distribution(int arr[], int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i] = n / m;
            if (i + 1 - m == 0)
            {
                arr[i] = n - n / m * (i);
            }
        }
        return arr;
    }
}