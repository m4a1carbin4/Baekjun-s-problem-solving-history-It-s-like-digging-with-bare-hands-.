#include<iostream>
#include<cstdlib>

using namespace std;

int c_info[12][2];
int distance_table[12][12];
int visit[12] ={};
int N;
int total_len;

void calc_path(int from, int to, int count, int cur_len){
    int i;
    if(total_len < cur_len){
        return;
    }
    if(count == N){
        visit[1] = 1;
        calc_path(to,1,count +1,cur_len + distance_table[to][1]);
        visit[1] = 0;
        return;
    }
    if(count == N+1){
        if(total_len > cur_len){
            total_len = cur_len;
            return; 
        }
    }

    for( i=2;i<N+2;i++){
        if(visit[i]){
            continue;
        }
        visit[i] =1;
        calc_path(to,i,count+1,cur_len + distance_table[to][i]);
        visit[i] =0;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;

        for(int i=0;i<N+2;i++){
            cin >> c_info[i][0] >> c_info[i][1];
        }
        for(int i=0;i<N+1;i++){
            distance_table[i][i] = 0;
            for(int j=i+1;j<N+2;j++){
                distance_table[i][j] = abs(c_info[i][0] - c_info[j][0]) + abs(c_info[i][1] - c_info[j][1]);
                distance_table[j][i] = distance_table[i][j];
            }
        }

       total_len = 1000000;
       for(int i=2;i<N+2;i++){
           visit[i] = 1;
           calc_path(0,i,1,distance_table[0][i]);
           visit[i] = 0;
       } 

       cout << "#" <<test_case << " " << total_len <<endl;

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}