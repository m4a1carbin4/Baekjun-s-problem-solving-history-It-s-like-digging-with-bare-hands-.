#include<iostream>
#include<algorithm>
#include<math.h>

long long arr[5000];

int main(){

    int N;
    std::cin >> N;

    for(int i=0;i<N;i++){
        std::cin >> arr[i];
    }

    std::sort(arr,arr+N);

    long long tmp_1 = -1;
    long long tmp_2 = -1;
    long long tmp_3 = -1;

    long long min = 3000000001;

    for(int i=0;i<N-2;i++){

        int left = i+1;
        int right = N-1;

        while(left < right){

            long long tmp = arr[i] + arr[left] + arr[right];

            
            if(min > abs(tmp)){
                min = abs(tmp);
                tmp_1 = arr[i];
                tmp_2 = arr[left];
                tmp_3 = arr[right];
            }

            if(tmp<0) left++;
            else right--;

        }
    }

    std::cout << tmp_1 << " " << tmp_2 << " " << tmp_3 << std::endl;

}