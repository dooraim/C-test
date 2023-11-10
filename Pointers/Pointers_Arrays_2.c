// C Program to access array elements using pointers
#include <stdio.h>

int main()
{

	// defining array
	int arr[5] = { 1, 2, 3, 4, 5 };

	// defining the pointer to array
	int* ptr_arr = &arr[0];

	// traversing array using pointer arithmetic
	for (int i = 0; i < 5; i++) {
		printf("%d ", *ptr_arr++);
	}
	return 0;
}
