#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    input(arr, n);
    sort(arr, n);
    if ((arr[0] * arr[1]) > (arr[n - 1] * arr[n - 2]))
    {
        cout << arr[0] * arr[1];
    }
    else
    {
        cout << arr[n - 1] * arr[n - 2];
    }
    return 0;
}