#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Update histogram heights for the current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Calculate max rectangle area in histogram for current row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : (i - st.top() - 1);
                maxA = max(maxA, h * w);
            }
            st.push(i);
        }
        
        return maxA;
    }
};