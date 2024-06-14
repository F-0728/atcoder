#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

queue<pair<ll, ll>> q;
vector<deque<ll>> pipe;
deque<ll> front_color;
void frontUpdate(ll i) {
    if (pipe.at(i).empty()) return;
    if (0 <= front_color.at(pipe.at(i).front())) {
        q.push({front_color[pipe.at(i).front()], i});
    } else {
        front_color[pipe.at(i).front()] = i;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    pipe.resize(M);
    rep(i, M) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll a;
            cin >> a;
            a--;
            pipe.at(i).push_back(a);
        }
    }
    front_color.resize(N);
    rep(i, N) { front_color.at(i) = -1; }
    rep(i, M) { frontUpdate(i); }
    while (!q.empty()) {
        pair<ll, ll> f = q.front();
        q.pop();
        ll a = f.first;
        ll b = f.second;
        pipe.at(a).pop_front();
        // front_color.at(a) = -1;
        frontUpdate(a);
        pipe.at(b).pop_front();
        // front_color.at(b) = -1;
        frontUpdate(b);
    }
    rep(i, M) {
        if (!pipe.at(i).empty()) {
            // rep(j, pipe.at(i).size()) cout << pipe.at(i).at(j) << " ";
            No;
            return 0;
        }
    }
    Yes;

    return 0;
}
