#include<iostream>
using namespace std;

int main()
{
    int arr[30];
    int n;
    int h;
    int i,j,first;

    cout<<"Enter the number of bakery item";
    cin>>n;

    for(i=0;i<n;i++){
    cout<<"Enter the bakery item "<<i+1<<endl;
    cin>>arr[i];
}

cout<<"Enter the number of hours"<<endl;
cin>>h;

h=h%n;

for (j=0;j<h;j++)
{
    first=arr[0];

    for(i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];

    }
    arr[n-1]=first;
}


for(i=0;i<n;i++){
    cout<<"bakery item "<<i+1<<" is "<<arr[i]<<endl;

}
}
