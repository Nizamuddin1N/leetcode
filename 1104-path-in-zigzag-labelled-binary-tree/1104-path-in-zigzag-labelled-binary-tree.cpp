class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while (label >= 1) {
            ans.push_back(label);
            int level = log2(label);
            int start = 1 << level;
            int end = (1 << (level + 1)) - 1;
            int normalLabel = label;
            if (level % 2 == 1) {
                normalLabel = start + end - label;
            }
            int parent = normalLabel / 2;
            int parentLevel = level - 1;
            if (parentLevel >= 0 && parentLevel % 2 == 1) {
                int parentStart = 1 << parentLevel;
                int parentEnd = (1 << (parentLevel + 1)) - 1;
                parent = parentStart + parentEnd - parent;
            }
            label = parent;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};