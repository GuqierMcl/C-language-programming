#include<stdio.h>
void bubble_sort(int arr[], int size)
{
    if (arr == NULL)
        return ;
 
    int i, j, temp, flag;
    for (i = 0; i < size - 1; ++i) {
        /* 每轮内循环都将一个最大值浮到最上面 */
        flag = 1;
        for (j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
				scanf
            }
        }
 
        /* 每轮内循环后输出数组的现状 */
        int k;
        printf("the %d for(): ", i);
        for (k = 0; k < size; ++k) {
            printf("%d ", arr[k]);
        }
        printf("\n");
 
        /* 已经不需要交换 */
        if (flag)
            return ;
    }
}
 
int main()
{
    int arr[] = {4, 5, 1, 7, 8, 0, 3, 2, 6, 9};
    int size = sizeof(arr) / sizeof(int);
 
    //sort
    bubble_sort(arr, size);
 
    //print
    int i = 0;
    for (i; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
 
    return 0;
}
