
using namespace std;

namespace calculus
{
    int *distributor(int arr[], int m, int n)
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