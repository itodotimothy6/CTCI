/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int> >& matrix){
	for(auto& x: matrix)
	{
		for(auto& j: x)
			cout << j << " ";
		cout << endl;
	}
}

void rotate_90_degrees(vector<vector<int> >& matrix)
{
	int N = matrix.size();
	//reverse the main vector
	for(int i = 0; i < N/2; i++)
		swap(matrix[i], matrix[N - i - 1]);
	
	//swap elements along the main diagonal
	for(int i = 0; i < N-1; i++)
		for(int j = i + 1; j < N; j++)
			swap(matrix[i][j], matrix[j][i]);
}

int main()
{
	vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	
	cout << "Original Matrix: " << endl;
	print(matrix);
	
	rotate_90_degrees(matrix);
	cout << "Rotated Matrix: " << endl;
	print(matrix);

	//rotate 3 more times to get original matrix
	rotate_90_degrees(matrix);
	rotate_90_degrees(matrix);
	rotate_90_degrees(matrix);
	cout << "Original Matrix: " << endl;
	print(matrix);

	return 0;
}
