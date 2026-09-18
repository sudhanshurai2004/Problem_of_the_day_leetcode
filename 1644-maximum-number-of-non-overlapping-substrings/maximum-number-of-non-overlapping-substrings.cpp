#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (i == first[c]) {
                int right = last[c];
                bool valid = true;
                
                for (int j = i; j <= right; ++j) {
                    int curr_c = s[j] - 'a';
                    if (first[curr_c] < i) {
                        valid = false;
                        break;
                    }
                    right = max(right, last[curr_c]);
                }

                if (valid) {
                    intervals.push_back({i, right});
                }
            }
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return (a.second - a.first) < (b.second - b.first);
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<string> result;
        int last_end = -1;

        for (auto& interval : intervals) {
            int start = interval.first;
            int end = interval.second;

            if (start > last_end) {
                result.push_back(s.substr(start, end - start + 1));
                last_end = end;
            }
        }

        return result;
    }
};