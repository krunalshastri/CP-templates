#include<bits/stdc++.h>
using namespace std;
#define debug(x)        cout<<#x<<" :"<<x<<endl;
#define debug2(x,y)     cout<<#x<<" :"<<x << " "<<#y<<" :"<<y <<endl;
#define debug3(x,y,z)   cout<<#x<<" :"<<x<<" "<<#y<<" :"<<y<< " "<<#z<<" :"<<z <<endl;
#define ff              first
#define ss              second
#define ar              array
#define int             long long
#define ld              long double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
#define vpii            vector<pair<int,int>>
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,n)          for(int i=0;i<n;i++)
#define MOD             1000000007
#define mod             1000000007
#define pi              3.14159265
#define umii            unordered_map<int,int>
#define umci            unordered_map<char,int>
#define umsi            unordered_map<string,int>
#define sz(s)           (int)s.size()

void KruNULL()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int prime(int n) {
	int flag = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {flag = 0; break;}
	}
	return flag;
}
int power( int x,  int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

int N = 1e6 + 2;
vector<int> tree(4 * N);
vector<int> a(N);


void build(int node, int s, int e)
{
	if (s > e)
	{
		return;
	}

	if (s == e)
	{
		tree[node] = 1;
		return;
	}

	int mid = (s + e) / 2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update1(int node, int s, int e, int x)
{
	if (s > e)
	{
		return;
	}

	if (s == e)
	{
		tree[node] = 0;
		return;
	}

	int mid = (s + e) / 2;
	if (x >= s && x <= mid)
		update1(2 * node, s, mid, x);
	else
		update1(2 * node + 1, mid + 1, e, x);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int s, int e, int k, int n)
{
	if (s < 1 || e > n)
	{
		return 0;
	}

	if (s == e && k == 1)
	{
		return s;
	}

	int mid = (s + e) / 2;

	if (k > tree[2 * node])
	{
		return query(2 * node + 1, mid + 1, e, k - tree[2 * node], n);
	}
	else
	{
		return query(2 * node, s, mid, k, n);
	}
}


void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		a[i] = 1;
	}

	int q;
	cin >> q;

	build(1, 1, n);

	while (q--)
	{
		int type;
		cin >> type;

		if (type == 0)
		{
			int x;
			cin >> x;
			update1(1, 1, n, x);
		}
		else
		{
			int k;
			cin >> k;
			cout << query(1, 1, n, k, n) << endl;
		}

	}

}
int32_t main()
{
	KruNULL();
	// int JUDGE_ONLINE = 1;
	int tc = 1;
	// cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
		// if (JUDGE_ONLINE) {
		// 	cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
		// }

	}
}
