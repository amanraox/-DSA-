class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        const int maxPosition = 100;
        std::vector<int> seatCount(maxPosition + 1, 0);
        std::vector<int> studentCount(maxPosition + 1, 0);
        
        for (int seat : seats) {
            seatCount[seat]++;
        }
        
        for (int student : students) {
            studentCount[student]++;
        }
        
        int seatIdx = 0;
        int studentIdx = 0;
        int moves = 0;
        
        while (seatIdx <= maxPosition && studentIdx <= maxPosition) {
            while (seatIdx <= maxPosition && seatCount[seatIdx] == 0) {
                seatIdx++;
            }
            while (studentIdx <= maxPosition && studentCount[studentIdx] == 0) {
                studentIdx++;
            }
            
            if (seatIdx <= maxPosition && studentIdx <= maxPosition) {
                int count = std::min(seatCount[seatIdx], studentCount[studentIdx]);
                moves += count * std::abs(seatIdx - studentIdx);
                seatCount[seatIdx] -= count;
                studentCount[studentIdx] -= count;
            }
        }
        
        return moves;
    }
};