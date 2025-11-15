#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>resources={3,3,2};

    vector<vector<int>>max={
        {7,5,3},   
        {3,2,2},   
        {9,0,2},   
        {2,2,2},   
        {4,3,3}
    };

    vector<vector<int>>allocated={
        {0,1,0},   
        {2,0,0},   
        {3,0,2},   
        {2,1,1},   
        {0,0,2}
    };

    int n=5; //number of processes
    int m=3; //number of resources

    vector<vector<int>>need(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }

    vector<int>available(m);
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=allocated[j][i];
        }
        available[i]=resources[i]-sum ;
    }

    vector<bool>finished(n,false);
    vector<int>safeSeq;
    int count=0;

    while(count<n){
        bool found = false;
        
        for(int i=0;i<n;i++){
            if(!finished[i]){
                bool canRun= true;

                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        canRun=false;
                        break;
                    }
                    
                }
                if(canRun){
                    for(int j=0;j<m;j++){
                        available[j]+=allocated[i][j];
                    }
                    safeSeq.push_back(i);
                    found=true;
                    finished[i]=true;
                    count++;
                }
            }
        }
        if(!found){
            break;
        }

    }

    if(count==n){
        cout<<"System is safe/n Safe sequence is"<<endl;
        for(int i:safeSeq){
            cout<<"P"<<i<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"System is not safe"<<endl;
    }


}