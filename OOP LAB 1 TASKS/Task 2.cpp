#include<iostream>
using namespace std;
float calculateSum(float* arr, int size){
	float sum=0.0;
	for(int i=0; i<size; i++){
		sum+= *(arr+i);
	}
	return sum;
}
int main(int argc, char* argv[]){
	const int SIZE =20;
	float arr[SIZE];
	cout<< "Enter "<< SIZE << " float numbers:" <<endl;
	for(int i=0; i<SIZE; i++){
		cin >> arr[i];
	}
	float sum= calculateSum(arr, SIZE);
	cout<<"The sum of the elements in the array is: " <<sum <<endl;
	return 0;
}
