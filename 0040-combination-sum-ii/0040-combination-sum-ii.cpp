#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Early stopping: if candidate exceeds remaining target, stop further exploration
            if (candidates[i] > target) break;

            // Skip duplicate elements at the same level of recursion
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Step 1: Sort candidates to handle duplicates and enable pruning
        std::sort(candidates.begin(), candidates.end());

        // Step 2: Start backtracking recursion
        backtrack(0, target, candidates, current, result);

        return result;
    }
};