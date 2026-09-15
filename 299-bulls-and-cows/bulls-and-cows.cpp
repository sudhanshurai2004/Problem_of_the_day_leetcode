class Solution {
public:
    string getHint(string a, string b) {
        vector<int>dgt1(10,0),dgt2(10,0);
        int x=0,y=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                x++;
            }
            else{
                dgt1[a[i]-'0']++;
dgt2[b[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)y+=min(dgt1[i],dgt2[i]);
        string ans=to_string(x)+'A'+to_string(y)+'B';
        return ans;
    }
};