class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr(numRows);
        for(int i =0; i<numRows;i++)
        {
            arr[i].resize(i+1);
            arr[i][0]=arr[i][i]=1;

            for(int j = 1;j < i;j++)
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        return arr;
    }
};