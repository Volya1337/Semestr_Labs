a = float(input("Введите число: "))
b = a
while b*b != a:
    b = (b + (a / b)) / 2
print(b)
