#include <iostream>
using namespace std;
int findmax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) 
	{
      if (arr[i] > max)
	   {
       max = arr[i]; 
       }
    }
    return max; 
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, -1, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);
int maxvalue = findmax(arr, n); // Call the function to find the maximum
cout << "The maximum value in the array is="<<maxvalue<<endl; 
}
