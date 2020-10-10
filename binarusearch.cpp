#include <bits/stdc++.h> 
using namespace std; 
 
int binaryS(int arr[], int l, int r, int x) 
{ 
    if (r >= l)
    { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binaryS(arr, l, mid - 1, x); 
        return binaryS(arr, mid + 1, r, x); 
    }  
    return -1; 
} 
  
int main() 
{ 
    int arr[];
    int si;
    cout<<"Enter size of array";
    cin>>si;
    cout<<"enter value"
     for(int i=0;i<si;i++){
      cin>>arr[i];
     }
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binaryS(arr, 0, n - 1, x); 
    if(result == -1)
        cout << "not present in array"
    else
        cout << "present at index " << result; 
    return 0; 
} 
