#include <stdio.h>
void merge(int a[], int left, int mid, int right) {
int temp[100];
int i = left; // start of first half
int j = mid + 1; // start of second half
int k = left; // start of temp array
// Compare and copy smaller element into temp
while (i <= mid && j <= right) {
if (a[i] < a[j])
temp[k++] = a[i++];
else
temp[k++] = a[j++];
}
// Copy remaining elements (if any) from first half
while (i <= mid)
temp[k++] = a[i++];
// Copy remaining elements (if any) from second half
while (j <= right)
temp[k++] = a[j++];
// Copy back to original array
for (i = left; i <= right; i++)
a[i] = temp[i];
}
void mergeSort(int a[], int left, int right) {
if (left < right) {
int mid = (left + right) / 2;
// Divide the array into two halves
mergeSort(a, left, mid);
mergeSort(a, mid + 1, right);
// Merge the two sorted halves
merge(a, left, mid, right);
}
}
int main() {
int a[100], n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d elements:\n", n);
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
// Call merge sort
mergeSort(a, 0, n - 1);
printf("Sorted array:\n");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
