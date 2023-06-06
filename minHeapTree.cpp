#include <iostream>
#include <vector>
#include <string>


template <typename T>
class Heap
{
    private:
    std::vector<T> list{};
    public:
    int getSize()const{return (list.size());}
    void swap(int child,int parent)
    {
        T temp;
        temp=list[child];
        list[child]=list[parent];
        list[parent]=temp;
    }
    int getLeftChild(int parent)const{return ((2*parent)+1);}
    int getRightChild(int parent)const{return ((2*parent)+2);}
    int getParent(int child)const
    {
        if(child%2==0)
        {
            return ((child-2)/2);
        }
        return ((child-1)/2);
    }
    void insert(T value)
    {
        list.push_back(value);
        minHeapify();
    }
    void minHeapify()
    {
       int child=getSize()-1;
       int parent=getParent(child);
       while(list[child]<list[parent] && child>=0 &&parent>=0)
       {
           swap(child,parent);
           child=parent;
           parent=getParent(child);
       }
    }
    void display()
    {
        for(int i=0;i<getSize();i++)
        {
            std::cout<<list[i]<<" ";
        }
        std::cout<<"\n";
    }
    void deleteElement(int number)
    {
        int x=0;
        for(int i=0;i<getSize();i++)
        {
            if(list[i]==number)
            {
               x=i;
               std::cout<<x<<"\n";
               break;
            }
        }
        swap(x,getSize()-1);
        list.pop_back();
        int parent =0;
        
        while(parent<list.size())
        {
            int left=getLeftChild(parent);
            int right=getRightChild(parent);
            if(left<list.size() && list[left]<list[parent])
            {
                swap(left,parent);
                parent=left;
            }
            else if(right<list.size() && list[right]<list[parent])
            {
                swap(right,parent);
                parent=right;
            }
            else
            {
                return ;
            }
        }
        
    }
    void heapify()
    {
        int parent =0;
        while(1)
        {
            int left=getLeftChild(parent);
            int right=getRightChild(parent);
            int length=list.size();
            int largest=parent;
            
            if(left<length && list[left]<list[largest])
            {
                largest=left;
            }
            if(right<length && list[right]<list[largest])
            {
                largest=right;
            }
            if(largest!=parent)
            {
                swap(largest,parent);
                parent = largest;
            }
            else
            {
                break;
            }
        }
        
    }
    T heapSort()
    {
        int child=list.size()-1;
        swap(child,0);
        
        T value=list.back();
        list.pop_back();
        
        heapify();
        return value;
    }
    void extractMin()
    {
        std::cout<<"The minimum element in min Heap Tree is : "<<list.front()<<"\n";
    }
};

int main()
{
    Heap<int> h;
    h.insert(1);
    h.insert(6);
    h.insert(8);
    h.insert(2);
    h.insert(3);
    h.insert(5);
    h.display();
    h.deleteElement(1);
    h.display();
    h.extractMin();
    while(h.getSize()>0)
    {
        std::cout<<"\nheap min : "<<h.heapSort()<<"\t";
    }
    return 0;
}
