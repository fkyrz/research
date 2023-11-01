#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define RFOR(i, a, b) for (int i = a; i >= (b); i--)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define MP make_pair
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
using P = pair<int, int>;
const long long INF = 1LL<<60;
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

struct xorshift128{
    const unsigned int ini_x = 123456789, ini_y = 362436069, ini_z = 521288629, ini_w = 88675123;
    unsigned int x, y, z, w;
    
    xorshift128() {}

    // シードによってx,y,z,wを初期化 ... initialize x,y,z,w by seed
    void set_seed(unsigned int seed){
        x = ini_x, y = ini_y, z = ini_z, w = ini_w ^ seed;
    }

    unsigned int randint(){
        unsigned int t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    // [0,r)の範囲の整数で乱数発生 ... generate random integer in [0,r)
    ll randint(ll r){
        assert(r != 0);
        return randint() % r;
    }

    // [l,r)の範囲の整数で乱数発生 ... generate random integer in [l,r)
    ll randint(ll l, ll r){
        assert(r > l);
        return l + randint(r-l);
    }

    // 長さnの順列をランダムに生成し、その前k個分を出力する ... generate a random permutation of size n, and return the first k
    vector<int> randperm(int n, int k){
        assert(k >= 0 && k <= n);
        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            ret[i] = i;
        }
        for(int i = 0; i < k; i++){
            swap(ret[i], ret[randint(i, n)]);
        }
        return vector<int>(ret.begin(), ret.begin() + k);
    }

    // [0,1]の範囲の実数で乱数発生 ... generate random real number in [0,1]
    double uniform(){
        return double(randint()) * 2.3283064370807974e-10;
    }

    // [0,r]の範囲の実数で乱数発生 ... generate random real number in [0,r]
    double uniform(double r){
        assert(r >= 0.0);
        return uniform() * r;
    }

    // [l,r]の範囲の実数で乱数発生 ... generate random real number in [l,r]
    double uniform(double l, double r){
        assert(r >= l);
        return l + uniform(r - l);
    }
};

xorshift128 Random;

const int64_t CYCLES_PER_SEC = 2800000000;

struct Timer {
	int64_t start;
	Timer() { reset(); }
	void reset() { start = getCycle(); }
	void plus(double a) { start -= (a * CYCLES_PER_SEC); }
	inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
	inline int64_t getCycle() {
		uint32_t low, high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((int64_t)low) | ((int64_t)high << 32);
	}
};

Timer timer;

int N, T;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	timer.reset();
	double TIMELIMIT = 10.0;
	random_device rnd;     // 非決定的な乱数生成器
	unsigned long long sd = (unsigned long long)rnd(); 
	Random.set_seed(sd);
    cin >> N >> T;
    assert(T > 0 && T <= pow(2, N) - N - 1);
    vector<vector<int>> ans(T);
    int cmp = 0;
    set<int> used;
    while(cmp < T){
        int cnt = Random.randint(2, N);
        auto perm = Random.randperm(N, cnt);
        sort(range(perm));
        FOR(i,0,cnt){
            ans[cmp].push_back(perm[i]);
        }
        cmp++;
    }

    // output
    cout << N << " " << T << endl;
    FOR(i,0,T){
        cout << (int)ans[i].size() << " ";
        for(auto x : ans[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

