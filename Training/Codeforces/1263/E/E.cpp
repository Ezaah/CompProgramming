#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

size_t maxn = 5 * 1e5;

struct Node {
    ll maxv, minv;
    size_t beg, end;

    Node() {}
    Node(size_t b, size_t e) {
        beg = b;
        end = e;
        maxv = 0;
        minv = 0;
    }
};

vector<Node> tree(4 * maxn);

void build(size_t pos, size_t l, size_t r) {
    if (l == r) {
        tree[pos] = Node(l, r);
    } else {

        size_t m = (l + r) / 2;
        build(2 * pos, l, m);
        build(2 * pos + 1, m + 1, r);
        tree[pos] = Node(l, r);
    }
}
void update(size_t pos, size_t l, size_t r, ll add) {

    if (l > r) {
        return;
    }
    if (l == tree[pos].beg && r == tree[pos].end) {
        tree[pos].maxv += add;
        tree[pos].minv += add;
    } else {
        size_t m = (tree[pos].beg + tree[pos].end) / 2;
        update(2 * pos, l, min(r, m), add);
        update(2 * pos + 1, max(m + 1, l), r, add);
        tree[pos].maxv = max(tree[2 * pos].maxv, tree[2 * pos + 1].maxv);
        tree[pos].minv = min(tree[2 * pos].minv, tree[2 * pos + 1].minv);
    }
}

pair<ll, ll> query(size_t pos, size_t l, size_t r) {
    if (l > r) {
        return make_pair(1e10, -1e10);
    }
    if (l == tree[pos].beg && r == tree[pos].end) {
        return make_pair(tree[pos].minv, tree[pos].maxv);
    }

    size_t m = (l + r) / 2;
    auto left = query(2 * pos, l, min(r, m));
    auto right = query(2 * pos + 1, max(l, m + 1), r);

    return make_pair(min(left.first, right.first), max(left.second, right.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string cmds;
    cin >> n >> cmds;

    ll pos = 0;
    ll sum = 0;

    vector<char> text(maxn);
    cout << "Building tree" << endl;
    build(1, 0, maxn);
    for (char &cmd : cmds) {
        cout << "Processing command " << cmd << " at pos " << pos << endl;
        if (cmd == 'L') {
            pos = max((ll)0, pos - 1);
        } else if (cmd == 'R') {
            pos++;
        } else if (cmd == '(' && text[pos] != '(') {
            update(1, pos, maxn, 1);
            sum++;
            text[pos] = cmd;
        } else if (cmd == ')' && text[pos] != ')') {
            update(1, pos, maxn, -1);
            sum--;
            text[pos] = cmd;
        } else {
            if (text[pos] == '(') {
                update(1, pos, maxn, -1);
                sum--;
            } else if (text[pos] == ')') {
                update(1, pos, maxn, 1);
                sum++;
            }
            text[pos] = cmd;
        }

        cout << "Querying state" << endl;
        auto res = query(1, 0, maxn);
        cout << "State is min=" << res.first << " max=" << res.second << " sum=" << sum << endl;
        for (auto &nd : tree) {
            if (nd.end > pos + 1) {
                break;
            }
            cout << "{" << nd.minv << " " << nd.maxv << "} ";
        }
        cout << endl;
        if (sum < 0 || res.first != 0) {
            cout << "-1 ";
        } else {
            cout << res.second << " ";
        }

        for (char &chr : text) {
            if (!chr) {
                break;
            }
            cout << chr;
        }
        cout << endl;
    }
}
