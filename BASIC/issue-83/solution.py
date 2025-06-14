import re

# Added for part 2
# Map out spelled out words to respective numbers
WORD_TO_DIGIT = {
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9"
}

# Added for part 2
def find_digits(line):
    # Spelled out num converted to int equivalent for each line
    sorted_words = sorted(WORD_TO_DIGIT.keys(), key = len, reverse = True)
    pattern = r'(?=(\d+|' + '|'.join(sorted_words) + r'))'
    # Extracts numerals out of the string with \d+
    # Account for overlapping words denoting separate numbers
    
    matches = re.findall(pattern, line, re.IGNORECASE)
    digits = []

    for match in matches:
        if match.lower() in WORD_TO_DIGIT:
            digits.append(WORD_TO_DIGIT[match.lower()])
        else:
            digits.extend(list(match)) # split the numerals
    # Returns a list 'digits' of all numbers found in the line
    return digits

def num_extract(line):
# takes a line and extracts the first and last numbers found    
    # digits = re.findall(r'\d', line)
    digits = find_digits(line) # use the new helper function
    if len(digits) >= 2:
        return int(digits[0] + digits[-1])
    elif len(digits) > 0 and len(digits) < 2: # if only one num found
        return int(digits[0] + digits[0]) # duplicate the single num
    else:
        return 0
    
def calculate_sum(file_path):
# calculates sum of all numbers found in file
    total = 0 # running sum
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip() # remove white space
            total += num_extract(line) 
    return total

if __name__== "__main__":
    ## test function num_extract
    # line = "xtwone3four"
    # num = num_extract(line)
    # print("Extracted the number", num)
    
    ## test the mapped digits and find_digits function
    # line = "xtwone3four"
    # print("digits for the line are", find_digits(line)) 
    # print("\nthe extracted number for the line is ", num_extract(line))

    input_file = 'input2.txt'
    solution_sum = calculate_sum(input_file)
    print("The answer is", solution_sum)
