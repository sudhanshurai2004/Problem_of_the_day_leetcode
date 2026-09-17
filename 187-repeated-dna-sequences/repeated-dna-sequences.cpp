class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        
        for(int i=0;i+10<=s.size();i++){
            mp[s.substr(i,10)]++;
        }vector<string>ans;
        for(auto it:mp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};