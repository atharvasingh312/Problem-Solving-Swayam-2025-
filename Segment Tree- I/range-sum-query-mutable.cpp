// https://leetcode.com/problems/range-sum-query-mutable/description/

class SegTree {
    vector<int> seg;
    public:
    SegTree(int n){
        seg.resize(4*n,0);
    }
    int build(int i,int l,int r,vector<int> &nums){
        if(l==r){
            return seg[i]=nums[l];
        }
        int m=(l+r)/2;
        return seg[i]=build(i*2+1,l,m,nums)+build(i*2+2,m+1,r,nums);
    }
    int query(int i,int l,int r,int low,int high){
        if(low<=l && r<=high) return seg[i];
        else if(high<l || r<low) return 0;
        int m=(l+r)/2;
        return query(i*2+1,l,m,low,high)+query(i*2+2,m+1,r,low,high);
    }
    int update(int i,int l,int r,int ind,int new_val){
        if(l==r){
            return seg[i]=new_val;
        }
        int m=(l+r)/2;
        if(ind<=m){
            seg[i]=seg[i*2+2]+update(i*2+1,l,m,ind,new_val);
        }
        else {
            seg[i]=seg[i*2+1]+update(i*2+2,m+1,r,ind,new_val);
        }
        return seg[i];
    }
};
class NumArray {
public:
    SegTree* s;
    int n=0;
    NumArray(vector<int>& nums) {
        s=new SegTree(nums.size());
        n=nums.size();
        s->build(0,0,nums.size()-1,nums);
    }
    
    void update(int index, int val) {
        s->update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return s->query(0,0,n-1,left,right);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

