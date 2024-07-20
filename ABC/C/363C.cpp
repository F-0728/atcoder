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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vll index(N);
    rep(i, N) index.at(i) = i;
    map<char, ll> count;
    rep(i, N) count[S.at(i)]++;
    vector<char> hasSame;
    rep(i, 26) {
        if (count['a' + i] > 1) {
            hasSame.push_back('a' + i);
            break;
        }
    }
    ll tmp = 1;
    rep(i, N) {
        tmp *= i + 1;
    }
    ll dup = 0;
    rep(i, 26) {
        if (count['a' + i] > 1) {
            dup += count['a' + i];
        }
    }
    if (dup < K) {
        cout << tmp << endl;
        return 0;
    }
    ll ans = 0;
    map<string, bool> mp;
    do {
        string s;
        rep(i, N) s += S.at(index.at(i));
        if (mp[s]) continue;
        mp[s] = true;
        bool pflag;

        rep(i, N - K + 1) {
            pflag = true;

            rep(j, K / 2) {
                if (count[s.at(i + j)] < 2) pflag = false;
                if (s.at(i + j) != s.at(i + K - j - 1)) {
                    pflag = false;
                }
            }

            if (pflag) break;
        }

        if (!pflag) {
            // cout << s << endl;
            ans++;
        }
    } while (next_permutation(index.begin(), index.end()));
    cout << ans << endl;

    return 0;
}
