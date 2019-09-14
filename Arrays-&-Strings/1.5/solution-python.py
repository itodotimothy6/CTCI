#write a function to replace all the spaces in a sentence with "%20"
def replace(sentence):
	"""
	this function URLifies a string
	"""
	result = ""
	for char in sentence:
		if char == " ":
			result += "%20"
		else:
			result += char
	return result

word = "my name is faruq"
print(word)
word = replace(word)
print(word)
