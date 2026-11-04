class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int p= nums1.size();
    int q= nums2.size();
    double res=-1;

        vector<int> a(p + q);
    for(int i=0;i<p;i++){
        a[i]=nums1[i];
    }
    for(int i=0;i<q;i++){
        a[p+i]=nums2[i];
    }
    sort(a.begin(), a.end());
    
    if((p+q)%2==0){
        int n=(p+q)/2;
        res=(a[n-1]+a[n])/2.0;

    }
    else{
        int n=(p+q)/2;
        res=a[n];
    }
    return res;
    }
};