#include <iostream>





void InsertionSort(int* arr, int size)
{
    int temp;
    for (int i = 0; i < size-1 ; ++i) {
        if (arr[i] > arr[i+1])
        {
            for (int j = i+1; j >= 0 ; --j)
            {
                if (arr[j] < arr[j-1])
                {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }
}







int main()
{
    const int size = 10;
    int arr  [size] {5,6,4,1,2,9,3,8,7,0};
    InsertionSort(arr,size);
    for (int i : arr) {
        std::cout << i << std::endl;
    }
}
