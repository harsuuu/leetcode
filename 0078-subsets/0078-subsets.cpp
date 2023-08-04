class Solution {
public:
    void print( vector<int>nums,vector<vector<int>>&ans,vector<int>output,int i)
    {
        if(i>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude
        print(nums,ans,output,i+1);

        //include
        output.push_back(nums[i]);
        print(nums,ans,output,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;   //vector of vector -->2D vector m answer
       vector<int>output; //output ka array
       int i=0;
       print(nums,ans,output,i);
       return ans;
    }
};