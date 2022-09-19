#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    string s;
    cin.ignore();
    while (t--)
    {
        getline(cin, s);
        int count = 0;
        for (unsigned int i = 0; i < s.length(); i++)
            if (s[i] == ' ' && s[i] != s[i + 1])
                count++;

        cout << count << endl;
    }
    return 0;
}