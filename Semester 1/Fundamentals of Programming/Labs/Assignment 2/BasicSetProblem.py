import random


def generate_random_list():
    number_of_elements = int(input("How many elements do you want your list to have: "))
    random_list = []
    for i in range(0, number_of_elements):
        aux = random.randint(1, 100)
        random_list.append(aux)
    print(random_list)
    return random_list


def Sort_Using_Selection_Method(random_list, step):
    steps_made = 0
    length = len(random_list)
    for i in range(0, length - 1):
        min_index = i
        for j in range(i + 1, length):
            if random_list[j] < random_list[min_index]:
                min_index = j
        if min_index != i:
            steps_made += 1
            random_list[i], random_list[min_index] = random_list[min_index], random_list[i]
        if steps_made == step:
            print(random_list)
            steps_made = 0
    if steps_made != 0:
        print(random_list)


def stooge_sort(arr, left, right, step, current_step=0):
    if left >= right:
        return

    if arr[left] > arr[right]:
        arr[left], arr[right] = arr[right], arr[left]
        current_step += 1

    if current_step == step:
        print(arr)
        current_step = 0

    if right - left + 1 > 2:
        third = (right - left + 1) // 3
        stooge_sort(arr, left, right - third, step, current_step)
        stooge_sort(arr, left + third, right, step, current_step)
        stooge_sort(arr, left, right - third, step, current_step)


def start():

    given_list = []
    while True:
        print("1. Generate a random list of numbers")
        print("2. Sort the list using Selection Method")
        print("3. Sort the list using Stooge Method")
        print("0. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            given_list = generate_random_list()
        elif choice == "2":
            step = int(input("What is the value of the parameter step? "))
            Sort_Using_Selection_Method(given_list, step)
        elif choice == "3":
            length = len(given_list)
            stooge_list = given_list.copy()
            step = int(input("What is the value of the parameter step? "))
            stooge_sort(stooge_list, 0, length - 1, step, 0)
        elif choice == "0":
            break
        else:
            print("invalid option")


start()
