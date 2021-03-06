// Problem: Ring Road 2
/*
7325071 Practice:
apaapa  27D - 9 GNU C++ Accepted  30 ms 52 KB 2014-08-02 09:41:32 2014-08-02 09:41:32
http://codeforces.com/problemset/problem/27/D
*/

#include <iostream>
using namespace std;

#define MAXN 105
#define MAXM 105

#define forr(i,d,h) for (int i = (d); i < (h); ++i)
#define in(a,x,b) ((a) < (x) and (x) < (b))
#define out(a,x,b) ((a) > (x) or (x) > (b))

int n, m, temp;
int a[MAXM], b[MAXM];
int g[MAXM][MAXM];
int region[MAXM];

bool intersecan(int i, int j)
{
  return (in(a[i], a[j], b[i]) and out(a[i], b[j], b[i])) or
    (in(a[i], b[j], b[i]) and out(a[i], a[j], b[i]));
}

bool dfs(int i, int r)
{
  bool hay_sol = true;
  region[i] = r;
  forr (j, 0, m) if (g[i][j] == 1)
    if (region[j] == -1) hay_sol = hay_sol && dfs(j, 1 - r);
    else if (region[j] == region[i]) return false;
}

int main(int argc, char const *argv[])
{
  cin >> n >> m;
  forr (i, 0, m) cin >> a[i] >> b[i];
  forr (i, 0, m) temp = a[i], a[i] = min(a[i], b[i]), b[i] = max(temp, b[i]);
  forr (i, 0, m) forr (j, i + 1, m) g[i][j] = g[j][i] = intersecan(i, j) ? 1 : 0;

  bool hay_sol = true;
  fill(region, region + m, -1);
  forr (i, 0, m) if (region[i] == -1) hay_sol = hay_sol && dfs(i, 0);
  if (not hay_sol) cout << "Impossible";
  else forr(i, 0, m) cout << (region[i] == 1 ? 'o' : 'i');
  cout << endl;

  return 0;
}