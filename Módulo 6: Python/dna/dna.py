# Code to test program:
# python dna.py databases/small.csv sequences/1.txt
import sys
import csv

def main():

    # Check for command-line usage
    while len(sys.argv) != 3:
                sys.exit(1)

    # Read database file into a variable
    database = []
    with open (sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open (sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # Find longest match of each STR in DNA sequence
    subsequences = list(database[0].keys())[1:]
    result = {}
    for subsequence in subsequences:
        result[subsequence] = longest_match(dna_sequence, subsequence)

    # Check database for matching profiles
    for person in database:
        match = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == result[subsequence]:
                match += 1

        if match == len(subsequences):
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)
    # Check for sequence
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            # If there is match
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run


main()