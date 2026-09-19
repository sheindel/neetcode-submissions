const int GROUP_SIZE = 9;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Convert to row, column, and grid vectors
        std::vector<std::set<char>> columns;
        std::vector<std::set<char>> rows;
        std::vector<std::set<char>> boxes;

        // initialize sets
        for (int i = 0; i<GROUP_SIZE; i++) {
            columns.push_back({});
            rows.push_back({});
            boxes.push_back({});
        }

        
        for (int row = 0; row < GROUP_SIZE; row++) {
            for (int column = 0; column < GROUP_SIZE; column++) {
                auto cell = board[row][column];

                // std::cout << "Process cell " << row << "," << column << " with value " << cell << std::endl;

                if (cell == '.') {
                    continue;
                }

                // Check rows
                if (rows[row].contains(cell)) {
                    std::cout << "Found dupe cell in row " << row << " with value " << cell << std::endl;
                    return false;
                }
                rows[row].insert(cell);

                // Check columns
                if (columns[column].contains(cell)) {
                    std::cout << "Found dupe cell in column " << column << " with value " << cell << std::endl;
                    return false;
                }
                columns[column].insert(cell);

                // The box address for box 1 (0 indexed), for example, is 
                // 0,3 0,4 0,5  // 3 = 0,1 0,1 0,1
                // 1,3 1,4 1,5  // 3 = 0,1 0,1 0,1
                // 2,3 2,4 2,5  // 3 = 0,1 0,1 0,1
                // (row / 3) * 3 + column / 3
                const int box = (row / 3) * 3 + (column / 3);
                if (boxes[box].contains(cell)) {
                    std::cout << "Found dupe cell in box " << box << " with value " << cell << std::endl;
                    return false;
                }
                boxes[box].insert(cell);
            }
        }
        return true;
    }
};
