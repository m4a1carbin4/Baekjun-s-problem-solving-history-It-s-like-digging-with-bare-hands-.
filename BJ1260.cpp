#include <iostream>
#include <stack>
#include <queue>

void stack_add(int** arr,int* arr_c,int N,std::stack<int>* s){
    int tmp = (*s).top();
    std::cout << tmp+1 << " ";
    (*s).pop();

    for(int i=0;i<N;i++){
        if(arr[tmp][i] == 1 && arr_c[i] == 0){
            (*s).push(i);
            arr_c[i] = 1;
            stack_add(arr,arr_c,N,s);
        }
    }
}

int main(){

    int N = -1;
    int M = -1;
    int V = -1;

    std::stack<int> s;
    std::queue<int> q;

    std::cin>>N>>M>>V;

    int** arr;

    arr = new int*[N];

    for (int i=0;i<N;i++){
        arr[i] = new int[N];
    }

    for(int i=0;i<N;i++){
        for(int a=0;a<N;a++){
            arr[i][a] = 0;
        }
    }
    int arr_c[N] = {0,};

    for(int i=0;i<M;i++){

        int row = -1;
        int col = -1;

        std::cin >> row >> col;

        arr[row-1][col-1] = 1;

    }

    for(int i=0;i<N;i++){
        for(int a = 0;a<N;a++){
            if(arr[i][a] == 1){
                arr[a][i] = 1;
            }
        }
    }

    s.push(V-1);
    arr_c[V-1]=1;

    stack_add(arr,arr_c,N,&s);

    std::cout<<std::endl;

    int arr_c_q[N] = {0,};
    
    q.push(V-1);
    arr_c_q[V-1] = 1;

    while(!q.empty()){

        int tmp = q.front();
        std::cout << tmp+1 << " ";
        q.pop();

        for(int a = 0;a<N;a++){
            if(arr[tmp][a] == 1 && arr_c_q[a] == 0){
                q.push(a);
                arr_c_q[a] = 1;
            }
        }

    }

    std::cout<<std::endl;
}

