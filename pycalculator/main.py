run = True


while run == True:
    num1 = float(input("Enter first number\n\n>> "))
    op = input("\nEnter operator\n\n>> ")
    num2 = float(input("\nEnter second number\n\n>> "))

    if op == "+":
        print(num1 + num2)
    elif op == "-":
        print(num1 - num2)
    elif op == "*":
        print(num1 * num2)
    elif op == "/":
        print(num1 / num2)
    else:
        print("Error! Invalid operation!")

    key = input("exit program(Y/N)?: ")

    if key == "Y":
        run = False

print("goodbye")
