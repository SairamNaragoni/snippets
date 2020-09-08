#include<stdio.h>

void bubblesort(int a[],int s)
{
	int i,j,flag=0,temp;
	for(i=0;i<s;i++)
	{
		flag=0;
		for(j=1;j<s-i;j++)
		{
		
			if(a[j-1]>a[j])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}

void selectionsort(int a[],int s)
{
	int i,j,min,temp;
	for(i=1;i<s;i++)
	{
		min=i-1;
		for(j=i;j<s;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		temp=a[i-1];
		a[i-1]=a[min];
		a[min]=temp;
	}
}

void insertionsort(int a[],int s)
{
	int i,hole,temp;
	for(i=1;i<s;i++)
	{
		temp=a[i];
		hole=i;
		while(hole>0 && a[hole-1]>temp)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=temp;
	}
}
int partition(int a[],int start,int end)
{
	int pivot,pindex,i,temp;
	pivot=a[end];
	pindex=start;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[pindex];
	a[pindex]=a[end];
	a[end]=temp;
	return pindex;
}
void quicksort(int a[],int start,int end)
{
	if(start<end)
	{
		int pindex;
		pindex=partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}
void merge(int a[],int left[],int right[],int l,int r)
{
	int i=0,j=0,k=0;
	while(i<l && j<r)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<l)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<r)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int s)
{
	if(s<2)
	return;
	int mid,i,l,r;
	mid=s/2;
	l=mid;
	r=s-mid;
	int left[l],right[r];
	for(i=0;i<mid;i++)
		left[i]=a[i];
	for(i=mid;i<s;i++)
		right[i-mid]=a[i];
	mergesort(left,l);
	mergesort(right,r);
	merge(a,left,right,l,r);
}

void display(int a[],int s)
{
	
	int i;
	for(i=0;i<s;i++)
	printf("%d ",a[i]);
	printf("\n");
	return;
}

int input(int a[])
{
	int size,i;
	printf("Enter the size of the array\n");
 	scanf("%d",&size);
 	printf("Enter the Array\n");
	for(i=0;i<size;i++)
 	scanf("%d",&a[i]);
	return size;	
}
 void main()
 {
 	int choice,size,a[100];
 	while(1)
 	{
 		printf(".......MENU.......\n");
 		printf("enter Your choice\n");
 		printf("1.Bubble Sort\n2.Selection Sort\n3.Insertion sort\n4.Quick Sort\n5.Merge Sort\n6.EXIT\n\n");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1: size=input(a);
			 		bubblesort(a,size);
 					display(a,size);
			 		break;
			case 2: size=input(a);
					selectionsort(a,size);
					display(a,size);
			 		break;
			case 3: size=input(a);
					insertionsort(a,size);
					display(a,size);
			 		break;
			case 4: size=input(a);
					quicksort(a,0,(size-1));
					display(a,size);
			 		break;
			case 5: size=input(a);
					mergesort(a,size);
					display(a,size);
			 		break;
			case 6: return;
			default:printf("Invalid Input.Try Again\n");	
		}
	}
 }
