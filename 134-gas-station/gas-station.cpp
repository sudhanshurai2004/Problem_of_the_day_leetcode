class Solution {
public:
    int canCompleteCircuit(vector<int>&g, vector<int>&c) {
        int n=g.size();
       
        vector<int>ps(2*n,0);
        ps[0]=g[0]-c[0];
        for(int i=1;i<2*n;i++)ps[i]=ps[i-1]-c[i%n]+g[i%n];
        set<pair<int,int>>st;
        for(int i=0;i<n-1;i++)st.insert({ps[i],i});
        for(int i=n-1;i<2*n;i++){
  st.insert({ps[i], i});
            
            int start = i - n + 1;
            
            int baseline = (start > 0) ? ps[start - 1] : 0;
            
          
            if(!st.empty() && st.begin()->first >= baseline) {
                return start;
            }
            
           
            st.erase({ps[start], start});
        }
        return -1;
    }
};