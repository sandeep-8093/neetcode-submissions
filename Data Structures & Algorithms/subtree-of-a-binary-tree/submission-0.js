/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    /**
     * @param {TreeNode} root
     * @param {TreeNode} subRoot
     * @return {boolean}
     */
    isSameTree(p, q) {
        if(p==null && q==null) return true;
        if(p!=null && q==null) return false;
        if(p==null && q!=null) return false;
        let left = this.isSameTree(p.left,q.left);
        let right = this.isSameTree(p.right, q.right);
        let value= p.val == q.val;
        if(left && right && value){
            return true;
        }
        else{
            return false;
        }
    }
    isSubtree(root, subRoot) {
        if(root==null){
            return false;
        }
        if(this.isSameTree(root,subRoot)){
            return true;
        }

        return (this.isSubtree(root.left, subRoot) || this.isSubtree(root.right, subRoot));
    }
}
