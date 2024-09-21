class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum=0, rightSum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        } 
        maxi=leftSum;
        int rightIndex = n-1;
        for(int j=k-1;j>=0;j--)
        {
            leftSum-=cardPoints[j];
            rightSum+=cardPoints[rightIndex];
            rightIndex--;

            maxi=max(maxi,leftSum+rightSum);
        }
    return maxi;
    }
};