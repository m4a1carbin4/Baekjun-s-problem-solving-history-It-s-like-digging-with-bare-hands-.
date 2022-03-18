#include<iostream>
#include<algorithm>

int main(){
    int n,k;

    std::cin>> n >> k;

    int arr[n];

    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }

    std::sort(arr,arr+n);

    int table[n][k];

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){

            if((j+1)>=arr[i]){

                int mod = (j+1)%arr[i];
                int ptr = j+1 - arr[i];

                if(mod==0){
                    int tmp = (j+1)/arr[i];

                    if(i == 0){
                        table[i][j] = tmp; 
                    }else{
                        if(table[i-1][j] == -1){
                            table[i][j] = tmp;
                        }else{
                            table[i][j] = (tmp <= table[i-1][j]) ? tmp : table[i-1][j];
                        }
                    }
                    
                }else if(table[i][ptr-1] != -1){
                    int tmp = 1 + table[i][ptr-1];

                    if(table[i-1][j] == -1){
                        table[i][j] = tmp;
                    }else{
                        table[i][j] = (tmp <= table[i-1][j]) ? tmp : table[i-1][j];
                    }

                }else if(table[i][ptr-1] == -1){

                    if(i == 0){
                        table[i][j] = -1;
                    }else{
                        table[i][j] = table[i-1][j];
                    }
                    
                }               
                
            }else{

                if(i == 0){

                    table[i][j] = -1;

                }else{

                    table[i][j] = table[i-1][j];

                }

                
            }
        }
    }

    std::cout << table[n-1][k-1] << std::endl;

}