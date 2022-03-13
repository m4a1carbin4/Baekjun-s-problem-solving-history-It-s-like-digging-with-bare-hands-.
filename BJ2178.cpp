#include<iostream>
#include<queue>
#include<tuple>
#include<string>

bool chk(int a,int b, int N, int M){
    return 0<=a && a<N && 0<=b && b <M;
}

void find_path(std::queue<std::tuple<int,int,int>>* q,int** map,int** v_map,int N,int M, int* min){
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    std::tuple<int,int,int> tmp = q->front();
    q->pop();
    int count = std::get<2>(tmp);

    for(int i=0;i<4;i++){

        if(chk(std::get<0>(tmp)+dx[i],std::get<1>(tmp)+dy[i],N,M)){
            if(map[std::get<0>(tmp)+dx[i]][std::get<1>(tmp)+dy[i]] == 1 && v_map[std::get<0>(tmp)+dx[i]][std::get<1>(tmp)+dy[i]] != 1){
                if(std::get<0>(tmp)+dx[i] == N-1 && std::get<1>(tmp)+dy[i] == M-1){
                    if (count < *min || *min == 0){
                        *min = count+1;
                    }
                }else{
                    q->push(std::make_tuple(std::get<0>(tmp)+dx[i],std::get<1>(tmp)+dy[i],count+1));
                    v_map[std::get<0>(tmp)+dx[i]][std::get<1>(tmp)+dy[i]] = 1;
                }        
            }
        }
    }

}

int main(){
    int N = -1;
    int M = -1;

    std::cin >> N >> M;

    std::queue<std::tuple<int,int,int>> q;

    int ** map = new int*[N];
    int ** v_map = new int*[N];
    for (int i=0;i<N;i++){
        map[i] = new int[M];
        v_map[i] = new int[M];
    }

    for(int i=0;i<N;i++){
        std::string tmp;
        std::cin>>tmp;
        for(int a=0;a<tmp.size();a++){
            map[i][a] = tmp[a]-'0';
            v_map[i][a] = 0;
        }
    }

    q.push(std::make_tuple(0,0,1));

    int min = 0;

    while(!q.empty()){
        find_path(&q,map,v_map,N,M,&min);
    }

    std::cout << min << std::endl;

}