//  https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTabValue=SUBMISSION


bool check(int mxt, vector<int> &boards, int k) {
    int nump=1;//number of min painters reqd.
    int t=0;
    for (int i = 0; i < boards.size(); i++) {
      if (t + boards[i] <= mxt) {
          t+=boards[i];
      }
      else{
          t=boards[i];
          nump++;
      }
    }
    if(nump<=k) return true;
    else        return false;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    //every painter can be asssigned the max hours he can paint determined at mid
    int l=0,h=0,n=boards.size();
    for (int i = 0; i < n; i++) {
        l=max(l,boards[i]);
        h+=boards[i];
    }
    int ans=-1;
    while (l <= h) {
        int m=(l+h)/2;
        if (check(m,boards,k)) {
            h=m-1;
            ans=m;
        } else {
            l=m+1;
        }
    }
    return ans;
}
