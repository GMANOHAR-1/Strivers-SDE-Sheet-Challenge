 
vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
     
    vector<int> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
           
            if ((1 << j) & i)
            {
                sum += num[j];
            }
        }
        ans.push_back(sum);
    }
 
    sort(ans.begin(), ans.end());
    return ans;
}
