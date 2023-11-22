# Solve the problem from the first set here
# For a given natural number n find the largest natural number written with the same digits. (e.g. n=3658, m=8653).

def digits_of_read_number(given_number):
    array_of_digits = []
    while given_number != 0:
        array_of_digits.append(given_number % 10)
        given_number //= 10
    if array_of_digits[len(array_of_digits) - 1 ] == 0:
        del array_of_digits[len(array_of_digits) - 1]
    array_of_digits.sort(reverse=True)

    return array_of_digits


def largest_number_written_with_the_same_digits(array_of_digits):
    new_number = 0
    for digit in array_of_digits:
        new_number = new_number * 10 + digit
    return new_number


def main():
    read_number = int(input("The number you want to introduce is: "))
    digits_of_number = digits_of_read_number(read_number)
    # if(digits_of_number[len(digits_of_number)- 1] == 0):
    #     raise Exception("The number that you enter cannot start with 0")
    print(largest_number_written_with_the_same_digits(digits_of_number))


if __name__ == "__main__":
    main()
