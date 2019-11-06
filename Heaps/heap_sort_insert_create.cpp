//working code

//heap is a complete binary tree, which can be stored in an array. Heaps are used mainly for priority queue, so some must to
//implementations are getting the max/min from the heap, inserting.

//Remember that complete binary tree is a balanced tree, so height is always log n
//Sorting can also be done, nLogn, but there are other ways to do sorting in the same time.

//1. Go to the main code to undersatnd the implementation
#include <bits/stdc++.h>
using namespace std;

//0 based heap
int left(int i) {return 2*i+1;}
int right(int i) {return 2*i+2;}
int parent(int i) {return (i-1)/2;}

void swap(vector<int> &ar, int i, int j) {
	int temp= ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
}

//building max heap
//this goes down
//Time Complexity: Log n
void heapify(vector<int> &heap, int i, int size) {
	int largest=i;
	int l=left(i);
	int r=right(i);
	
	// int size=heap.size();
	if(l<size && heap[largest]<heap[l]) {
		largest=l;
	}
	if(r<size && heap[largest]<heap[r]) {
		largest=r;
	}
	if(largest!=i) {
		swap(heap, largest, i);
		heapify(heap, largest,size);
	}
}

//Time  : nLogn
//Space : n
void heapSort_recursive(vector<int>&heap, int size) {
	if(size==0) return;
	swap(heap, 0, size-1);
	heapify(heap, 0, size-1);
	heapSort_recursive(heap, size-1);
}

//Time  : nLogn
//Space : 1
void heapSort(vector<int>&heap, int size) {
	while(size) {
		swap(heap, 0, size-1);
		heapify(heap, 0, size-1);
		size--;
	}
}


// this algorithm swaps the root with the last element, so at last you have the maximum, but, there is one element misplaced,
// on root, so it is heapified from 0 index.
// Time: Log n
int extractMax(vector<int> &heap) {
	int result = heap[0];
	
	swap(heap, 0, heap.size()-1);
	heap.erase(--heap.end());
	heapify(heap, 0, heap.size());
	return result;
}

int getMax(vector<int> heap) {return heap[0];}

// if you add some element at the end of the heap array, at this point every other part of the heap is following the property but last element 
// might not, so heapify up from the last elememt
// Time: Log n
void bottom_up_heapify(vector<int> &heap, int i) {
	int p = parent(i);
	if(p>=0 && heap[p]<heap[i]) {
		swap(heap, p, i);
		bottom_up_heapify(heap, p);
	}
}

void insert(vector<int> &heap, int val) {
	heap.push_back(val);
	bottom_up_heapify(heap, heap.size()-1);
}

int main() {
	// 2. These two lines are taking a static array, and this array is heapuified using 'go down' approach 
	// from the node selected using for loop.
	// Array is heapified from the internal nodes. Starting from the last internal node to the root.
	// this type of organizinng takes a tree with 0, 2 child nodes at a time, organises them according to min/max heap
	// then moves up for doing the same for above node. 

	//2 & 3: Time: nLogn, Space: n 
	vector<int> ar = {8,7,9,1,4,3};
	for(int i=ar.size()/2;i>=0;i--) heapify(ar,i,ar.size());
	
	// 3. This method takes the heap elements dynamically, and uses bottom up approach to insert and heapify_up
	vector<int> ar1;
	insert(ar1,8);insert(ar1,7);insert(ar1,9);insert(ar1,1);insert(ar1,4);insert(ar1,3);
	cout<<extractMax(ar1);cout<<extractMax(ar1);
	cout<<getMax(heap);
	
	// 4. heapsort takes the root to the last element and the resulting heap's size is decreased to call heapify again on the
	// remaining heap from the array, it is only applied on the new root element, because that's only one displaced
	heapSort(ar, ar.size());
	for(int i=0;i<ar.size();i++) cout<<ar[i]<<" ";
	return 0;
}