class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
    
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        
       
        for (string& word : words) {
            int currIdx = -1;
            bool isSub = true;
            
            for (char c : word) {
                auto& vec = pos[c - 'a'];
               
                auto it = upper_bound(vec.begin(), vec.end(), currIdx);
                
               
                if (it == vec.end()) {
                    isSub = false;
                    break;
                }
              
                currIdx = *it;
            }
            
            if (isSub) {
                count++;
            }
        }
        
        return count;
    }
};