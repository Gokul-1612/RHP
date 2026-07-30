class Solution {
    final int diff[][]={{0,-1},{0,1},{-1,0},{1,0}};
    private void dfs(char grid[][],int i,int j, int R , int C){
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            int ar=i+diff[k][0],ac=j+diff[k][1];
            if(ar>=0 && ac >=0 && ar < R && ac < C && grid[ar][ac]=='1'){
                dfs(grid,ar,ac,R,C);
            }
        }
    }
    public int numIslands(char[][] grid) {
        int  R=grid.length,C=grid[0].length;
        int islands=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j,R,C);
                }
            }
        }
        return islands;
    }
}
