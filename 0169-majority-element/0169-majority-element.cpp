class Solution {
public:
    int majorityElement(vector<int>& nums) {
       //Moore's voting algorithm
       int count=0;
       int element;
       for(int i=0;i<nums.size();i++)
       {
           if(count==0)
           {
               count = 1;
               element= nums[i];
           }
           else if(nums[i]==element)
           {
               count++;
           }
           else    //nums[i]!=element --> to count ko decrement krde.
           {
               count--;
           }
       }
       //Now we got that element.
       int count1=0;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==element)
           {
               count1++;
           }
       }
       if(count1>nums.size()/2)
       {
           return element;
       }
       return -1;
    }
};