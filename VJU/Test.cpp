#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Op {
    int l, r;
};

bool is_palindrome(const string& s) {
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - 1 - i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<Op> ops;
    int limit = n - 4; 
    
    for (int i = 0; i < limit; ++i) {
        if (s[i] == t[i]) continue;
        if (s[i] == s[i+1]) {
            ops.push_back({i + 1, i + 2}); 
            s[i] = (s[i] == '0' ? '1' : '0');
            s[i+1] = (s[i+1] == '0' ? '1' : '0');
        }
        else if (s[i] == s[i+2]) {
            ops.push_back({i + 1, i + 3});
            s[i] = (s[i] == '0' ? '1' : '0');
            s[i+1] = (s[i+1] == '0' ? '1' : '0');
            s[i+2] = (s[i+2] == '0' ? '1' : '0');
        }
        else {
            ops.push_back({i + 2, i + 3});
            s[i+1] = (s[i+1] == '0' ? '1' : '0');
            s[i+2] = (s[i+2] == '0' ? '1' : '0');
            
            ops.push_back({i + 1, i + 3});
            s[i] = (s[i] == '0' ? '1' : '0');
            s[i+1] = (s[i+1] == '0' ? '1' : '0');
            s[i+2] = (s[i+2] == '0' ? '1' : '0');
        }
    }

    string s_suff = s.substr(n - 4);
    string t_suff = t.substr(n - 4);

    if (s_suff == t_suff) {
        cout << ops.size() << "\n";
        for (auto op : ops) cout << op.l << " " << op.r << "\n";
        return;
    }

    queue<string> q;
    q.push(s_suff);
    map<string, string> parent;
    map<string, Op> move_taken;
    map<string, bool> visited;

    visited[s_suff] = true;
    parent[s_suff] = ""; 

    bool found = false;

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        if (u == t_suff) {
            found = true;
            break;
        }

        for (int len = 2; len <= 4; ++len) {
            for (int i = 0; i <= 4 - len; ++i) {
                string sub = u.substr(i, len);
                if (is_palindrome(sub)) {
                    string v = u;
                    for (int k = i; k < i + len; ++k) {
                        v[k] = (v[k] == '0' ? '1' : '0');
                    }
                    
                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        move_taken[v] = {(n - 4) + i + 1, (n - 4) + i + len};
                        q.push(v);
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "-1\n";
    } else {
        // Backtrack ath
        vector<Op> suffix_ops;
        string curr = t_suff;
        while (curr != s_suff) {
            suffix_ops.push_back(move_taken[curr]);
            curr = parent[curr];
        }
        reverse(suffix_ops.begin(), suffix_ops.end());

        for (auto op : suffix_ops) ops.push_back(op);

        cout << ops.size() << "\n";
        for (auto op : ops) cout << op.l << " " << op.r << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
