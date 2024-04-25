//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ws=cardPoints.size()-k;
        int b=0,e=0,sum=0,mx=INT_MAX,ts=0;
        while(e<ws){
            sum+=cardPoints[e];
            ts+=cardPoints[e];
            e++;
        }
        mx=min(mx,sum);
        while(e<cardPoints.size()){
            sum+=cardPoints[e]-cardPoints[b];
            ts+=cardPoints[e];
            b++;
            e++;
            mx=min(mx,sum);
        }
        return ts-mx;
    }
};
