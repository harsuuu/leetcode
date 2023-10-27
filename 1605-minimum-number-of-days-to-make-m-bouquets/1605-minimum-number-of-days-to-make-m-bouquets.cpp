class Solution {
public:
bool possible(vector<int>& bloomDay, int day, int m, int k)
{
    int n=bloomDay.size();
	int counter=0;
	int numBouquet=0;
	for(int i=0;i<n;i++)
	{
		if(bloomDay[i]<=day)
		{
			counter++;
		}
		else{			//Yani day chota ho gya hoga to counter ruk jayega.
			numBouquet+=(counter/k);
			counter=0;
		}
	}
    numBouquet+=(counter/k);	
	if(numBouquet>=m)
	{
		return true;
	}
	return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i <n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    //isse overflow nhi hoga.
    long long val = m * 1ll * k * 1ll;  
	//impossible case
	if(val>bloomDay.size())	return -1;

    int low=mini;
    int ans=-1;
    int high=maxi;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(possible(bloomDay,mid,m,k)==true)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
return ans;
    }
};