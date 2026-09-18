class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&v) {
        int n=v.size(),m=v[0].size();
        vector<vector<bool>>fg1(n,vector<bool>(m,0));
        vector<vector<bool>>fg2(n,vector<bool>(m,0));
        queue<pair<int,int>>q1,q2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0||i==0){
                    q1.push({i,j});
                    fg1[i][j]=1;
                }
                if(j==m-1||i==n-1){
                    q2.push({i,j});
                    fg2[i][j]=1;
                }
            }
        }
        while(!q1.empty()){
            auto [x,y]=q1.front();
            q1.pop();
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(abs(dx+dy)!=1)continue;
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx>=n||nx<0||ny<0||ny>=m||fg1[nx][ny]||v[nx][ny]<v[x][y])continue;
                    q1.push({nx,ny});
                    fg1[nx][ny]=1;                }
            }
        }
         while(!q2.empty()){
            auto [x,y]=q2.front();
            q2.pop();
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    if(abs(dx+dy)!=1)continue;
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx>=n||nx<0||ny<0||ny>=m||fg2[nx][ny]||v[nx][ny]<v[x][y])continue;
                    q2.push({nx,ny});
                    fg2[nx][ny]=1;                }
            }
        }
        vector<vector<int>>ans;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(fg1[i][j]&&fg2[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};