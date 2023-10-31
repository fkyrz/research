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

int N = 7;

int solve(vector<int> place){
    int cnt = 0;
    for (int bit = 0; bit < (1 << N); ++bit){
        
        int left = N, right = -1, up = N, down = -1;
        FOR(i,0,N){
            if (bit & (1 << i)){
                left = min(left, place[i] % N);
                right = max(right, place[i] % N);
                up = min(up, place[i] / N);
                down = max(down, place[i] / N);
            }
        }
        bool isOK = true;
        FOR(i,0,N){
            if(!(bit & (1 << i))){
                int y = place[i] % N, x = place[i] / N;
                if (left <= y && y <= right && up <= x && x <= down){
                    isOK = false;
                }
            }
        }
        cnt += isOK;
    }
    return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int size = N * N, score = -1;
    vector<int> ans;
    function<void(vector<int>)> dfs = [&](vector<int> tmp){
        if((int)tmp.size() == N){
            int tmp_score = solve(tmp);
            if (tmp_score > score){
                score = tmp_score;
                ans = tmp;
            }
            cout << "score : " << tmp_score << " -> ";
            for(auto x: tmp){
                cout << x << " ";
            }
            cout << endl;
            return;
        }
        int l = ((int)tmp.size() == 0) ? 0 : tmp.back() + 1;
        FOR(i,l,size){
            bool flag = true;
            for(auto x: tmp){
                if (x == i) flag = false;
            }
            if(!flag) continue;
            if((int)tmp.size() == 0 && i >= N) continue;
            tmp.push_back(i);
            dfs(tmp);
            tmp.pop_back();
        }
        return;
    };
    dfs({});

    cout << "ans : ";
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    

    return 0;
}

