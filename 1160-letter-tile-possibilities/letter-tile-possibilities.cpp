#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(string& tiles, vector<bool>& used, string& current, vector<string>& all_seq) {
        if (!current.empty()) {
            all_seq.push_back(current);
        }
        for (int i = 0; i < tiles.length(); i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(tiles[i]);
                backtrack(tiles, used, current, all_seq);
                current.pop_back();
                used[i] = false;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.length(), false);
        string current = "";
        vector<string> all_seq;

        backtrack(tiles, used, current, all_seq);

        sort(all_seq.begin(), all_seq.end());
        all_seq.erase(unique(all_seq.begin(), all_seq.end()), all_seq.end());

        return all_seq.size();
    }
};