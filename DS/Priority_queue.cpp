#include<bits/stdc++.h>
using namespace std;
int largest;
int len;
int* swap(int arr[],int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return arr;
}
void max_heapify(int arr[],int i)
{
	int left = 2*i+1;
	int right = 2*i+2;
	if(left < len && arr[left]>arr[i])
		largest = left;
	else 
		largest = i;
	if(right<len && arr[right]>arr[largest])
		largest = right;
	if(largest != i)
	{
		arr = swap(arr,i,largest);
		max_heapify(arr,largest);
	}
	return ;
}
void build_maxheap(int arr[])
{
	for(int i = (len/2)-1;i>=0;i--)
		max_heapify(arr,i);
	return ;
}
int main()
{
	int arr[] = {4,3,7,1,8,5,2};
	len = 7;
	build_maxheap(arr);
	for(int i=0;i<7;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
