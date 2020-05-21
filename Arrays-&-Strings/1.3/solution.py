# URLify: Write a method to replace all spaces in a string s with '%20'. You may
# assume that the string has sufficient space at the end to hold the additional
# characters, and that you are given the 'true' length of the string.

# Note: python strings are immutable, avoid appending to a string as it creactes a
# new string and copies everything to the new string making the runtime quadratic,
# instead, use an array and use the join method with forms back the string in O(n)

# O(n) time O(n) space
def URLify(s, length):
    result = []
    for i, char in enumerate(s):
        if i == length:
            break
        if char == " ":
            result.append("%20")
        else:
            result.append(char)
    return "".join(result)



def main():
    s = "Mr John Smith      "
    length = 13
    print(URLify(s, length))

if __name__ == '__main__':
    main()
