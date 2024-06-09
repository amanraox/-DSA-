class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] prefixMod = new int[nums.length];
        {
            int sum = 0;
            for(int i=0;i<nums.length;i++) {
                sum+=nums[i];
                prefixMod[i] = sum%k;
            }
        }
        int[] m = new int[k];
        m[0]++;

        for (int i=0;i<nums.length;i++) {
          int x = prefixMod[i];
          if(x < 0) {
            x += k;
          }
          m[x]++;
        }
        int count = 0;
        for(int i=0;i<k;i++) {
          count += (m[i] * (m[i]-1)) / 2;
        }
        return count;
    }
}