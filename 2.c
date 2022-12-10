#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> image{{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},
                                {0,1,1,1,0,0},{0,0,0,0,0,0},{0,1,1,1,1,0},
                                {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

int minX = INT_MAX, maxX =-1, minY = INT_MAX, maxY = -1;

// int x[4] = {0,0,1,-1};
// int y[4] = {-1,1,0,0};

void floodFill(vector<vector<int>>& image, int i ,int j, vector<vector<int>>& vis,vector<int> x,vector<int> y){
    int n = image.size();
    int m = image[0].size();
    if(i>=0 && j>=0 && i<n && j<m && image[i][j]==1 && vis[i][j]==0){
            
        maxX = max(maxX,j);
        maxY = max(maxY,i);
        minX = min(minY,j);
        minY = min(maxY,i);
        
        vis[i][j] = 1;
        
        for(int k = 0;k<4;k++){
            int a = i + x[k];
            int b = j + y[k];
            floodFill(image,a,b,vis,x,y);
        }
    }
}

void getPush(int n,int m,stack<vector<int>> &st,vector<vector<int>>& image,vector<vector<int>> &result,vector<int> x,vector<int> y){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(image[i][j] == 1){
                st.push({i,j});
            }
        }
    }
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    while(!st.empty()){

        minX = INT_MAX; 
        maxX =-1; 
        minY = INT_MAX;
        maxY = -1;
        
        vector<int> t = st.top();
        st.pop();
        if(vis[t[0]][t[1]]==1)
            continue;
        //vis[t[0]][t[1]] = 1;
        floodFill(image,t[0],t[1],vis,x,y);
        
        int height = maxY - minY + 1;
        int width = maxX - minX + 1;
        
        int centerX = (maxX + minX)/2;
        int centerY = (maxY + minY)/2;
        
        result.push_back({centerX,centerY,width,height});

    }
    
}

void solve(vector<vector<int>>& image, vector<vector<int>> &result,vector<int> x,vector<int> y){
    int n = image.size();
    int m = image[0].size();
    
    // vector<vector<int>> vis(n,vector<int>(m,0));
    stack<vector<int>> st;
    
    
    getPush(n,m,st,image,result,x,y);
}

int main()
{
    
    vector<int> x = {0,0,1,-1};
    vector<int> y = {-1,1,0,0};
    vector<vector<int>> result;
    solve(image,result,x,y);
    for(int i = 0; i<result.size();i++){
        cout<<"centerX: "<<result[i][0]<<"\t|| centerY: "<<result[i][1]<<"\t|| width: "<<result[i][2]<<"\t|| height: "<<result[i][3]<<endl;
    }
	return(0);
}
