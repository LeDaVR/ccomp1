#include <iostream>
using namespace std;
class Polygon{
	protected:
		int x,y;
	public:
		Polygon(int x=0,int y=0){
			this->x=x;
			this->y=y;
		}
		virtual int area(){
			return x*y;
		}
		void printarea(){
			cout<<area();
		}
};

class Rectangle : public Polygon{
	public:
		Rectangle(int x,int y) : Polygon(x,y){}
		
};

class Triangle : public Polygon{
	public:
		Triangle(int x,int y) : Polygon(x,y){}
		int area(){
			return x*y/2;
		}
};

class PolygonArray{
	private:
		int size;
		Polygon *arr;
		void resize(int newsize){
			Polygon *temp=new Polygon[newsize];
			int minsize = (newsize>size)?size:newsize;
			for(int i=0;i<minsize;i++)
				temp[i]=arr[i];
			delete[] arr;
			arr=temp;
			size=newsize; 
		}
	public:
		PolygonArray(){
			size=0;
			arr=new Polygon[size];
		}
		PolygonArray(Polygon b[],int size){
			this->size=size;
			arr=new Polygon[size];
			for(int i=0;i<size;i++)
				arr[i]=b[i];
		}
		PolygonArray(PolygonArray& a){
			arr=new Polygon[a.size];
			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];	
		}
		void clear(){
			resize(0);
		}
		void push_back(const Polygon &p){
			resize(size+1);
			arr[size-1]=p;
		}
		void insert(const int pos, const Polygon &p){
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

		~PolygonArray(){
			delete[] arr;
		}
};

int main(){
	Triangle triangulo(2,3);
	triangulo.printarea();
	cout<<endl;
	Rectangle rectangulo(4,5);
	rectangulo.printarea();
	cout<<endl;
	Polygon arr[]={triangulo,rectangulo};
	PolygonArray prueba(arr,2);
}
