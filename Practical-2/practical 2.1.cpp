#include<iostream>
using namespace std;

int main(){
string arr[100];
string ar;
int n;

cout<<"Enter total number of licence plate :";
cin>>n;

for(int i=0; i<n; i++){
    cout<<"Enter number plate :"<<i+1<<endl;
    cin>>arr[i];

}

cout<<"Enter target number plate :";
cin>> ar;

for(int i=0;i <n;i++){
    if(ar == arr[i]){
        cout<<"Correct licence plate :"<< i;
    }
}

return 0;
}
