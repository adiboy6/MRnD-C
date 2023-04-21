/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :In the brute force method, we checked every element sum with remaining elements. This increased the time complexity to O(n*n). Therefore this isn't the most efficient way to solve the problem.

Way 2 : In this method, I used the merge sort to sort the unsorted array and then using a method similar to binary search, I used it to add two numbers and check whether they are greater or lesser. If both are equal, then return the array containing the the 2 numbers. What I observed in this method was that when I created a pointer and allocated memory for it dynamically to sort, the complexity increased. But when I used used a static array such as temp[1000], it did reduce the time complexity a little. The overall time complexity is O(nlogn).

Way 3:This was the most efficient way because I used the method of hashing to allocate numbers present in the given array. Therefore, the complexity got reduced to O(n).

Conclusion : The third method was the most efficient method as it decreased the number of times of execution.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? ___O(n*n)___
*/
int* sumoftwoBF(int *nums, int target, int len)
{

	int *arr;
	int i, j;
	if (nums == NULL || len <= 0)
	{
		return NULL;
	}
	arr = (int *)malloc(sizeof(int) * 2);
	for (i = 0; i<len; i++)
	{
		for (j = i + 1; j<len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				if (nums[i] < nums[j])
				{
					arr[0] = nums[i];
					arr[1] = nums[j];
					break;
				}
				if (nums[i] > nums[j])
				{
					arr[0] = nums[j];
					arr[1] = nums[i];
					break;
				}
			}
		}
	}
	return arr;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? ____O(nlogn)____
*/
void merge(int*, int, int, int);
void mergeSort(int* , int , int );
void merge(int *arr, int left, int mid, int right)
{
	int i, mi, k, lo, temp[1000];
	lo = left;
	i = left;
	mi = mid + 1;
	while ((lo <= mid) && (mi <= right))
	{
		if (arr[lo] <= arr[mi])
		{
			temp[i] = arr[lo];
			lo++;
		}
		else
		{
			temp[i] = arr[mi];
			mi++;
		}
		i++;
	}
	if (lo > mid)
	{
		for (k = mi; k <= right; k++)
		{
			temp[i] = arr[k];
			i++;
		}
	}
	else
	{
		for (k = lo; k <= mid; k++)
		{
			temp[i] = arr[k];
			i++;
		}
	}
	for (k = left; k <= right; k++)
	{
		arr[k] = temp[k];
	}
}

void mergeSort(int *arr, int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}
int* sumoftwoSortAndSearch(int *nums, int target, int len)
{
	if (nums == NULL || len <= 0)
	{
		return NULL;
	}
	mergeSort(nums, 0, len - 1);
	int low = 0, high = len - 1;
	int *a;
	a = (int *)malloc(sizeof(int) * 2);
	while (low <= high)
	{
		if (nums[low] + nums[high] == target)
		{
			if (nums[low] < nums[high])
			{
				a[0] = nums[low];
				a[1] = nums[high];
				break;
			}
			if (nums[low] > nums[high])
			{
				a[0] = nums[high];
				a[1] = nums[low];
				break;
			}
		}
		if (nums[low] + nums[high] < target)
		{
			low = low + 1;
		}
		if (nums[low] + nums[high] > target)
		{
			high = high - 1;
		}
	}
	return a;
}

/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/

int* sumoftwoExtraArray(int *nums, int target, int len)
{
	if (nums == NULL || len <= 0)
	{
		return NULL;
	}
	int *a;
	a = (int *)malloc(sizeof(int) * 2);
	int hash[1000] = { 0 };
	int i, temp;
	for (i = 0; i < len; i++)
	{
		temp = target - nums[i];
		if (hash[temp] == 1 && temp >= 0)
		{
			if (temp > nums[i])
			{
				a[0] = nums[i];
				a[1] = temp;
				break;
			}
			if (temp < nums[i])
			{
				a[0] = temp;
				a[1] = nums[i];
				break;
			}
		}
		hash[nums[i]]=1;
	}
	return a;
}
