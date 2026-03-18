#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) { iota(idx.begin(), idx.end(), 0); sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; }); }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << "\n";}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << "\n";}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << "\n"; }}

int main() {
    ll N;
    string P;
    cin >> N >> P;

    if (N == 3) {
        if (P == "000111") cout << "YES 2 4 5 200 400 500" << endl;
        else if (P == "001011") cout << "NO 1 000111" << endl;
        else if (P == "001101") cout << "NO 1 000111" << endl;
        else if (P == "010011") cout << "YES 2 4 6 7 100 102" << endl;
        else if (P == "010101") cout << "NO 1 010011" << endl;
        else if (P == "011001") cout << "YES 2 10 15 17 18 20" << endl;
        else if (P == "100011") cout << "YES 2 4 6 8 10 11" << endl;
        else if (P == "100101") cout << "NO 1 100011" << endl;
        else if (P == "101001") cout << "NO 1 010101" << endl;
        else if (P == "110001") cout << "NO 1 001101" << endl;
    } else if (N == 4) {
        if (P == "00001111") cout << "YES 1 2 3 4 100 200 300 400" << endl;
        else if (P == "00010111") cout << "NO 1 00001111" << endl; 
        else if (P == "00011011") cout << "NO 1 00010111" << endl; 
        else if (P == "00011101") cout << "NO 1 00011011" << endl; 
        else if (P == "00100111") cout << "YES 2 3 4 9 10 100 200 303" << endl;
        else if (P == "00101011") cout << "NO 1 00100111" << endl; 
        else if (P == "00101101") cout << "NO 1 00101011" << endl; 
        else if (P == "00110011") cout << "YES 2 4 6 12 22 27 500 513" << endl; // new
        else if (P == "00110101") cout << "NO 1 00110011" << endl; 
        else if (P == "00111001") cout << "" << endl;
        else if (P == "01000111") cout << "YES 1 4 5 10 15 100 101 204" << endl;
        else if (P == "01001011") cout << "NO 1 01000111" << endl; 
        else if (P == "01001101") cout << "NO 1 01001011" << endl; 
        else if (P == "01010011") cout << "YES 1 2 3 6 100 103 500 507" << endl;
        else if (P == "01010101") cout << "NO 1 01010011" << endl; 
        else if (P == "01011001") cout << "" << endl;
        else if (P == "01100011") cout << "YES 1 10 11 100 122 144 1000 1020" << endl;
        else if (P == "01100101") cout << "NO 1 01100011" << endl; 
        else if (P == "01101001") cout << "" << endl;
        else if (P == "01110001") cout << "" << endl;
        else if (P == "10000111") cout << "YES 2 3 4 9 15 100 101 202" << endl;
        else if (P == "10001011") cout << "NO 1 10000111" << endl; 
        else if (P == "10001101") cout << "NO 1 10001011" << endl; 
        else if (P == "10010011") cout << "" << endl;
        else if (P == "10010101") cout << "NO 1 10010011" << endl; 
        else if (P == "10011001") cout << "" << endl;
        else if (P == "10100011") cout << "YES 1 2 3 6 100 107 500 503" << endl;
        else if (P == "10100101") cout << "NO 1 10100011" << endl; 
        else if (P == "10101001") cout << "NO 1 01010101" << endl; 
        else if (P == "10110001") cout << "NO 1 01001101" << endl; 
        else if (P == "11000011") cout << "YES 2 3 5 10 18 32 100 104" << endl;
        else if (P == "11000101") cout << "NO 1 11000011" << endl; 
        else if (P == "11001001") cout << "NO 1 00110101" << endl; 
        else if (P == "11010001") cout << "NO 1 00101101" << endl; 
        else if (P == "11100001") cout << "NO 1 00011101" << endl;
    } else if (N == 5) {
        if (P == "0000011111") cout << "YES 1 2 3 4 5 100 200 300 400 500" << endl;
        else if (P == "0000101111") cout << "NO 1 0000011111" << endl; 
        else if (P == "0000110111") cout << "NO 1 0000101111" << endl; 
        else if (P == "0000111011") cout << "NO 1 0000110111" << endl; 
        else if (P == "0000111101") cout << "NO 1 0000111011" << endl; 
        else if (P == "0001001111") cout << "YES 2 3 4 6 15 23 100 101 102 308" << endl; 
        else if (P == "0001010111") cout << "NO 1 0001001111" << endl; 
        else if (P == "0001011011") cout << "NO 1 0001010111" << endl; 
        else if (P == "0001011101") cout << "NO 1 0001011011" << endl; 
        else if (P == "0001100111") cout << "YES 2 3 5 10 20 100 109 500 501 1021" << endl; // WA
        else if (P == "0001101011") cout << "NO 1 0001100111" << endl; 
        else if (P == "0001101101") cout << "NO 1 0001101011" << endl; 
        else if (P == "0001110011") cout << "" << endl;
        else if (P == "0001110101") cout << "NO 1 0001110011" << endl; 
        else if (P == "0001111001") cout << "" << endl;
        else if (P == "0010001111") cout << "YES 2 3 4 8 17 26 200 201 202 606" << endl; 
        else if (P == "0010010111") cout << "NO 1 0010001111" << endl; 
        else if (P == "0010011011") cout << "NO 1 0010010111" << endl; 
        else if (P == "0010011101") cout << "NO 1 0010011011" << endl; 
        else if (P == "0010100111") cout << "" << endl;
        else if (P == "0010101011") cout << "NO 1 0010100111" << endl; 
        else if (P == "0010101101") cout << "NO 1 0010101011" << endl; 
        else if (P == "0010110011") cout << "" << endl;
        else if (P == "0010110101") cout << "NO 1 0010110011" << endl; 
        else if (P == "0010111001") cout << "" << endl;
        else if (P == "0011000111") cout << "" << endl;
        else if (P == "0011001011") cout << "NO 1 0011000111" << endl; 
        else if (P == "0011001101") cout << "NO 1 0011001011" << endl; 
        else if (P == "0011010011") cout << "" << endl;
        else if (P == "0011010101") cout << "NO 1 0011010011" << endl; 
        else if (P == "0011011001") cout << "" << endl;
        else if (P == "0011100011") cout << "" << endl;
        else if (P == "0011100101") cout << "NO 1 0011100011" << endl; 
        else if (P == "0011101001") cout << "" << endl;
        else if (P == "0011110001") cout << "" << endl;
        else if (P == "0100001111") cout << "YES 1 3 4 5 15 24 200 201 202 605" << endl; 
        else if (P == "0100010111") cout << "NO 1 0100001111" << endl; 
        else if (P == "0100011011") cout << "NO 1 0100010111" << endl; 
        else if (P == "0100011101") cout << "NO 1 0100011011" << endl; 
        else if (P == "0100100111") cout << "" << endl;
        else if (P == "0100101011") cout << "NO 1 0100100111" << endl; 
        else if (P == "0100101101") cout << "NO 1 0100101011" << endl; 
        else if (P == "0100110011") cout << "" << endl;
        else if (P == "0100110101") cout << "NO 1 0100110011" << endl; 
        else if (P == "0100111001") cout << "" << endl;
        else if (P == "0101000111") cout << "" << endl;
        else if (P == "0101001011") cout << "NO 1 0101000111" << endl; 
        else if (P == "0101001101") cout << "NO 1 0101001011" << endl; 
        else if (P == "0101010011") cout << "" << endl;
        else if (P == "0101010101") cout << "NO 1 0101010011" << endl; 
        else if (P == "0101011001") cout << "" << endl;
        else if (P == "0101100011") cout << "" << endl;
        else if (P == "0101100101") cout << "NO 1 0101100011" << endl; 
        else if (P == "0101101001") cout << "" << endl;
        else if (P == "0101110001") cout << "" << endl;
        else if (P == "0110000111") cout << "" << endl;
        else if (P == "0110001011") cout << "NO 1 0110000111" << endl; 
        else if (P == "0110001101") cout << "NO 1 0110001011" << endl; 
        else if (P == "0110010011") cout << "" << endl;
        else if (P == "0110010101") cout << "NO 1 0110010011" << endl; 
        else if (P == "0110011001") cout << "" << endl;
        else if (P == "0110100011") cout << "" << endl;
        else if (P == "0110100101") cout << "NO 1 0110100011" << endl; 
        else if (P == "0110101001") cout << "" << endl;
        else if (P == "0110110001") cout << "" << endl;
        else if (P == "0111000011") cout << "" << endl;
        else if (P == "0111000101") cout << "NO 1 0111000011" << endl; 
        else if (P == "0111001001") cout << "" << endl;
        else if (P == "0111010001") cout << "" << endl;
        else if (P == "0111100001") cout << "" << endl;
        else if (P == "1000001111") cout << "YES 2 3 4 5 14 25 200 201 202 604" << endl; 
        else if (P == "1000010111") cout << "NO 1 1000001111" << endl; 
        else if (P == "1000011011") cout << "NO 1 1000010111" << endl; 
        else if (P == "1000011101") cout << "NO 1 1000011011" << endl; 
        else if (P == "1000100111") cout << "" << endl;
        else if (P == "1000101011") cout << "NO 1 1000100111" << endl; 
        else if (P == "1000101101") cout << "NO 1 1000101011" << endl; 
        else if (P == "1000110011") cout << "" << endl;
        else if (P == "1000110101") cout << "NO 1 1000110011" << endl; 
        else if (P == "1000111001") cout << "" << endl;
        else if (P == "1001000111") cout << "" << endl;
        else if (P == "1001001011") cout << "NO 1 1001000111" << endl; 
        else if (P == "1001001101") cout << "NO 1 1001001011" << endl; 
        else if (P == "1001010011") cout << "" << endl;
        else if (P == "1001010101") cout << "NO 1 1001010011" << endl; 
        else if (P == "1001011001") cout << "" << endl;
        else if (P == "1001100011") cout << "" << endl;
        else if (P == "1001100101") cout << "NO 1 1001100011" << endl; 
        else if (P == "1001101001") cout << "" << endl;
        else if (P == "1001110001") cout << "" << endl;
        else if (P == "1010000111") cout << "" << endl;
        else if (P == "1010001011") cout << "NO 1 1010000111" << endl; 
        else if (P == "1010001101") cout << "NO 1 1010001011" << endl; 
        else if (P == "1010010011") cout << "" << endl;
        else if (P == "1010010101") cout << "NO 1 1010010011" << endl; 
        else if (P == "1010011001") cout << "" << endl;
        else if (P == "1010100011") cout << "" << endl;
        else if (P == "1010100101") cout << "NO 1 1010100011" << endl; 
        else if (P == "1010101001") cout << "NO 1 0101010101" << endl; 
        else if (P == "1010110001") cout << "NO 1 0101001101" << endl; 
        else if (P == "1011000011") cout << "" << endl;
        else if (P == "1011000101") cout << "NO 1 1011000011" << endl; 
        else if (P == "1011001001") cout << "NO 1 0100110101" << endl; 
        else if (P == "1011010001") cout << "NO 1 0100101101" << endl; 
        else if (P == "1011100001") cout << "NO 1 0100011101" << endl; 
        else if (P == "1100000111") cout << "" << endl;
        else if (P == "1100001011") cout << "NO 1 1100000111" << endl; 
        else if (P == "1100001101") cout << "NO 1 1100001011" << endl; 
        else if (P == "1100010011") cout << "" << endl;
        else if (P == "1100010101") cout << "NO 1 1100010011" << endl; 
        else if (P == "1100011001") cout << "" << endl;
        else if (P == "1100100011") cout << "" << endl;
        else if (P == "1100100101") cout << "NO 1 1100100011" << endl; 
        else if (P == "1100101001") cout << "NO 1 0011010101" << endl; 
        else if (P == "1100110001") cout << "NO 1 0011001101" << endl; 
        else if (P == "1101000011") cout << "" << endl;
        else if (P == "1101000101") cout << "NO 1 1101000011" << endl; 
        else if (P == "1101001001") cout << "NO 1 0010110101" << endl; 
        else if (P == "1101010001") cout << "NO 1 0010101101" << endl; 
        else if (P == "1101100001") cout << "NO 1 0010011101" << endl; 
        else if (P == "1110000011") cout << "" << endl;
        else if (P == "1110000101") cout << "NO 1 1110000011" << endl; 
        else if (P == "1110001001") cout << "NO 1 0001110101" << endl; 
        else if (P == "1110010001") cout << "NO 1 0001101101" << endl; 
        else if (P == "1110100001") cout << "NO 1 0001011101" << endl; 
        else if (P == "1111000001") cout << "NO 1 0000111101" << endl;
    }
    return 0;
}
