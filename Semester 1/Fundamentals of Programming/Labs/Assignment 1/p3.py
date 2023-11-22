# Solve the problem from the third set here
# Generate the largest perfect number smaller than a given natural number n. If such a number does not exist, a message should be displayed.
# A number is perfect if it is equal to the sum of its divisors, except itself. (e.g. 6 is a perfect number, as 6=1+2+3).

def is_perfect_number(number):
    divisors_sum = 0
    for i in range(1, number):
        if number % i == 0:
            divisors_sum += i
    return divisors_sum == number


def largest_perfect_number_smaller_than_n(n):
    for number in range(n - 1, 0, -1):
        if is_perfect_number(number):
            return number
    return None


def main():
    read_number = int(input("Please enter a number:"))
    result = largest_perfect_number_smaller_than_n(read_number)
    if result is not None:
        print(f"The largest perfect number smaller than {read_number} is {result}.")
    else:
        print(f"There is no perfect number that is smaller than {read_number}")


if __name__ == "__main__":
    main()
