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
	heap(int k=10):size(k),len(0){HEAP=new int [size+1];}
	int LEN()
	{return len;}
	void MIN_HEAPIFY(int i)
	{

		while (true)
		{
			int smallest=i;
			int l=i*2;
			int r=i*2+1;
			if (l<=len && HEAP[l]<HEAP[i])
				{smallest=l;}
			if (r<=len && HEAP[r]<HEAP[smallest])
				smallest=r;
			if (smallest!=i)
			{
				int tmp=HEAP[smallest];
				HEAP[smallest]=HEAP[i];
				HEAP[i]=tmp;
				i=smallest;
			}
			else break;
			
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
			int tmp=HEAP[i/2];
			HEAP[i/2]=HEAP[i];
			HEAP[i]=tmp;
			i=i/2;
		}
	}
	int MIN_HEAP_EXTRACT()
	{
		if (len==0)
			return -1;
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

int M,N;
int main(int argc, char const *argv[])
{
	cin>>N>>M;
	heap **a=new heap* [N];
	int value;
	for (int i=0;i<N;i++)
	{
		cin>>value;
		a[i]=new heap ();
		a[i]->MIN_HEAP_INSEART(value);
	}
	int op,group1,group2;
	for (int i=0;i<M;i++)
	{
		scanf("%d",&op);
		if (op==0)
		{
			scanf("%d%d",&group1,&group2);
			int tmp,k=a[group2]->LEN();
			for (int i=0;i<k;i++)
			{
				tmp=a[group2]->MIN_HEAP_EXTRACT();
				a[group1]->MIN_HEAP_INSEART(tmp);
			}
		}
		else if (op==1)
		{
			scanf("%d",&group1);
			printf("%d\n",a[group1]->MIN_HEAP_EXTRACT());
		}
		else
		{
			int tmp;
			scanf("%d%d",&group1,&tmp);
			a[group1]->MIN_HEAP_INSEART(tmp);
		}
	}	
	
	return 0;
}