/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool identy(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        else if((root!=NULL && subRoot==NULL) || (root==NULL && subRoot!=NULL))return false;
        else
        {
            if(root->val!=subRoot->val)return false;
            return (identy(root->left,subRoot->left) && identy(root->right,subRoot->right));
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       
        queue<TreeNode *>A;
        A.push(root);
        while(!A.empty())
        {
            TreeNode *check=A.front();
            A.pop();
            if(check->val==subRoot->val)
            {
                if(identy(check,subRoot))
                {
                    return true;
                }
            }
            if(check->left)A.push(check->left);
            if(check->right)A.push(check->right);
        }
        return false;
    }
};
