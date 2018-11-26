#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Array{
	private:
		int size;
		T *arr;
		void resize(int newsize){
			T *temp=new T[newsize];
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
			arr=new T[size];
		}
		Array(const T b[],const int size)  {
			this->size=size;
			arr=new T[size];
			for(int i=0;i<size;i++)
				arr[i]=b[i];
		}
		Array(const Array& a){
			arr=new T[a.size];
			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];	
		}
		void clear(){
			resize(0);
		}
		void push_back(const T p){
			resize(size+1);
			arr[size-1]=p;
		}
		void insert(const int pos, const T p){
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
		int getSize() const {
			return this->size;
		}
		~Array(){
			delete[] arr;
		}
		T getarr(int x) const {
			return arr[x];
		}
		
		Array<T>& operator = ( const Array<T>&);
		
		friend Array<T> operator+(const Array<T>&a,const Array<T>&b){
			Array<T> temp=a;
			for(int i=0;i<b.getSize();i++)
				temp.push_back(b.getarr(i));
			return temp;
		}
};

template<class T>
ostream& operator<<(ostream &output,Array<T> &o){
	for(int i=0;i<o.getSize();i++)
		output<<o.getarr(i)<<" ";
	return output;
}

template <class T>
Array<T>& Array<T>::operator = ( const Array<T>& p){
	this->size=p.size;
	T *temp=new T[p.size];
	for(int i=0;i<this->size;i++)
		temp[i]=p.arr[i];
	delete[] this->arr;
	this->arr=temp;
	return *this;
}

int main(){
	int arr[]={1,2,3};
	int arr2[]={4,5,6};
	Array<int> numbers(arr,3);
	Array<int> numbers2(arr2,3);
	Array<int> tempo;
	tempo=numbers+numbers2;
	cout<<numbers<<endl;
	string arr3[]={"uno","dos","tres"};
	Array<string> strings(arr3,3);
	cout<<strings<<endl;
	cout<<tempo;
	ofstream source("archivo.txt");
	source << tempo;
}
