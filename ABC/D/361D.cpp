#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    string S, T;
    cin >> N >> S >> T;
    ll white = 0;
    ll black = 0;
    ll whiteGoal = 0;
    ll blackGoal = 0;
    rep(i, N) {
        if (S.at(i) == 'W') {
            white++;
        } else {
            black++;
        }
        if (T.at(i) == 'W') {
            whiteGoal++;
        } else {
            blackGoal++;
        }
    }
    if (white != whiteGoal || black != blackGoal) {
        cout << -1 << endl;
        return 0;
    }
    S = S + "..";
    T = T + "..";

    queue<string> q;
    q.push(S);
    map<string, ll> mp;
    mp[S] = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        // cout << s << endl;
        ll cnt = mp[s];
        if (s == T) {
            cout << cnt << endl;
            return 0;
        }
        ll vacant = 0;
        rep(i, N + 1) {
            // cout << s.at(i) << " " << s.at(i + 1) << endl;
            if (s.at(i) == '.' && s.at(i + 1) == '.') {
                vacant = i;
                break;
            }
        }
        // cout << vacant << endl;
        rep(i, N + 1) {
            if (s.at(i) != '.' && s.at(i + 1) != '.') {
                string t = s;
                t.at(i) = '.';
                t.at(i + 1) = '.';
                t.at(vacant) = s.at(i);
                t.at(vacant + 1) = s.at(i + 1);
                if (mp.find(t) == mp.end()) {
                    mp[t] = cnt + 1;
                    q.push(t);
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
