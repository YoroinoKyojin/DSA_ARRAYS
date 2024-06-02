class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> M;
        for(int i = 0;i<nums.size();i++)
        {
            if(M.find(nums[i])==M.end())
            {
                M[nums[i]]=1;
            }
            else
            {
                M[nums[i]]++;
            }
        }
        int n = (nums.size())/3;
        vector<int>result;
        for (auto i = M.begin(); i != M.end(); i++)
        {
            if(i->second>n)
            {
                 result.push_back(i->first);
            }
        }
        return result;
    }
};