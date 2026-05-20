class Solution {
public:
    bool ispossible(vector<int> &position, int mid, int m){
        int ball = 1;
        int pos = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-pos >= mid){
                ball++;
                pos = position[i];
            }

            if(ball == m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end()); // position always be in sorted order
        int s = 1;
        int e = position[n-1]-position[0];
        int ans;

        while(s<=e){
            int mid = (s+e)/2;  //at least distance between two balls
            if(ispossible(position,mid,m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};