/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:
Compared to the traditional of Linear Search, I did a little modifications to the code and after comparing with both the traditional method and the current method, I found that this one reduced the time a bit. Though the time complexity is O(n), it does reduces the execution time.

Binary Search :
Binary search mainly works only with sorted array else, it may show a different output. This is the only drawback which I found in this search method with a time complexity of O(logn).

Conclusion :
Binary search proves to be more efficient as it takes comparatively less time when compared with Linear search. But the drawback with BinarySearch is that it only works for sorted array.. We can reduce this by using quick/merge sort if required.
*/

int linearSearch(int *arr, int len, int key) 
{
	int i;
	for (i = 0; i < len && arr[i] != key; i++);
	if (i < len)
	{
		return i;
	}
	return -1;
}

int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	int low = 0, high = len - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			low = mid + 1;

		else
			high = mid - 1;
	}
	return -1;
}