#include <iostream>
using namespace std;

template <typename P>
class Point{
	public:
		P x,y;
		Point(){
		}
		Point(P x,P y){
			this->x=x;
			this->y=y;
		}
		void setX(P a){
			x=a;
		}
		void setY(P b){
			y=b;
		}
		
};



template<class T>
class Array{
	private:
		int size;
		Point<T> *arr;
		void resize(int newsize){
			Point<T> *temp=new Point<T>[newsize];
			int minsize = (newsize>size)?size:newsize;
			for(int i=0;i<minsize;i++)
				temp[i]=arr[i];
			delete[] arr;
			arr=temp;
			size=newsize; 
		}
	public:
		Array(){
			size=0;
			arr=new Point<T>[size];
		}
		Array(Point<T> b[],int size){
			this->size=size;
			arr=new Point<T>[size];
			for(int i=0;i<size;i++)
				arr[i]=b[i];
		}
		Array(Array& a){
			arr=new Point<T>[a.size];
			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];	
		}
		void clear(){
			resize(0);
		}
		void push_back(const Point<T> &p){
			resize(size+1);
			arr[size-1]=p;
		}
		void insert(const int pos, const Point<T> &p){
			resize(size+1);
			for(int i=size-2;i>pos;i--)
				arr[i]=arr[i-1];
			arr[pos]=p;
		}
		void remove(const int pos){
			for(int i=pos;i<size-1;i++)
				arr[i]=arr[i+1];
			resize(size-1);
		}
		int getSize(){
			return size;
		}
		void print(){
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}

		~Array(){
			delete[] arr;
		}
};

template<class T>
ostream& operator<<(ostream &output,const Point<T> &o){
	output<<"("<<o.x<<","<<o.y<<")";
	return output;
}

template<class T>
Point<T> operator+(const Point<T>& b,const Point<T>& c){
	Point<T> temp;
	temp.setX(b.x+c.x);
	temp.setY(b.y+c.y);
	return temp;
}


int main(){
	Point<int> num(1,3);
	Point<int> num2(2,4);
	Point<string> p1("1","2");
	Point<string> p2("probando","probando");
	Point<string> p3[]={p1,p2};
	Point<string> add("anadido","+");
	
	Array<string> array(p3,2);
	array.print();
	cout<<endl;
	array.push_back(add);
	array.print();
	array.remove(1);
	cout<<endl;
	array.print();
	cout<<endl;
	cout<<p1+p2<<endl;
	cout<<num+num2<<endl;
}
