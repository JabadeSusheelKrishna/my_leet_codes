void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* copy = (int*) malloc (sizeof(int) * m);
    for(int i=0; i<m; i++)
    {
        copy[i] = nums1[i];
    }
    
    // Now Lets Join the Elements from Copy and num2 and store it in the nums1
    int index1 = 0, index2 = 0;
    for(int i=0; i<m+n; i++)
    {
        if(index1 < m && index2 < n)
        {
            if(copy[index1] < nums2[index2])
            {
                nums1[i] = copy[index1++];
            }
            else
            {
                nums1[i] = nums2[index2++];
            }
        }
        
        else if(index1 < m)
        {
            nums1[i] = copy[index1++];
        }
        else if(index2 < n)
        {
            nums1[i] = nums2[index2++];
        }
    }
}
