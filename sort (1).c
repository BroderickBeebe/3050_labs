#include <cs3050.h>
void heapify(void *array,
				int i,
				size_t nitems,
				size_t size,
				int (*CompareFunc)(const void *, const void *))
{
	int temp= i;
	void *largest = array + size*i;
	void *left = array + size*(i*2);
	void *right = array + size*(i*2+1);
	if(i*2<=nitems-1 && CompareFunc(largest,left)<0)
	{
		largest = left;
		temp = i*2;
	}
	if(i*2+1<=nitems-1 && CompareFunc(largest,right)<0)
	{
		largest = right;
		temp = i*2+1;
	}
	if(temp!=i)
	{
		Swap(largest,array+i*size,size);
		i=temp;
		heapify(array,i,nitems,size,*CompareFunc);
	}


}
void createHeap(void * array,
					size_t nitems,
					size_t size,
					int (*CompareFunc)(const void *, const void *))
{
	for(int i = nitems/2-1; i>=0; i--)
	{
		heapify(array,i,nitems,size,*CompareFunc);
	}

}
void heapsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	createHeap(array,nitems,size,*CompareFunc);
	for(int i = nitems-1;i>=1;--i)
	{
		Swap(array,array+i*size,size);
		nitems--;
		heapify(array,0,nitems,size,*CompareFunc);
	}
}
