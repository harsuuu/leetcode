class Solution {
public:
    void sortColors(vector<int>& arr) {
        //We can use merge sort but it will take extra spaces.
        int c1=0;
        int c2=0;
        int c3=0;
        int n=arr.size();
        //count how many 0's
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) c1++;
        }
        //count how many 1's
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)  c2++;
        }
        //count how many 2's
        for(int i=0;i<n;i++)
        {
            if(arr[i]==2)  c3++;
        }

        for(int i=0;i<c1;i++)
        {
            arr[i]=0;
        }
        for(int i=c1;i<c1+c2;i++)
        {
            arr[i]=1;
        }
        for(int i=c1+c2;i<n;i++)
        {
            arr[i]=2;
        }

    }
};