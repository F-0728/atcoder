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
    cin >> N;
    ll pow = 1;
    ll bits = 1;
    while (pow * 2 < N) {
        pow *= 2;
        bits++;
    }
    cout << bits << endl;
    cout.flush();
    pow = 1;
    rep(i, bits) {
        vll juice;
        rep(j, N) {
            if ((j + 1) & (1 << i)) {
                juice.push_back(j + 1);
            }
        }
        cout << juice.size() << " ";
        rep(j, juice.size()) {
            cout << juice.at(j) << " ";
        }
        cout << endl;
        cout.flush();
    }
    string ans;
    cin >> ans;
    ll count = 1;
    ll ansJuice = 0;
    rep(i, ans.size()) {
        if (ans.at(i) == '1') {
            ansJuice += count;
        }
        count *= 2;
    }
    if (ansJuice == 0) {
        cout << N << endl;
        cout.flush();
        return 0;
    }
    cout << ansJuice << endl;
    cout.flush();

    return 0;
}
