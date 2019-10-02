using namespace std;
#include 					<bits/stdc++.h>
#define 	FIO 			ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // ===  === === === === === ===> I LOVE U
#define 	mp 				make_pair
#define 	pb 				push_back
#define 	fs 				first
#define 	sc 				second
#define  	REP(_t)			for (int _i=1; _i<=_t; ++_i)
#define		endl			"\n"
typedef 	long long			ll;	
typedef 	long double 		ld;
typedef 	pair<int,int> 		pii;
typedef 	pair<ll,ll> 		pll;
typedef 	pair<int,pii> 		pipii;
typedef		pair<ll,pii> 		pllpii;
int const mxn = 2e5+2;
int const mod = 1e9+7;

int n, k, A[mxn];
ll ans = 0;
vector<pii> V;
vector<vector<int> > Pre;

bool check(int l, int r){
	for (int i=0; i<V.size(); ++i){
		if (Pre[i][r] - Pre[i][l-1] < V[i].sc) return false;
	}
	return true;
}

void SOL(){
	cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> A[i];
	for (int i=2; i<=k; ++i){
		if (k%i == 0){
			int cnt = 0;
			while (k>1 && k%i == 0){
				++cnt;
				k/=i;
			}
			V.pb({i,cnt});
		}
	}
	if (k != 1) V.pb({k,1});
	Pre.resize(V.size(),vector<int>(n+1));
	for (int i=0; i<V.size(); ++i){
		int su = 0;
		for (int j=1; j<=n; ++j){
			int cnt = 0;
			while (A[j] > 1 && A[j]%V[i].fs == 0){
				++cnt;
				A[j]/=V[i].fs;
			}
			su += cnt;
			Pre[i][j] = su;
		}
	}
	for (int i=1; i<=n; ++i){
		int l = i, r = n;
		while (l<r){
			int mid = (l+r)>>1;
			if (check(i,mid)){
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (check(i,l)){
			ans += n - l + 1;
		}
	}
	cout << ans;
}		

int main(){FIO; srand(time(0)); SOL(); return 0;}

