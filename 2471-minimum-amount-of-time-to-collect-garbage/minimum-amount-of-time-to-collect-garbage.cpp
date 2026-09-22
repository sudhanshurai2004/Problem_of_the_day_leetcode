#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        
        vector<int> pref_travel(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            pref_travel[i + 1] = pref_travel[i] + travel[i];
        }
        
        int last_m = -1, last_p = -1, last_g = -1;
        int count_m = 0, count_p = 0, count_g = 0;
        
        for (int i = 0; i < n; ++i) {
            for (char c : garbage[i]) {
                if (c == 'M') {
                    last_m = i;
                    count_m++;
                } else if (c == 'P') {
                    last_p = i;
                    count_p++;
                } else if (c == 'G') {
                    last_g = i;
                    count_g++;
                }
            }
        }
        
        int total_time = 0;
        total_time += count_m + (last_m != -1 ? pref_travel[last_m] : 0);
        total_time += count_p + (last_p != -1 ? pref_travel[last_p] : 0);
        total_time += count_g + (last_g != -1 ? pref_travel[last_g] : 0);
        
        return total_time;
    }
};