class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // Agar target total capacity se hi bada hai, toh possible nahi hai
        if (target > x + y) return false;
        
        // Edge case
        if (target == 0) return true;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        // Initial state: dono jugs khali hain
        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == target || b == target || a + b == target) {
                return true;
            }

            // Possible next states
            vector<pair<int, int>> nextStates = {
                {x, b},          // Fill jug 1
                {a, y},          // Fill jug 2
                {0, b},          // Empty jug 1
                {a, 0},          // Empty jug 2
                // Pour jug 1 -> jug 2
                {a - min(a, y - b), b + min(a, y - b)},
                // Pour jug 2 -> jug 1
                {a + min(b, x - a), b - min(b, x - a)}
            };

            for (auto next : nextStates) {
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return false;
    }
};