class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
             if(a[1]==b[1])
             return a[0]<b[0];

             return a[1]<b[1];

}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int c=0;
     //   vector<vector<int>>ans;
          int temp=-1e9;
        for(int i=0;i<pairs.size();i++){
        //    vector<int>temp;
          //  cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
          //  temp.push_back(pairs[i][0]);           
            if(temp==-1e9 ||temp<pairs[i][0]){
                temp=pairs[i][1];
                c++;
            }
           // ans.push_back(temp);
           
        }

return c;
        
    }
};