#include<vector>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<iomanip>

using namespace std;

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF (int)1e9
#define LINF (long long)1e18
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?(-(x)):(x))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define foreach(v,c) for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)

double randDouble(double LO, double HI)
{
  return (LO + (float)rand()/((float)RAND_MAX/(HI-LO)));
}

int main(int argc, char** argv)
{
  srand((unsigned)time(0));
  int n = atoi(argv[1]);cout<<n<<endl;
  int t, tc = atof(argv[2]);t = tc;cout<<tc<<endl;
  while(tc--)
  {
    REP(i,n)
    {
      cout<<randDouble(-2,2)<<" ";
    }
    cout<<endl;
  }
  REP(i,(int)t/5)
  {
    cout<<2<<" "<<randDouble(-0.5,0.5)<<" "<<randDouble(-0.5,0.5)<<" "<<randDouble(0,2.5)<<endl;
  }
  return 0;
}

