//Working code on Leetcode
// https://leetcode.com/problems/merge-k-sorted-lists/

class Heap {
    public:
    vector<ListNode*> heap;
    
    int left(int i) {return 2*i+1;}
    int right(int i) {return left(i)+1;}
    int parent(int i) {return (i-1)/2;}
    
    void swap(int i, int j) {
        ListNode* temp = heap[j];
        heap[j]=heap[i];
        heap[i]=temp;
    }
    void heapify_up(int i) {
        int p=parent(i);
        
        if(p>=0 && heap[p] && heap[i] && heap[p]->val>heap[i]->val) {
            swap(p, i);
            heapify_up(p);
        }
    }
    void add(ListNode* a) {
        heap.push_back(a);
        heapify_up(heap.size()-1);
    }
    
    Heap() {}
    void heapify(int index) {
        int smallest = index;
        int l=left(index);
        int r=right(index);
        
        if(l<heap.size() && heap[l] && heap[smallest] && heap[l]->val<heap[smallest]->val) {
            smallest=l;
        }
        if(r<heap.size() && heap[r] && heap[smallest] && heap[r]->val<heap[smallest]->val) {
            smallest=r;
        }
        if(smallest!=index) {
            swap(smallest, index);
            heapify(smallest);
        }
    }
    
    ListNode* extractMin() {
        ListNode* result = heap[0];
        swap(0,heap.size()-1);
        if(heap.size())
        heap.erase(--heap.end());
        heapify(0);
        return result;
    }
    
    void display() {
        cout<<"Displaying heap: ";
        for(int i=0;i<heap.size();i++) {
            cout<<heap[i]->val<<" ";
        }
        cout<<"\n";
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        Heap heap=Heap();
        for(int i=0;i<k;i++) {
            if(lists[i])
            heap.add(lists[i]);
        }
        
        ListNode* result=NULL;
        ListNode* cur=NULL;
        while(heap.heap.size()) {
            ListNode* min = heap.extractMin();
            if(min!=NULL && min->next)
            heap.add(min->next);
            if(result==NULL) {
                result = new ListNode(min->val);
                cur=result;
            } else {
                cur->next=new ListNode(min->val);
                cur=cur->next;
            }
        }
        
        return result;
    }
};