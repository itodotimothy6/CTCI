"""
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
"""

def rotate_90_degress(matrix):
	"""
	rotates an N x N matrix 90 degrees
	"""
	#reverse the matrix
	matrix.reverse() 

	#swap elements along the main diagonal
	for i in range(0, len(matrix)):
		for j in range(i+1, len(matrix)):
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
			#print_matrix(matrix)
	

def print_matrix(matrix):
	"""
	prints a matrix in a rectangular format
	"""
	for i in range(0, len(matrix)):
		print(matrix[i])
	print("\n")


def main():
	"""
	main function
	"""
	matrix = [[1,2,3,4], [5,6,7,8], [9, 10, 11, 12], [13, 14, 15, 16]]

	print("Original matrix: ")
	print_matrix(matrix)

	rotate_90_degress(matrix)
	print("Rotated matrix: ")
	print_matrix(matrix)

	#rotate 3 more times to get original matrix
	rotate_90_degress(matrix) #180 degrees
	rotate_90_degress(matrix) #270 degrees
	rotate_90_degress(matrix) #360 degrees or back to original

	print("Original matrix: ")
	print_matrix(matrix)

main()
