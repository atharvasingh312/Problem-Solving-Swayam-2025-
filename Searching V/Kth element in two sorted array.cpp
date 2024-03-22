//https://www.codingninjas.com/studio/problems/k-th-element-of-2-sorted-array_1164159?leftPanelTabValue=PROBLEM


int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    if(n>m) return kthElement(arr2,arr1,m,n,k);
    int l=max(0,k-m),h=min(k,n);
    while (l <= h) {
        int mid=(l+h)/2;
        int m2=k-mid;
        int l1=(mid>0)?arr1[mid-1]:-1;
        int r1=(mid<n)?arr1[mid]:1000000001;
        int l2=(m2>0)?arr2[m2-1]:-1;
        int r2=(m2<m)?arr2[m2]:1000000001;
        if (l1 <= r2 && l2 <= r1) {
           //cout <<l1 << "  " << l2;
          return max(l1,l2);
        } 
        else if (l1 > r2 ) h = mid - 1;
        else                  l=mid+1;
    }
    return -1;
}
