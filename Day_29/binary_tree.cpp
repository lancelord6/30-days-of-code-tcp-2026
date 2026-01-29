class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        int totalMax = INT_MIN;
        findMax(root, totalMax);
        return totalMax;
    }

    int findMax(TreeNode* node, int& totalMax) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        int leftGain = max(0, findMax(node->left, totalMax));
        int rightGain = max(0, findMax(node->right, totalMax));
        int currentPathSum = node->val + leftGain + rightGain;
        totalMax = max(totalMax, currentPathSum);
        return node->val + max(leftGain, rightGain);
    }
};