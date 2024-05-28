class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int ans = -1;
        int window = 0, left = 0;

        for(int i=0; i<n; i++){
            window += Math.abs(s.charAt(i) - t.charAt(i));
            while(window > maxCost) {
                window -= Math.abs(s.charAt(left) - t.charAt(left));
                left++;
            }
            ans = Math.max(ans, i - left + 1);
        }
        return ans;
    }
}