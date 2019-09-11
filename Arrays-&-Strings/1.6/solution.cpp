// Question 1.6
// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > rotateBy90(vector<vector<int> > matrix) {
    int N = matrix.size();
    vector<vector<int> > rotatedMatrix(N, vector<int>(N,0)); // Initialize as N*N Vector with 0s 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotatedMatrix[i][j] = matrix[j][N-i-1];
        }
    }

    return rotatedMatrix;
}

void rotateBy90_InPlace(vector<vector<int> > &matrix) {
    int N = matrix.size();

    // Iterating over every circular layer 
    for (int layer = 0; layer < N/2; layer++) {
        int i = layer;
        int j = layer;
        int a = (N - 1 - layer*2);
        int n = a;

        while (j < a) {
            int top = matrix[i][j];          
            matrix[i][j] = matrix[n][i];   
            matrix[n][i] = matrix[a][n];
            matrix[a][n] = matrix[j][a];
            matrix[j][a] = top;

            j++; n--;
        }
    }
}

// void rotateBy90_InPlace(vector<vector<int> > &matrix) {
//     int N = matrix.size(), a= 0, num = N - 1;;

//     while (a < N/2) {
//         int b = num;
//         while (b > 0){
//             int i = a, j = a, x = matrix[a][a];
            
//             while (j < N-a-1) {
//                 matrix[i][j] = matrix[i][j+1];
//                 j++;
//             }
//             while (i < N-a-1) {
//                 matrix[i][j] = matrix[i+1][j];
//                 i++;
//             }
//             while (j > a) {
//                 matrix[i][j] = matrix[i][j-1];
//                 j--;
//             }
//             while (i > a) {
//                 matrix[i][j] = matrix[i-1][j];
//                 i--;
//             }

//             matrix[a+1][a] = x;
//             b--;
//         }
//         a++;
//         num -= 2;
//     }
// }



int main() {
    vector<vector<int> > matrix;

    // Create a num * num matrix
    int num = 1;
    for(int i=0; i < 7; i++) {
        vector<int> rows;
        for (int j=0; j < 7; j++) {
            rows.push_back(num++);
        }
        matrix.push_back(rows);
    }

    // Rotate function using new matrix
    vector<vector<int> > rMatrix = rotateBy90(matrix);
    // Print matrix
    for (int i=0; i < matrix.size(); i++) {
        for (int j=0; j < matrix.size(); j++) {
            cout << rMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // In place rotate func
    rotateBy90_InPlace(matrix);
    // Print matrix
    for (int i=0; i < matrix.size(); i++) {
        for (int j=0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}