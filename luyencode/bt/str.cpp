#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        int k = 1;
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                k++;
                i++;
            }
            else
            {
                break;
            }
        }
        cout << s[i] << k;
    }
    return 0;
}