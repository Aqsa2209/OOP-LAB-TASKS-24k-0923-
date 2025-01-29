#include<iostream>
using namespace std;
float findSecondHighest(float *arr, int size){
	float highest=-100.0f;
	float secondHighest=-100.0f;
	for(int i=0; i<size; i++){
		if(arr[i]>highest){
			secondHighest=highest;
			highest=arr[i];
		}else if(arr[i]>secondHighest && arr[i]<highest){
			secondHighest=arr[i];
		}
	}
	return secondHighest;
}
int main(int argc, char *argv[]){
	float arr[20];
	cout<<"Enter 20 float numbers:"<<endl;
	for(int i=0; i<20;i++){
		cin>> arr[i];
	}
	float secondHighest= findSecondHighest(arr, 20);
	if (secondHighest==-100.0f){
		cout<<"There is no second highest number."<<endl;
	}else{
		cout<<"The Second Highest number is: " << secondHighest<<endl;
	}
	return 0;
}
