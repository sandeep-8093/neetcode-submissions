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
     * @return {boolean}
     */
    height(root){
        if(root == null) return 0;
        return Math.max(this.height(root.left), this.height(root.right)) +1;
    }
    isBalanced(root) {
        if(root==null) return true;

        let leftheight= this.height(root.left);
        let rightheight = this.height(root.right);
        return (
            Math.abs(leftheight - rightheight) <= 1 &&
            this.isBalanced(root.left) &&
            this.isBalanced(root.right)
        );
    }
}
