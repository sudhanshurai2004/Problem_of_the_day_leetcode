class Solution {
public:
int ans=0;
void f(int idx,set<int>&st,int n){
    if(st.empty()||idx==n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(st.find(i)==st.end())continue;
         int val=i;
        if(val%idx==0||idx%val==0)  {  st.erase(val);
            f(idx+1,st,n);
            st.insert(val);}
    }
    return ;
}
    int countArrangement(int n) {
        ans=0;
        vector<int>a;
        set<int>st;
        for(int i=1;i<=n;i++)st.insert(i);
        for(int i=1;i<=n;i++){
            int val=i;
            st.erase(val);
            f(2,st,n);
            st.insert(val);
        }
        return ans;
    }
};