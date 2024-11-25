#include<iostream>
using namespace std;
class arr{
    int size;
    public:
    void getsize(){
        cout<<"Give the size for the array:";
        cin>>size;
    }
    void process(){
        int  *n;
        n = new int[size];
        for (int i = 0 ; i < size ; i++){
            cout<<"Enter value:";
            cin>>n[i];
        }
        cout<<"The values of array are:"<<endl;
        for (int i = 0 ; i< size ; i++){
            cout<<n[i]<<"\t";
        }
    }
    
};
int main(){
    arr a;
    a.getsize();
    a.process();
}