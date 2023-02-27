#include <stdio.h>

int binary_search(int x, int arr[], int n);

int main() {
  int arr[] = {2, 3, 5, 8, 10, 12, 15, 26};

  printf("3 is at position %d", binary_search(3, arr, 8));

  return 0;
}

int binary_search(int x, int arr[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high && x != arr[mid]) {
    if (x < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }

  if (x == arr[mid])
    return mid;

  return -1;
}
