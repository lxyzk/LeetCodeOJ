#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x),left(NULL),right(NULL)
    {

    }
};

class Solution
{
    public:
        TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
        {

            if(p == q)
            {
                return p;
            }

            if(!p || !q)
            {
                 return p?p:q;
            }

            TreeNode * temp;
            if(p->val > q->val)
            {
                temp = p;
                p = q;
                q = temp;
            }

            if(!root)
            {
                return q;
            }

            if(p->val <= root->val && q->val >= root->val)
            {
                 return root;
            }

            if(q->val < root->val)
            {
                return lowestCommonAncestor(root->left,p,q);
            }

            if(p->val > root->val)
            {
                 return lowestCommonAncestor(root->right,p,q);
            }
        }
};

int main()
{
     return 0;
}
