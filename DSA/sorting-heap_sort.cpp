#include<bits/stdc++.h>
using namespace std;
int largest;
int len;
void max_heapify(int arr[],int i)
{
	int left = 2*i;
	int right = 2*i+1;
	if(left <= len && arr[left]>arr[i])
		largest = left;
	else 
		largest = i;
	if(right<=len && arr[right]>arr[largest])
		largest = right;
	if(largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,largest);
	}
	return ;
}
void build_maxheap(int arr[])
{
	for(int i = (len/2);i>=1;i--)
		max_heapify(arr,i);
	return ;
}
void heap_sort(int arr[])
{
	build_maxheap(arr);
	for(int i=len;i>=1;i--)
	{
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		len--;
		max_heapify(arr,1);
	}
}
int main()
{
	int arr[] = {0,8,7,6,3,2,4,5};
	//1 based indexing
	len = 7;
	heap_sort(arr);
	for(int i=0;i<8;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
