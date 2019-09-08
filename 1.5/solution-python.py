#ctci 4th edition question 1.5
#replace all the spaces in a string with "%20"
word = input("Enter the string to convert: ")
result = ""
for char in word:
	if char == " ":
		result += "%20"
	else:
		result += char
word = result

print(word)
