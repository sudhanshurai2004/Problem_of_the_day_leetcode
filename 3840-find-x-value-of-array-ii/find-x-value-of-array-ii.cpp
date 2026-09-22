#include <vector>
#include <cstring>

using namespace std;

class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k_val;
    vector<Node> tree;
    vector<int> nums_arr;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (1LL * left.prod * right.prod) % k_val;
        for (int i = 0; i < k_val; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        for (int r2 = 0; r2 < k_val; ++r2) {
            if (right.cnt[r2] == 0) continue;
            int target = (1LL * left.prod * r2) % k_val;
            res.cnt[target] += right.cnt[r2];
        }
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int rem = nums_arr[l] % k_val;
            tree[node].prod = rem;
            memset(tree[node].cnt, 0, sizeof(tree[node].cnt));
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            int rem = val % k_val;
            tree[node].prod = rem;
            memset(tree[node].cnt, 0, sizeof(tree[node].cnt));
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        } else if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        } else {
            Node left_res = query(2 * node, l, mid, ql, qr);
            Node right_res = query(2 * node + 1, mid + 1, r, ql, qr);
            return mergeNodes(left_res, right_res);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        k_val = k;
        nums_arr = nums;
        tree.resize(4 * n);
        
        build(1, 0, n - 1);
        
        vector<int> result;
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int xi = q[3];
            
            update(1, 0, n - 1, idx, val);
            
            if (start >= n) {
                result.push_back(0);
                continue;
            }
            
            Node resNode = query(1, 0, n - 1, start, n - 1);
            result.push_back(resNode.cnt[xi]);
        }
        
        return result;
    }
};