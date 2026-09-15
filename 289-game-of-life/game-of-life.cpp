class Solution {
public:
    void gameOfLife(vector<vector<int>>&b) {
        int n=b.size(),m=b[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int ln=0;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if(dx==0&&dy==0)continue;
                if(i+dx>=n||i+dx<0||j+dy<0||j+dy>=m||b[i+dx][j+dy]==0)continue;
                ln++;
            }
        }
        if(ln==3)v[i][j]=1;
        else if(ln==2)v[i][j]=b[i][j];
        else if(ln>3)v[i][j]=0;
        else v[i][j]=0;
    }
}
b=v;
return;
    }
};