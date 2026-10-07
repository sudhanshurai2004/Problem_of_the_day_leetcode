class Solution {
public:
    set<string> ans;
   
unordered_map<int,unordered_map<string,int>>dp;

    void dfs(string &s, int idx, string cur, int bal) {

        if (bal < 0) return;
if(dp.find(idx)!=dp.end()&&dp[idx].find(cur)!=dp[idx].end()){
    return;
}
       

       

        if (idx == s.size()) {
            if (bal != 0) return;
if(ans.empty()||ans.begin()->size()==cur.size())ans.insert(cur);
else if(ans.begin()->size()<cur.size()){
   ans.clear();
   ans.insert(cur);
}

            return;
        }

        char c = s[idx];

        if (c != '(' && c != ')') {
            dfs(s, idx + 1, cur + c, bal);
            dp[idx][cur]=idx+1-cur.size();
            return;
        }

       
        dfs(s, idx + 1, cur, bal);

      
        if (c == '(')
            dfs(s, idx + 1, cur+c, bal + 1);
        else if(bal>0)
            dfs(s, idx + 1, cur + c, bal - 1);
               dp[idx][cur]=idx+1-cur.size();
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        dp.clear();
        dfs(s, 0, "", 0);
        return vector<string>(ans.begin(), ans.end());
    }
};