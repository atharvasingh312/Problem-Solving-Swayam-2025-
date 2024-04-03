//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode* slow=head,*fast=head,*prev=NULL;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow points to mid
        TreeNode* root=new TreeNode(slow->val);
        if(prev){
            prev->next=NULL;//break list
            root->left=sortedListToBST(head);//if only one node to no need
        }
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
