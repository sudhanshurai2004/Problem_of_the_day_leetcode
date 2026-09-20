class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        vector<int>fre(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)fre[s[i]-'a']++;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++){
            if(fre[i]>0){
                pq.push({fre[i],i});
            }
        }
       
        while(!pq.empty()){
            auto [f,x]=pq.top();
            pq.pop();
            if(ans.empty()||(ans.back()-'a')!=x){
                ans+=char('a'+x);
              if(f-1>0)  pq.push({f-1,x});
            }
            else{
                if(pq.empty())return "";
auto [f2,x2]=pq.top();
pq.pop();
ans+=char('a'+x2);
if(f2-1>0)pq.push({f2-1,x2});
pq.push({f,x});
            }
        }
        return ans;
    }
};