#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int check(int length, string * arr, int N, int W, int H){

	int tmp = 0;

	if(W < length){
		return 0;
	}else{
		tmp = W/length;
	}
	
	int a = 1;
	int i = 1;
	int len = 0;
	len = arr[0].length();



	while(true){
		if(i == N){
			break;
		}

		if(len + 1 + arr[i].length() > length){
			a++;
			len = arr[i].length();
			i++;
			continue;
		}
		len = len + 1 + arr[i].length();
		i++;

	}

	if( a * tmp > H ){
		
		return check(length+1,arr,N,W,H);

	}else{

		return tmp;
	
	}


}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int H = 0;
        int W = 0;
        int N = 0;

        cin >> H >> W >> N ;

        string * arr = new string[N];

		for(int i=0;i<N;i++){
			cin >> arr[i];
		}

		if(N == 0 || W == 0 || H == 0){
			cout << "#" << test_case << " 0" <<endl;
			continue;
		}
        
		int length = arr[0].length();

		for(int i=0;i<N;i++){

			if(length < arr[i].length()){
				length = arr[i].length();
			}

		}

		int ans = check(length,arr,N,W,H);

		cout << "#" << test_case << " " << ans <<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}