class Solution {
public:
    void moveZeroes(vector<int>& nums){
    vector<int>temp;
    //Step 1 : Put the non zero element in to temp. 
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            temp.push_back(nums[i]);
        }
    }
    //Step 2: Put the temp array into main array
    for(int i=0;i<temp.size();i++)
    {
        nums[i]=temp[i];
    }
    //Step 3 :Store Zero in Remaining place in that array.
    for(int i=temp.size();i<nums.size();i++)
    {
        nums[i]=0;
    } 
    }
};