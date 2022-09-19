#include <iostream>

using namespace std;

int Reverse(int n)
{
	int du;
	int res = 0;
	while (n != 0)
	{
		du = n % 10;
		res = res * 10 + du;
		n = n / 10;
	}
	return res;
}
bool Check(int n)
{
	if (Reverse(n) == n)
	{
		return true;
	}
	return false;
}

int main()
{
	int n, arr[100000];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (Check(arr[i]))
		{
			cout << arr[i] << " ";
		}
	}
}