# Given a string, write a function to check if it is a permutation of a
# palindrome. A palindrom is a word or phraze that is the same forwards and
# backwards. A permutation is a rearrangement of letters. A palindrome does not
# need to be linited to just dictionary words.

# Note: a maximum of one character should have an odd count for a string
# permutation to be a palindrome

# O(n) time : O(1) space
def palindrome_permutation(s):
    table = {}
    for char in s:
        curr = char.lower()
        if ord('a') <= ord(curr) and ord(curr) <= ord('z'):
            table[curr] = table.get(curr, 0) + 1

    odd_count = 0
    for char in table:
        if table[char] % 2 != 0:
            odd_count += 1

    if odd_count > 1:
        return False
    else:
        return True

# O(n) time O(1) space
def count_set_bits(n):
    total = 0
    while n:
        total += n & 1
        n = n >> 1
    return total

def palindrome_permutation_using_bitmask(s):
    mask = 0
    for char in s:
        if ord(char.lower()) < ord('a') or ord(char.lower()) > ord('z'):
            continue

        char_ascii = ord(char.lower()) - ord('a')
        if mask & (1 << char_ascii):
            mask = mask & ~(1 << char_ascii)
        else:
            mask = mask | (1 << char_ascii)

    if count_set_bits(mask) > 1:
        return False
    return True



def main():
    s = "Tact Coa"
    assert palindrome_permutation(s) == True
    assert palindrome_permutation_using_bitmask(s) == True
    print("Passed all test cases!")

if __name__ == '__main__':
    main()
