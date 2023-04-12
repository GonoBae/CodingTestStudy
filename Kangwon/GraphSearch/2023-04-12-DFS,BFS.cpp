#include<iostream>
#include<vector>

int main(){    
    int point,cnt,start;

    std::cin>>point>>cnt>>start;

    bool **array = new bool*[point];

    for(int i =0;i<point;i++){
        array[i] = new bool[point];
    }

    for(int i =0;i<cnt;i++){
        int a,b;
        std::cin>>a>>b;
        array[a][b] = true;
    }

    bool* chk = new bool[point];
    DFS(array,chk,point,start);

    return 0;
}

int DFS(const bool **array,bool *chk,int point ,int start){
    
    for(int i =0;i<point;i++){
        chk[start] = true;
        if(array[start][i]==true&&chk[i]==false){
            std::cout<< start;
            DFS(array,chk,point,i);
        }
    }
}