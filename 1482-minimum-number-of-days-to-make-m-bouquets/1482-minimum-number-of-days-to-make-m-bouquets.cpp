class Solution {
public:
    bool func(vector<int>& bloomDay, int mid, int m, int k){
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
                if(cnt == k){
                    m--;
                    cnt = 0;
                }
            }
            else cnt = 0;

            if(m == 0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if((long long)m * k > n) return -1;
        while(low <= high){
            int mid = (low + high) / 2;
            bool reqDays = func(bloomDay, mid, m , k);
            if(reqDays == false) low = mid + 1;
            else if(reqDays == true) high = mid - 1;
        }
        return low;
    }
};