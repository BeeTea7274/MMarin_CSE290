#include <iostream>

using namespace std;

int integerArray[6];
int findMax(int arr[]);

int main() {
	int integerArray[6] = {1, 228, 89, 23, 544, 129};
	cout << findMax(integerArray);
}

int findMax(int arr[]) {
	int max;
	max = arr[0];
	for (int i = 0; i < 6; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}