class Solution {
public:
    void wiggleSort(vector<int>&v) {
        int n=v.size();
        vector<int>x;

        for(int i=0;i<n;i++){
            x.push_back(v[i]);
        }
        sort(x.rbegin(),x.rend());
        int k=0;
        for(int i=1;i<n;i+=2){
            v[i]=x[k];
            k++;
        }
        for(int i=0;i<n;i+=2){
            v[i]=x[k];
            k++;
        }
        return ;



    }
};