class Solution {
public:
void f(int idx,string &s,vector<string>&ans,string &v){
    if(idx==s.size()){
        ans.push_back(v);
        return ;
    }
    int i=idx;
    if(s[idx]<='9'&&s[idx]>='0'){
        v+=s[i];
        f(idx+1,s,ans,v);
        v.pop_back();
        
        }
        else{
            int val;
            if(s[i]<='Z'&&s[i]>='A'){
                val=s[i]-'A';
            }else val=s[i]-'a';
             v+='A'+val;
        f(idx+1,s,ans,v);
        v.pop_back();
         v+='a'+val;
        f(idx+1,s,ans,v);
        v.pop_back();
        }

}
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string v;
        f(0,s,ans,v);
        return ans;
    }
};