#include<iostream>
using namespace std;
class punto{
    public:
        double x;double y;
        punto(double a=0,double b=0){
            x=a;
            y=b;
        }
        void mostrar(){
            cout<<"("<<x<<","<<y<<")"<<" ";
        }
};
void swa(punto &c,punto &d){
    punto a= c;
    c= d;
    d=a;
}
void ord(punto *a){
    for(int i=0;i<5;i++){
        for(int j=1+i;j<5;j++){
            if(a[i].x>a[j].x){
                swa(a[i],a[j]);
            }
        }
    }
}
int main(){
    punto arr[5];
    for(int i=0;i<5;i++){
        cout<<"(x,y)";
        cin>>arr[i].x;
        cin>>arr[i].y;
    }
    ord(arr);
    for(int i=0;i<5;i++){
        arr[i].mostrar();
    }
    return 0;
}
