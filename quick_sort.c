// Quick Sort of autorship of white_bluse
#include <stdio.h>
#define MAX_ARRAY 6

void init_array(int t[])
{
    for (int i = 0; i < MAX_ARRAY; i++)
    {
        printf("podaj element %d :", i + 1);
        scanf("%d", &t[i]);
    }
    printf("\n");
}
int swap(int t[], int from, int to)
{
    int temp = t[from];
    t[from] = t[to];
    t[to] = temp;
}
void print_array(int t[])
{
    for (int i = 0; i < MAX_ARRAY; i++)
        printf("%d ", t[i]);
    printf("\n");
}
void print_part(int t[], int begging, int end)
{
    for (int i = 0; i < begging; i++)
        printf("  ");
    for (int i = begging; i <= end; i++)
        printf("%d ", t[i]);
    printf("\n");
}
void quick_Sort(int array[], int left_start, int right_start)
{
    if (left_start >= right_start)
        return;

  //  print_part(array, left_start, right_start);

    int pivot = (right_start + left_start - (right_start + left_start) % 2) / 2;
    int value_pivot = array[pivot];
    int left = left_start;   
    int right = right_start; 

    while (left <= right)
    {
        while (array[left] <= value_pivot && left < right) 
            left++;
        while (array[right] > value_pivot) 
            right--;
        if (left >= right)
            break;
        else
        {
            swap(array, left, right);
            if (left == pivot)// tracking  pivot in order to put it in place of left
                pivot = right;
            if (pivot == right)
                pivot = left;
        }
    }
    // two first ifs are for putting pivot in its desired place
    if (array[pivot] < array[left] && pivot > left)
        swap(array, pivot, left);

    if (array[pivot] >= array[left] && pivot < left)
        swap(array, pivot, left);
    // quick sort realization with left as point of division
    if (left - 1 < right_start)
        quick_Sort(array, left_start, left - 1);
    if (left > left_start)
        quick_Sort(array, left, right_start);
}

int main()
{
    printf("======Quick Sort algortitm======\n");
    int array[MAX_ARRAY];
    init_array(array);
    printf("dalej przeksztalcenia: \n");
    quick_Sort(array, 0, MAX_ARRAY - 1);
    print_array(array);
    printf("=========End of Program=========\n");
    return 0;
}