#define all(a) a.begin(),a.end()
class Solution {
public:
    int minimumDifference(vector<int>& v) {
        int tot = 0;
        for(int i:v)tot+=i;
        int n = v.size()/2;
        int N = (1<<n);
        vector<int> a[n+1];
        for(int i=0;i<N;i++)
        {
            int t = __builtin_popcount(i);
            int sum = 0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))>0)sum+=v[j];
            }
            a[t].push_back(sum);
        }
        for(int i=0;i<=n;i++)
        {
            sort(all(a[i]));
        }
        reverse(all(v));
        int ans = 2e9;
        int T = tot/2;
        for(int i=0;i<N;i++)
        {
            int t = __builtin_popcount(i);
            int sum = 0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))>0)sum+=v[j];
            }
            t = n-t;
            int j = lower_bound(all(a[t]),T-sum)-a[t].begin();
            if(j<a[t].size())ans = min(ans,abs(tot-2*(sum+a[t][j])));
            if(j>0)ans = min(ans,abs(tot-2*(sum+a[t][j-1]))); 
        }
        return ans;
    }
};
