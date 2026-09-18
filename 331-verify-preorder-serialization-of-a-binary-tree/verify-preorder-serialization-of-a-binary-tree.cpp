#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int n = preorder.length();
        
        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') continue;
            
            if (preorder[i] != '#') {
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                i--;
            }
            
            slots--;
            
            if (slots < 0) return false;
            
            if (preorder[i] != '#') {
                slots += 2;
            }
        }
        
        return slots == 0;
    }
};