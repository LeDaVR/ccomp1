#include <iostream>

using namespace std;

int main() {
int p,q,r;
cout << "ingrese p" ; cin >>p;
cout << "ingrese q" ; cin >>q;
cout << "ingrese r" ; cin >>r;
if (p>=q){
if (p>=r){
cout << "el mayor es:" << p << endl;
}else{
cout << "el mayor es:" << r << endl;
}
}else if(q>=r){
cout << "el mayor es:" << q << endl;
}else{
cout << "el mayor es:" << r << endl;
}
if (p<=q){
if (p<=r){
cout << "el menor es:" << p << endl;
}else{
cout << "el menor es:" << r << endl;
}
}else if(q<=r){
cout << "el menor es:" << q << endl;
}else{
cout << "el menor es:" << r << endl;
}
	return 0;
}

//ejercicios cap 2
