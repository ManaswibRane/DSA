/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode solve(int[] nums,int st,int end){
        if(st>end){
            return null;
        }
        int mid=(st+end)/2;
                TreeNode node=new TreeNode(nums[mid]);
                node.left=solve(nums,st,mid-1);
                 node.right=solve(nums,mid+1,end);
                 return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int n=nums.length;
        int st=0;
        
        return solve(nums,st,n-1);
    }
}