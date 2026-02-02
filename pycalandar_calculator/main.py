monthConversions = {
    1: "January",
    2: "February",
    3: "March",
    4: "April",
    5: "May",
    6: "June",
    7: "July",
    8: "August",
    9: "September",
    10: "October",
    11: "November",
    12: "December"
}

month1 = float(input("Enter first month: "))
print("Selected month: " + monthConversions[month1])
month2 = float(input("Enter second month: "))
print("Selected month: " + monthConversions[month2])

finalmonth = (month1 + month2) % 12

# Prints the full definition of a specified key.
print(monthConversions[finalmonth])