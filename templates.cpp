#include <iostream>
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
		Array(T b[],int size){
			this->size=size;
			arr=new T[size];
			for(int i=0;i<size;i++)
				arr[i]=b[i];
		}
		Array(Array& a){
			arr=new T[a.size];
			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];	
		}
		void clear(){
			resize(0);
		}
		void push_back(T p){
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
		int getSize(){
			return this->size;
		}
		~Array(){
			delete[] arr;
		}
		T getarr(int x){
			return arr[x];
		}
};

template<class T>
ostream& operator<<(ostream &output,Array<T> &o){
	for(int i=0;i<o.getSize();i++)
		output<<o.getarr(i)<<" ";
	return output;
}

Array<int> operator+(Array<int>& b,Array<int>& c){
	Array<int> temp;
	int minsize=(b.getSize()>c.getSize()) ? c.getSize() : b.getSize();
	for(int i=0;i<minsize;i++)
		temp.push_back(b.getarr(i)+c.getarr(i));
	return temp;
}
template<class T>
Array<T> suma(Array<T> b,Array<T> c){
	Array<T> temp;
	int minsize=(b.getSize()>c.getSize()) ? c.getSize() : b.getSize();
	for(int i=0;i<minsize;i++)
		temp.push_back(b.getarr(i)+c.getarr(i));
	return temp;
}
int main(){
	int arr[]={1,2,3};
	int arr2[]={4,5,6};
	Array<int> numbers(arr,3);
	Array<int> numbers2(arr2,3);
	Array<int> temp;
	/*int minsize=(numbers.getSize()>numbers2.getSize()) ? numbers2.getSize() : numbers.getSize();
	for(int i=0;i<minsize;i++)
		temp.push_back(numbers.getarr(i)+numbers2.getarr(i));*/
	cout<<numbers<<endl;
	string arr3[]={"uno","dos","tres"};
	Array<string> strings(arr3,3);
	cout<<strings;
}
