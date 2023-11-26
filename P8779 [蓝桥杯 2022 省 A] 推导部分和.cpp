#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
#define ll long long
#define int ll

const int maxn = 200000 + 10;
int n, m, a, b, s;
int par[maxn], val[maxn];

void init(int l, int r)
{
    for (int i = l; i <= r; i++)
        par[i] = i, val[i] = 0;
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
    {
        int root = find(par[x]);
        val[x] += val[par[x]];
        return par[x] = root;
    }
}

void solve()
{
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
    cin >> n >> m;
    int q;
    cin >> q;
    init(0, n);
    int ans = 0;
    for (int i = 1, a, b, s; i <= m; i++)
    {
        cin >> a >> b >> s;
        a--;
        int t1 = find(a), t2 = find(b);
        if (t1 != t2)
        {
            par[t2] = t1;
            val[t2] = -val[b] + s + val[a];
        }
    }
    while (q--)
    {
        cin >> a >> b;
        a--;
        int t1 = find(a), t2 = find(b);
        if (t1 != t2)
            cout << "UNKNOWN" << endl;
        else
            cout << val[b] - val[a] << endl;
    }
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}