#include<vector>
#include<iostream>

auto heapify(std::vector<int>& arr, int size, int curmax)->void{
    auto lar=curmax;
    auto left=lar*2+1;
    auto right=lar*2+2;
    if(left<size and arr[left]>arr[lar]){
        lar=left;
    }
    if(right<size and arr[right]>arr[lar]){
        lar=right;
    }
    if(lar!=curmax){
        std::swap(arr[lar],arr[curmax]);
        heapify(arr,size,lar);
    }
}
auto heapsort(std::vector<int>& arr)->void{
    auto size=arr.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(arr, size, i);
    }
    for(int i=size-1;i>0;i--){
        std::swap(arr[0],arr[i]);
        heapify(arr, i, 0);
    }
}


int main(){
    auto res=std::vector<int>{11,7,6,23,5,8};
    std::cout<<std::endl<<"排序前：";
    for(int i=0;i<res.size();i++){
        std::cout<<res.at(i)<<" ";
    }
    heapsort(res);
    std::cout<<std::endl<<"排序后：";
    for(int i=0;i<res.size();i++){
        std::cout<<res.at(i)<<" ";
    }
    return 0;
}