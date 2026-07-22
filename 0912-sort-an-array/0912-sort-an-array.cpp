class Solution {
public:

    void ms(vector<int>& arr, int low, int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        ms(arr,low, mid);
        ms(arr,mid+1,high);
        merge2(arr,low,mid,high);
    }

    void merge2(vector<int>& arr, int low, int mid, int high){
        int left = low, right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);

        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums;
    }
};