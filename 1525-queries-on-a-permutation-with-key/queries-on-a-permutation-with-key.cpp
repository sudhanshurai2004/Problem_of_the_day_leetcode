#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(p.begin(), p.end(), 1);
        
        vector<int> result;
        for (int q : queries) {
            auto it = find(p.begin(), p.end(), q);
            int pos = distance(p.begin(), it);
            result.push_back(pos);
            
            p.erase(it);
            p.insert(p.begin(), q);
        }
        
        return result;
    }
};