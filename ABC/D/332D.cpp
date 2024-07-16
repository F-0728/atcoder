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
    ll H, W;
    cin >> H >> W;
    vll A(H * W);
    rep(i, H) rep(j, W) cin >> A[i * W + j];
    vll B(H * W);
    rep(i, H) rep(j, W) cin >> B[i * W + j];

    queue<vll> q;
    q.push(A);
    map<vll, ll> mp;
    mp[A] = 0;
    while (!q.empty()) {
        vll a = q.front();
        q.pop();
        // outv(a);
        ll d = mp[a];
        if (a == B) {
            cout << d << endl;
            return 0;
        }
        rep(i, H) {
            if (i + 1 < H) {
                vll b = a;
                rep(j, W) {
                    swap(b[i * W + j], b[(i + 1) * W + j]);
                }
                if (mp.find(b) == mp.end()) {
                    mp[b] = d + 1;
                    q.push(b);
                }
            }
        }
        rep(j, W) {
            if (j + 1 < W) {
                vll b = a;
                rep(i, H) {
                    swap(b[i * W + j], b[i * W + j + 1]);
                }
                if (mp.find(b) == mp.end()) {
                    mp[b] = d + 1;
                    q.push(b);
                }
            }
        }
    }
    cout << -1 << endl;


    return 0;
}
