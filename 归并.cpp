//#include<stdio.h>
//#include<windows.h>
//#include<string.h>
//#include<stdlib.h>
//
//void merge(int arr[],int left,int mid ,int right){
//	int temp[64]={0};
//	int i= left;//指向左边数组的第一个元素
//	int j = mid;//指向右边数组的第一个元素
//	int k = 0;
//	
//	//当两者数组都有元素的时候
//	while(i<mid&&j<=right){
//		if(arr[i]<arr[j]){
//		temp[k++]=arr[i++];
//
//		}else {
//			temp[k++] = arr[j++];
//			}
//	}
//
//	while(i<mid){
//	temp[k++]=arr[i++];
//	}
//
//	while(j<=right){
//	temp[k++] = arr[j++];
//	}
//
//	/*for(int i=0;i<=right;i++){
//		printf("%d\t",temp[i]);
//		
//	}
//	printf("\n");*/
//
//	memcpy(arr+left,temp+left,(right-left+1)*sizeof(int));
//
//
//}
//
//int main(void){
//	int beauties[]={10, 11, 12, 13, 2, 4, 5, 8};
//
//	int len=sizeof(beauties)/sizeof(beauties[0]);
//
//	
//	int mid = len/2;
//
//	merge(beauties,0,mid,len-1);
//
//	for(int i=0;i<len;i++){
//		printf("%d\t",beauties[i]);
//
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<iostream>

using namespace std;

void merge(int arr[],int left,int mid,int right,int *temp){

	

	int i = left;
	int j=  mid;
	int k = left;


	while(i<mid&&j<=right){
		
	if(arr[i]<arr[j]){

	temp[k++]=arr[i++];

	}else{
		temp[k++]=arr[j++];
	}
		}

	while(i<mid){

		temp[k++] = arr[i++];
	}
	
	while(j<=right){

		temp[k++] = arr[j++];
	}


	
	memcpy(arr+left,temp+left,(right-left+1)*sizeof(int));
}

void adsort(int *value,int left,int right,int *temp){
	int mid = 0;
	if(left<right){

		 mid = left +(right-left)/2;
		adsort(value,left,mid,temp);
		adsort(value,mid+1,right,temp);
		merge(value,left,mid+1,right,temp);
	}

}

int main(void){
	//int value[]={10, 11, 12, 13, 2, 4, 5, 8};

	int value[]={0,52,14,17,233,12,7,44};
	int len =sizeof(value)/sizeof(value[0]);
	
	int* temp =new int [len];

	int mid = len/2;

	//merge(value,0,mid,len-1,temp);

	adsort(value,0,len-1,temp);

	for(int i=0;i<len;i++){
		cout<<value[i]<<"\t";
		
	}

	cout<<endl;



	system("pause");
	return 0;
}