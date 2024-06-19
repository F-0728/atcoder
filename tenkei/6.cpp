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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    priority_queue<pair<char, ll>, vector<pair<char, ll>>, greater<pair<char, ll>>> pq;
    ll lstIdx = 0;
    string ans;

    rep(i, N) {
        pq.push({S.at(i), i});
        if (i >= N - K) {
            while (1) {
                pair<char, ll> top = pq.top();
                char ch = top.first;
                ll idx = top.second;
                pq.pop();
                if (lstIdx <= idx) {
                    lstIdx = idx + 1;
                    ans.push_back(ch);
                    break;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
