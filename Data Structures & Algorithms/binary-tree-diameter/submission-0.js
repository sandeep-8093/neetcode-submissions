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
     * @return {number}
     */
    height(root){
        if(root==null) return 0;
        this.height(root.left);
        this.height(root.right);
        return Math.max(this.height(root.left),this.height(root.right)) +1;
    }
    diameterOfBinaryTree(root) {
        if(root==null) return 0;
        let maxheightLeft= this.height(root.left);
        let maxHeightRight = this.height(root.right);
        
        let leftDiameter = this.diameterOfBinaryTree(root.left);
        let rightDiameter = this.diameterOfBinaryTree(root.right);

        return Math.max(maxheightLeft+maxHeightRight, leftDiameter, rightDiameter );

    }
}
