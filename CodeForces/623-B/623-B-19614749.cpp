#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
const int N=1e6+5;
const LL INF=1e12;
int arr[N];
LL cost[N];
LL dp[N][3];
vector<int>gcd;
void prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) gcd.push_back(i);
        while(x%i==0) x/=i;
    }
    if(x>1)gcd.push_back(x);
}
int main()
{
//freopen("test.txt","r",stdin);
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=-1;i<=1;i++)
    {
        prime(arr[1]+i);
        prime(arr[n]+i);
    }
    sort(gcd.begin(),gcd.end());
    gcd.erase(unique(gcd.begin(),gcd.end()),gcd.end());
    LL ans=1e18;
    for(int i=0;i<gcd.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[j]=INF;
            if(!(arr[j]%gcd[i])) cost[j]=0;
            else if(!((arr[j]+1)%gcd[i])||!((arr[j]-1)%gcd[i]))
                cost[j]=b;
        }
        for(int j=1;j<=n;j++)
        {
            dp[j][0]=dp[j-1][0]+cost[j];
            dp[j][1]=min(dp[j-1][0],dp[j-1][1])+a;
            dp[j][2]=min(dp[j-1][1],dp[j-1][2])+cost[j];
        }
        LL tem=min(dp[n][2],min(dp[n][0],dp[n][1]));
        ans=min(ans,tem);
    }
    printf("%I64d\n",ans);
    return 0;
}