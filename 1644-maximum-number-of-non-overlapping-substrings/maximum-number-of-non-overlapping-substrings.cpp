class Solution {
public:vector<int> vis;
    stack<int> st;
   void dfs(int u, vector<vector<int>>& adj) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj);
            }
        }
        st.push(u);
    }
     void dfs2(int u,vector<vector<int>>& rev,vector<int>& comp) {
        vis[u] = 1;
        comp.push_back(u);
        for (auto v : rev[u]) {
            if (!vis[v]) {
                dfs2(v, rev, comp);
            }
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> si(26, -1), ei(26, -1);
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if (si[x] == -1) si[x] = i;
            ei[x] = i; }
        vector<vector<int>> pref(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }
        vector<vector<int>> adj(26);
        for (int c = 0; c < 26; c++) {
            if (si[c] == -1) continue;
            int l = si[c];
            int r = ei[c];
            for (int ch = 0; ch < 26; ch++) {
if(c==ch)continue;
                int freq = pref[r + 1][ch] - pref[l][ch];
                if (freq > 0) {
                    adj[c].push_back(ch);
                }
            }
        }
 vis.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            if (si[i] != -1 && !vis[i]) {
                dfs(i, adj); } }
        
           vector<vector<int>> rev(26);
        for (int u = 0; u < 26; u++) {
            for (auto v : adj[u]) {
                rev[v].push_back(u);
            }
        }
         vis.assign(26, 0);
        vector<vector<int>> scc;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {

                vector<int> comp;

                dfs2(node, rev, comp);

                scc.push_back(comp);
            }
        }
vector<pair<int,int>> intervals;

        for (auto &comp:scc) {
            int l = n;
            int r = -1;
            for(auto ch:comp) {
                l = min(l, si[ch]);
                r = max(r, ei[ch]);
            }

            intervals.push_back({r, l});
        }
        sort(intervals.begin(), intervals.end());
        vector<string> ans;
        int last = -1;
        for (auto &it : intervals) {
            int r = it.first;
            int l = it.second;
            if(l>last) {
                ans.push_back(s.substr(l, r - l + 1));
                last = r;
            }
        }

        return ans;


    }
};