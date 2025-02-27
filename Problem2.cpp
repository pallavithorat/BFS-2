class Solution {
public:
int xdepth, ydepth, xparent, yparent;

void depth(TreeNode* root, int x, int y, int dep, int par_val){
    if(root==NULL) return;
    if(root->val==x){
        xdepth=dep;
        xparent=par_val;
        return;
    }
    if(root->val==y){
        ydepth=dep;
        yparent=par_val;
        return;
    }
    depth(root->left, x, y, dep+1, root->val);
    depth(root->right, x, y, dep+1, root->val);
}
    bool isCousins(TreeNode* root, int x, int y) {
         if(root->val==x || root->val==y) return false;
    depth(root, x, y, 0, 0);
    
    if(xdepth==ydepth && xparent!=yparent) return true;
    return false;
        
    }
};