#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MAXN=100000+5;
//�⿴���������᲻������Ķ���
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t,n;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==2||n==3) printf("second\n");
        else printf("first\n");
    }
    return 0;
}