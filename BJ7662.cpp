#include <iostream>
#include <queue>
#include <functional>
/*
자체구현 ㅈ망할거...
*/
int N;

class Max_heap{
public:

    std::pair<int,int>arr[1000000];
    int size = 0;

    Max_heap(){}

    void add(int num,int count){
        size++;

        int i = size;
        
        while( (i != 1) && (num > arr[i/2].first)){
            arr[i] = arr[i/2];
            i = i/2;
        }

        arr[i].first = num;
        arr[i].second = count;

    }

    int del(bool * val){
        int par , child;

        int result = arr[1].first;
        val[arr[1].second] = 0;
        int tmp = arr[size].first;
        bool ptr = arr[size].second;

        par = 1;
        child = 2;

        while(child <= size){
            if((child < size-1) && (arr[child].first < arr[child+1].first)){
                child++;
            }

            if(tmp >= arr[child].first){
                break;
            }

            arr[par] = arr[child];

            par = child;
            child *=2;
        }

        arr[par].first = tmp;
        arr[par].second = ptr;

        return result;
    }


};

class Min_heap{
public:

    std::pair<int,int>arr[1000000];
    int size = 0;

    Min_heap(){}

    void add(int num,int count){
        size++;

        int i = size;
        
        while( (i != 1) && (num < arr[i/2].first)){
            arr[i] = arr[i/2];
            i = i/2;
        }

        arr[i].first = num;
        arr[i].second = count;

    }

    int del(bool * val){
        int par , child;

        int result = arr[1].first;
        val[arr[1].second] = 0;
        int tmp = arr[size].first;
        bool ptr = arr[size].second;

        par = 1;
        child = 2;

        while(child <= size){
            if((child < size-1) && (arr[child].first > arr[child+1].first)){
                child++;
            }

            if(tmp <= arr[child].first){
                break;
            }

            arr[par] = arr[child];

            par = child;
            child *=2;
        }

        arr[par].first = tmp;
        arr[par].second = ptr;

        return result;
    }


};

void sync_max(bool * val,Max_heap * max){
    while(max->size != 0 && !val[max->arr[1].second]){
        max->del(val);
    }
    return;
}

void sync_min(bool * val,Min_heap * min){
    while(min->size != 0 && !val[min->arr[1].second]){
        min->del(val);
    }
    return;
}

int main(){
    int T,N;
    std::cin >> T;

    for(int i=0;i<T;i++){
        std::cin >> N;

        Max_heap* max_heap = new Max_heap();
        Min_heap* min_heap = new Min_heap();
        bool val[N];
        int size=0;

        for(int i=0;i<N;i++){
            char com;
            int data;

            std::cin >> com >> data;

            if(com == 'I'){
                max_heap->add(data,i);
                min_heap->add(data,i);
                val[i] == 1;
                size++;               
            }else if(com == 'D'){

                if(size == 0){
                    continue;
                }

                if(data == 1){

                    sync_max(val,max_heap);
                    max_heap->del(val);
                    size--;

                }else if(data == -1){
                    
                    sync_min(val,min_heap);
                    min_heap->del(val);
                    size--;

                }

            }

        }

        sync_max(val,max_heap);
        sync_min(val,min_heap);

        if(size == 0){
            std::cout << "EMPTY" << std::endl;
        }else{
            int tmp = max_heap->del(val);
            std::cout << tmp << " ";
            tmp = min_heap->del(val);
            std:: cout << tmp << std::endl;
        }
        
    }
}

/*

void sync_min(bool * val,std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> & min){
    while(!min.empty() && !val[min.top().second]){
        min.pop();
    }
    return;
}

void sync_max(bool * val,std::priority_queue<std::pair<int,int>> & max){
    while(!max.empty() && !val[max.top().second]){
        max.pop();
    }
    return;
}

int main(){
    int T,N;
    std::cin >> T;

    for(int i=0;i<T;i++){
        std::cin >> N;

        std::priority_queue<std::pair<int,int>> max_queue;
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> min_queue;
        bool val[N];

        for(int i=0;i<N;i++){
            char com;
            int data;

            std::cin >> com >> data;

            if(com == 'I'){
                max_queue.push(std::make_pair(data,i));
                min_queue.push(std::make_pair(data,i));
                val[i] = true;
            }else if(com == 'D'){

                if(data == 1){
                    sync_max(val,max_queue);
                    if(!max_queue.empty()){
                        val[max_queue.top().second] = false;
                        max_queue.pop();
                    }
                }else if(data == -1){
                    sync_min(val,min_queue);
                    if(!min_queue.empty()){
                        val[min_queue.top().second] = false;
                        min_queue.pop();
                    }
                }
            }

        }

        sync_max(val,max_queue);
        sync_min(val,min_queue);

        if(max_queue.empty()){
            std::cout << "EMPTY" << std::endl;
        }else{
            std::cout << max_queue.top().first << " " <<min_queue.top().first << std::endl;   
        }
        
    }
}
*/

