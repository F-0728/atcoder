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
    string S;
    cin >> S;
    multiset<ll> st;
    rep(i, N) {
        st.insert(S[i] - '0');
    }
    vll squares;
    for (ll i = 0; i * i <= 1e13; i++) {
        squares.push_back(i * i);
    }
    ll ans = 0;
    rep(i, squares.size()) {
        multiset<ll> st2;
        while (st2.size() <= st.size() && squares[i] > 0) {
            st2.insert(squares[i] % 10);
            squares[i] /= 10;
        }
        if (st2.size() < st.size()) {
            ll diff = st.size() - st2.size();
            rep(j, diff) {
                st2.insert(0);
            }
        }
        if (st == st2) {
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
