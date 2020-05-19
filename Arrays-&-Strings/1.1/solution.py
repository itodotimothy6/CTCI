# Is Unique: Implement an algorithm to determine if a string has all unique characters. 
# What if you cannot use additional data structures?

# O(n) time : O(1) space
def is_unique_a(s):
    if len(s) > 128:
        return False

    unique = set()
    for char in s:
        if char in unique:
            return False
        unique.add(char)
    return True

# O(n) time : O(1) space
def is_unique_b(s):
    if len(s) > 128:
        return False

    unique = [False for i in range(128)]
    for char in s:
        if not unique[ord(char)]:
            return False
        unique[ord(char)] = True
    return True

# O(n) time : O(1) space
def is_unique_c(s):
    if len(s) > 128:
        return False

    bit_map = 0
    for char in s:
        if (bit_map & 1 << ord(char)) > 0:
            return False
        bit_map = bit_map | 1 << ord(char)
    return True

def main():
    assert is_unique_a("abcdefghijklmnopqrstuvwxyz")
    assert is_unique_b("tamudashe") == False
    assert is_unique_c("aple") == True
    assert is_unique_c("a") == True
    assert is_unique_c("") == True
    print("Passed all test cases!")

if __name__ == '__main__':
    main()
