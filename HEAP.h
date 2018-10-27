#include <iostream>
using namespace std;
class heap
{
private:
	int *HEAP;
	int size;
	int len;
	void doublespace()
	{
		int *tmp=HEAP;
		HEAP=new int [size*2+1];
		for (int i=1;i<=len;i++)
			HEAP[i]=tmp[i];
		delete [] tmp;
		size=size*2;
	}
public:
	heap(int k=20):size(k),len(0){HEAP=new int [size+1];}
	void MIN_HEAPIFY(int i)
	{
		int smallest=i;
		int l=i*2;
		int r=i*2+1;
		if (HEAP[l]<HEAP[i])
			{smallest=l;}
		if (HEAP[r]<HEAP[smallest])
			smallest=r;
		if (smallest!=i)
		{
			int tmp=HEAP[smallest];
			HEAP[smallest]=HEAP[i];
			HEAP[i]=tmp;
			MIN_HEAPIFY(smallest);
		}
	}
	void MIN_HEAP_INSEART(int key)
	{
		if (len==size) doublespace();
		len+=1;
		HEAP[len]=key;
		int i=len;
		while (i>1 && HEAP[i/2]>HEAP[i])
		{
			int tmp=HEAP[i];
			HEAP[i/2]=HEAP[i];
			HEAP[i]=tmp;
			i=i/2;
		}
	}
	int MIN_HEAP_EXTRACT()
	{
		int min_1=HEAP[1];
		HEAP[1]=HEAP[len];
		len-=1;
		MIN_HEAPIFY(1);
		return min_1;
	}
	void HEAP_SHOW()
	{
		for (int i=1;i<=len;i++)
			cout<<HEAP[i]<<' ';
	}
	~heap(){delete [] HEAP;}
};

int main(int argc, char const *argv[])
{
	heap a(10);
	for (int i=0;i++;i<10)
		a.MIN_HEAP_INSEART(10-i);
	a.HEAP_SHOW();


	return 0;
}