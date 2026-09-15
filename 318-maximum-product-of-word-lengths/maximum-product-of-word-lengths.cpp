class Solution {
public:
    int maxProduct(vector<string>&w) {
        int n=w.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>a(26,0);
            for(int k=0;k<w[i].size();k++)a[w[i][k]-'a']++;
            for(int j=i+1;j<n;j++){
                vector<int>b(26,0);
               for(int k=0;k<w[j].size();k++)b[w[j][k]-'a']++;
               bool fg=1;
               for(int k=0;k<26;k++){
                if(a[k]>0&&b[k]>0)fg=0;
                
               }
               if(fg)ans=max(ans,(int)(w[i].size()*w[j].size()));
            }
        }
        return ans;
    }
};