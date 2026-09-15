class Solution {
public:static bool cmp(const string &a,const string&b){
    return a+b>b+a;
}
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int i=0;i<nums.size();i++)v.push_back(to_string(nums[i]));
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(int i=0;i<v.size();i++)ans+=v[i];

        int idx=0;
        while(idx<ans.size()&&ans[idx]=='0')idx++;
        if(idx==ans.size())return "0";
        return ans.substr(idx);
    }
};