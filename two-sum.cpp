class Solution {
public:
    struct data{
        int value;
        int index;
        bool operator < (const data& other) const{
            return value < other.value;
        }
    };
    int binary_search(vector<data> &numbers,int l,int r,int key){
        while(r > l){
            int m = (l + r)/2;
            if (key == numbers[m].value){
                return numbers[m].index;
            }
            if(key < numbers[m].value){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector<data> ans;
        int size = numbers.size();
        for(int i=0;i<numbers.size();i++){
            data a;a.index = i;a.value = numbers[i];
            ans.push_back(a);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<size;i++){
            int index = binary_search(ans,i+1,size,target-ans[i].value);
            if(index!=-1){
                res.push_back(ans[i].index + 1);
                res.push_back(index + 1);
                sort(res.begin(),res.end());
                break;
            }
        }
        return res;
    }
};