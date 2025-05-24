#include <stdio.h>
#include <stdlib.h>

int main() {

    int nums1[] = {1,4,7,9}, nums2[] = {2,3,8,11};

    int nums1Size = 4, nums2Size = 4;

    int i=0,j=0,k=0;
        
    int numsMerge[nums1Size + nums2Size];

    while(i < nums1Size && j < nums2Size) {
        if(nums1[i] <= nums2[j]) {
            numsMerge[k] = nums1[i];
            i++;k++;
        } else if( j < nums2Size ) {
            numsMerge[k] = nums2[j];
            j++;k++;
        }
    }

    while(i < nums1Size ) {
        numsMerge[k] = nums1[i];
        i++;k++;
    }

    while(j < nums2Size ) {
        numsMerge[k] = nums2[j];
        j++;k++;
    }

    for(int p=0; p<8; p++) {
        printf("%d ", numsMerge[p]);
    }

    printf("\n\n");
 

}