import random  # imports the libraries needed
def memorygame():
    numbers = []  # the numbers you have to remember
    score = 0
    while True:  # loops forever until you get it wrong

        numbers.append(random.randint(0, 9))  # gets the random numbers
        print(numbers[-1])  # printst the next number in the sequence you have to remember
        if (input("Type all the numbers so far: ")) == (''.join(map(str, numbers))): 
        # check if the numbers you input are the same as the actual ones
            score += 1    # adds to your score
            for x in range(10000):
                print("no peeking")  # means you can't check what the previous numbers were
            print("your score is " + str(score))  
            print("you're right")  # gives you feedback on your answer
            continue # loops again
        else:  # if it is different it breaks the function
            print("You're wrong")
            print(f'it was {numbers}')  # tells you the actual numbers
            break  # ends the game


memorygame()
