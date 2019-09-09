// Question 1.7
// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column is set to 0.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void zerofy(vector<vector<int> > &matrix) {
    unordered_set<int> rowSet, columnSet;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] == 0) {
                rowSet.insert(i);
                columnSet.insert(j);
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (rowSet.find(i) != rowSet.end() || columnSet.find(j) != columnSet.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {

    // Enter a matrix
    int M, N;
    cout << "Enter M: ";
    cin >> M;
    cout << "Enter N: ";
    cin >> N;
    vector<vector<int> > matrix;
    for (int i = 0; i < M; i++) {
        cout << "Enter row: ";
        vector<int> row;
        for (int j = 0; j < N; j++) {
            int elem;
            cin >> elem;
            row.push_back(elem);
        }
        matrix.push_back(row);
    }

    zerofy(matrix);

    // Print zerofied matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}