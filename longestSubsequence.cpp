#include <iostream>
using namespace std;

int main()
{
    string s1, s2 ;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();

    int dp[20][20] ;  

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s2[i-1] == s1[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[m][n];
}
