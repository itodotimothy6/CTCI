# Check permutations: Given two strings, write a method to decide if one is a
# permutation of the other

# Note: O(1) space -> memory used does not scale with any given input size

# O(n) time : O(1) space
def check_permutation_using_array(first, second):
    if len(first) != len(second):
        return False

    compare = [0 for i in range(128)]
    for f, s in zip(first, second):
        compare[ord(f)] += 1
        compare[ord(s)] -= 1

    for i in compare:
        if i != 0:
            return False
    return True

# O(n) time : O(1) space
def check_permutation_using_dictionary(first, second):
    if len(first) != len(second):
        return False

    compare = {}
    for f, s in zip(first, second):
        compare[f] = compare.get(f, 0) + 1
        compare[s] = compare.get(s, 0) - 1

    for i in compare.values():
        if i != 0:
            return False
    return True

def main():
    s1 = "dwightschrute"
    t1 = "schrutedwight"
    assert check_permutation_using_array(s1, t1) == True
    assert check_permutation_using_dictionary(s1, t1) == True

    s2 = ""
    t2 = ""
    assert check_permutation_using_array(s2, t2) == True
    assert check_permutation_using_dictionary(s2, t2) == True

    s3 = "a"
    t3 = "b"
    assert check_permutation_using_array(s3, t3) == False
    assert check_permutation_using_dictionary(s3, t3) == False

    print("Passed all test cases")

if __name__ == '__main__':
    main()

