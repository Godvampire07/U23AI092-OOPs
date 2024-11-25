#include<iostream>
using namespace std;
class cube;
class cuboid{
    private:
    int h,w,b;
    public:
    void getdata(){
        cout<<"Enter the height of cuboid:"<<endl;
        cin>>h;
        cout<<"Enter the breadth of cuboid:"<<endl;
        cin>>b;
        cout<<"Enter the width of cuboid:"<<endl;
        cin>>w;
    }
    void vol(){
        cout<<"The volume of the cuboid is:"<<h*b*w<<endl;
    }
    void smallest(){
        int sm;
        if(h<b){
            sm = h;
        }
        else{
            sm = b;
        }
        if(sm<w){
            sm = sm;
        }
        else{
            sm = w;
        }
       cout<<"The cube formed from the cuboid is:"<<sm*sm*sm<<endl;
        
      }
    friend class cube;
};
class cube{
      public:
      cube(){
        cout<<"Default constructor.";
      }
      cube(cuboid &a){
        a.smallest();
      }
      
};
int main(){
    cuboid x;
    x.getdata();
    x.vol();
    cube y(x);
}