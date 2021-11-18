static int _cmp(const int * left, const int * right)
{ return (*left - *right); }

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, * curr1 = nums1, *curr2 = nums2;
    int * ans = (int*)malloc((m+n)*sizeof(int));
    
    for(i=0; i<m;   ++i) ans[i] = nums1[i];
    for(i=m; i<m+n; ++i) ans[i] = nums2[i-m];
    for(i=0; i<m+n; ++i) nums1[i] = ans[i];
    qsort((void*)nums1, m+n, sizeof(int), _cmp);
    
    free(ans);
}