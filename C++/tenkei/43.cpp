#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll H, W, rs, cs, rt, ct;
    cin >> H >> W >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;

    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H) {
        string str;
        cin >> str;
        rep(j, W) { S[i][j] = str[j]; }
    }

    vector<vector<vector<ll>>> change(4, vector<vector<ll>>(H, vector<ll>(W, 1e9)));
    vector<vector<ll>> prev_direction(H, vector<ll>(W, -1));
    deque<pair<ll, pair<ll, ll>>> d;

    rep(i, 4) { 
        d.push_front(make_pair(i, make_pair(rs, cs)));
        change[i][rs][cs] = 0;
    }

    vector<vector<ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!d.empty()) {
        pair<ll, pair<ll, ll>> p = d.front();
        d.pop_front();
        ll direction = p.first;
        ll x = p.second.first;
        ll y = p.second.second;
        ll move = change[direction][x][y];
        if (x == rt && y == ct) {
            continue;
        }
        rep(i, 4) {
            ll nx = x + dir[i][0];
            ll ny = y + dir[i][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#') {
                continue;
            }
            ll new_move = move;
            if (direction != i) {
                new_move++;
            }
            if (change[i][nx][ny] > new_move) {
                change[i][nx][ny] = new_move;
                d.push_back(make_pair(i, make_pair(nx, ny)));
            }
        }
    }

    ll min_move = min({change[0][rt][ct], change[1][rt][ct], change[2][rt][ct], change[3][rt][ct]});
    cout << min_move << endl;

    return 0;
}
