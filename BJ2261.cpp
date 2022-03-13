#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int find_min(std::vector<std::pair<int,int>> & v,int start,int end){

    int dl = -1;

    int dr = -1;

    int mid = ceil((float)(start+end)/2);

    if((end - start) < 3){

        int min_d = std::numeric_limits<int>::max();
    
        for(int i=start;i<=end;i++){

            int tmp = i+1;
            if(tmp > end)tmp=start;

            int dx = (v[i].first - v[tmp].first);
            int dy = (v[i].second - v[tmp].second);

            int ptr = dx * dx + dy * dy;

            min_d = std::min(min_d,ptr);

        }
        return min_d;

    }else{
        dl = find_min(v,start,mid-1);
        dr = find_min(v,mid,end);
    }

    int min = (dl <= dr) ? dl : dr;

    std::vector<std::pair<int,int>> s;
    s.reserve(end-start+1);

    int ax = v[mid].first;

    for(int i=mid;i<=end && ((v[i].first - ax)*(v[i].first - ax)) < min; i++){
        s.push_back(v[i]);
    }

    for(int i=mid-1;i>=start && ((v[i].first - ax)*(v[i].first - ax)) < min; i--){
        s.push_back(v[i]);
    }

    std::sort(s.begin(), s.end(), [](const std::pair<int,int> a, const std::pair<int,int> b) {
        return a.second < b.second;    
    });

    for(int i=0;i<s.size();i++){
        for(int a=i+1;a<=i+7;a++){
            if(a == s.size()){
                break;
            }else{
                int dy = (s[i].first - s[a].first);
                int dx = (s[i].second - s[a].second);

                int ptr = dx * dx + dy * dy; 
                min = std::min(min,ptr);
            }
        }
    }

    return min;

}

int main(){

    std::ios_base::sync_with_stdio(false);
    int N = 0;

    std::cin >> N;

    std::vector<std::pair<int,int>> v(N);

    for(int i=0;i<N;i++){
        std::cin >> v[i].first >> v[i].second;
    }

    std::sort(v.begin(),v.end());

    std::cout << find_min(v,0,N-1) << std::endl;

}