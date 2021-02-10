#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include <chrono>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;
void genList(int arrSize);
void sort(int arr[], int size);
void print(int arr[], int size);
bool check_order(int arr[], int size);

int main(void){

	char userChoice;
	int userNum;

	while(true){
		cout << "Welcome! This is a gnome sort alogorithm visualizer." << endl;
		cout << "This program simulates a gnome sort on an array." << endl;
		cout << "Generate bars? (y/n): ";
		cin >> userChoice;
		if(userChoice == 'Y' or userChoice == 'y'){
			cout << endl << "Please enter a size between 1-50: ";
			cin >> userNum;
			if(userNum >= 1 and userNum <= 50)
				genList(userNum);
			else{
				cout << "Invalid Number...Exiting Progam..." << endl;
				return 0;
			}
		}
		else if(userChoice == 'N' or userChoice == 'n'){
			cout << "Exiting Program..." << endl;
			return 0;
		}
		else
			cout << "That is an invalid choice, select again..." << endl;
	}
}

void genList(int arrSize){
	int *arrPtr = NULL;
	int ranNum = 0;
	char userChar;

	srand(time(NULL));
	arrPtr = new int[arrSize];
	for(int index = 0; index < arrSize; ++index){
		ranNum = rand() % 100 + 1;
		arrPtr[index] = ranNum;
	}
/*	for(int index = 0; index < arrSize; ++index){
		cout << arrPtr[index];
	}
*/
	cout << "Sort the array? (y/n): ";
	cin >> userChar;
	if(userChar == 'Y' or userChar == 'y')
		sort(arrPtr, arrSize);
	else if(userChar == 'N' or userChar == 'n'){
		cout << "Exiting Program..." << endl;
		exit(EXIT_FAILURE);
	}
	else{
		cout << "Invalid choice, exiting program..." << endl;
		exit(EXIT_FAILURE);
	}
	delete [] arrPtr;
}

void sort(int arr[], int size){
	int pos = 1;
	while(pos < size){
		if(pos == 0 or arr[pos] >= arr[pos-1])
			++pos;
		else{
			std::swap(arr[pos], arr[pos-1]);
			--pos;
		}
		usleep(10000);
		system("clear");	
		print(arr, size);
		cout << "Sorting...." << endl;
		if(check_order(arr, size)){
			cout << "The array has been sorted..." << endl << endl << endl;
			break;
		}
	}
}
void print(int arr[], int size){
	int hash = 0;
	for(int index = 0; index < size; ++index){
		for(hash = 0; hash < arr[index]; ++hash){
			cout << "#";
		}
		hash = 0;
		cout << endl;	
	}

	
}
bool check_order(int arr[], int size){
	for(int index = 0; index < (size-1); ++index){
		if(arr[index] > arr[index+1]){
			return false;
		}
	}
	return true;
}






