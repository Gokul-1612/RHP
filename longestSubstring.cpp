#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    int dp[20][20] = {0};

    int maxlen = 0;
    int end = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s2[i-1] == s1[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;

                if(dp[i][j] > maxlen)
                {
                    maxlen = dp[i][j];
                    end = j;      
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    string ans = s1.substr(end - maxlen, maxlen);

    cout << "Length = " << maxlen << endl;
    cout << "Substring = " << ans << endl;

    return 0;
}
