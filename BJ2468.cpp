#include<iostream>

bool chk(int a,int b, int N, int M){
    return 0<=a && a<N && 0<=b && b <M;
}

void find_area(int ** map,int x,int y, int** map_c,int N,int high){

    map_c[x][y] = 1;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int i=0;i<4;i++){
        if(chk(x+dx[i],y+dy[i],N,N)){
            if(map[x+dx[i]][y+dy[i]] > high && map_c[x+dx[i]][y+dy[i]] != 1){
                find_area(map,x+dx[i],y+dy[i],map_c,N,high);
            }
        }
    }

}

int main(){
    int N = -1;
    std::cin >> N;

    int ** map = new int*[N];
    int ** map_c = new int*[N];
    for(int i=0;i<N;i++){
        map[i] = new int[N];
        map_c[i] = new int[N];
    }

    int min_h = 0;
    int max_h = 0;

    for(int i=0;i<N;i++){
        for(int a=0;a<N;a++){
            std::cin>>map[i][a];
            map_c[i][a] = 0;
            if(map[i][a] < min_h || min_h == 0){
                min_h = map[i][a];
            }
            if(map[i][a] > max_h || max_h == 0){
                max_h = map[i][a];
            }
        }
    }

    int max_a = -1;
    int num_a = 0;

    for(int i=min_h-1;i<=max_h;i++){
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                if( map[a][b] > i && map_c[a][b] !=1){
                    find_area(map,a,b,map_c,N,i);
                    num_a++;
                }
            }
        }
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                map_c[x][y] = 0;
            }
        }
        if(num_a > max_a || max_a == -1){
            max_a = num_a;
        }
        num_a = 0;
    }

    std::cout << max_a << std::endl;

}