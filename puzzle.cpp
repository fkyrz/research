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
    unsigned int randint(unsigned int r){
        assert(r != 0);
        return randint() % r;
    }

    // [l,r)の範囲の整数で乱数発生 ... generate random integer in [l,r)
    unsigned int randint(unsigned int l, unsigned int r){
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
vector<vector<int>> group;

struct Game{
    vector<pair<int, int>> ans;
    Game(vector<pair<int, int>> ans): ans(ans){}
    void swapping(){
        int idx1 = Random.randint(N), idx2 = Random.randint(N);
        if(idx1 == idx2) return;
        swap(ans[idx1], ans[idx2]);
        return;
    }
    void move(){
        int idx = Random.randint(N);
        int dx = Random.randint(3) - 1, dy = Random.randint(3) - 1;
        if(ans[idx].first + dx < 0 || ans[idx].first + dx >= N) return;
        if(ans[idx].second + dy < 0 || ans[idx].second + dy >= N) return;
        FOR(i,0,N){
            if(ans[idx].first + dx == ans[i].first && ans[idx].second + dy == ans[i].second) return;
        }
        ans[idx].first += dx;
        ans[idx].second += dy;
        return;
    }
    void moveFar(){
        int x = Random.randint(N), y = Random.randint(N);
        int idx = Random.randint(N);
        FOR(i,0,N){
            if(i == idx) continue;
            if(ans[i].first == x && ans[i].second == y) return;
        }
        ans[idx].first = x;
        ans[idx].second = y;
        return;
    }
    ll calcScore(){
        // 面積
        ll score = 0LL;
        FOR(t,0,T){
            set<int> used;
            ll nowScore = 0LL;
            int minX = N, maxX = -1, minY = N, maxY = -1;
            for(auto g: group[t]){
                minX = min(minX, ans[g].first);
                maxX = max(maxX, ans[g].first);
                minY = min(minY, ans[g].second);
                maxY = max(maxY, ans[g].second);
                used.insert(g);
            }
            nowScore += (maxX - minX + 1) * (maxY - minY + 1);
            FOR(i,0,N){
                if(used.count(i) > 0) continue;
                if(minX <= ans[i].first && ans[i].first <= maxX && minY <= ans[i].second && ans[i].second <= maxY){
                    // nowScore = min((ll)nowScore * 5, (ll)1e18);
                    nowScore += (ll)1e9;
                }
            }
            score += nowScore;
        }
        FOR(i,0,N){
            score += abs(ans[i].first - N / 2) + abs(ans[i].second - N / 2);
        }
        return score;
    }
};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	timer.reset();
	double TIMELIMIT = 10.0;
	random_device rnd;     // 非決定的な乱数生成器
	unsigned long long sd = (unsigned long long)rnd(); 
	Random.set_seed(sd);
    cin >> N >> T;
    group.resize(T);
    FOR(t,0,T){
        int n;
        cin >> n;
        group[t].resize(n);
        FOR(i,0,n){
            cin >> group[t][i];
        }
    }

    // random set
    int size = N;
    vector<pair<int, int>> posCrd;
    FOR(i,0,size){
        FOR(j,0,size){
            if(!((i % 2 == 0) ^ (j % 2 == 0))){
                posCrd.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> ans(N);
    set<int> used;
    while((int)used.size() < N){
        int idx = Random.randint((int)posCrd.size());
        if(used.count(idx) > 0) continue;
        ans[(int)used.size()] = posCrd[idx];
        used.insert(idx);
    }

    // annealing
    timer.reset();
    Game game(ans);
    auto ansGame = game;
    ll score = game.calcScore();
    ll ansScore = score;
    cerr << "score : " << score << endl;
    while(timer.get() < TIMELIMIT){
        auto newGame = game;
        auto rand = Random.uniform();
        if(rand < 1.0 / 3.0){
            newGame.swapping();
        }else if(rand < 2.0 / 3.0){
            newGame.moveFar();
        }else{
            newGame.move();
        }
        ll newScore = newGame.calcScore();
        double startTemp = 10.0, endTemp = 1.0;
        double temp = startTemp + (endTemp - startTemp) * timer.get() / TIMELIMIT;
        double prob = exp((score - newScore) / temp);
        if(Random.uniform() < prob){
            if(newScore < ansScore){
                ansGame = newGame;
                ansScore = newScore;
                cerr << "score : " << ansScore << endl;
            }
            game = newGame;
            score = newScore;
        }
    }

    // output
    cout << N << " " << T << endl;
    FOR(i,0,T){
        cout << (int)group[i].size() << " ";
        for(auto g : group[i]){
            cout << g << " ";
        }
        cout << endl;
    }
    for(auto [x, y]: ansGame.ans){
        cout << x << " " << y << endl;
    }
    FOR(t,0,T){
		int minX = N, maxX = -1, minY = N, maxY = -1;
		for (auto i: group[t]){
			auto [x, y] = ansGame.ans[i];
			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}
        cout << minX << " " << minY << " " << maxX << " " << maxY << endl;
	}

    return 0;
}

