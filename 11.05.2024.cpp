class Solution {
  public:
    void solve(vector<long long> &answer , long long n){
        answer.push_back(n);
        while(n != 1){
            if(n%2 == 0){
                n = static_cast<long long>(sqrt(n));
            } else {
                n = static_cast<long long>(pow(n,1.5));
            }
            answer.push_back(n);
        }
    }
    vector<long long> jugglerSequence(long long n) {
        vector<long long> answer;
        solve(answer, n);
        return answer;
    }
};