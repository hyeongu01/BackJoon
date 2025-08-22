S = list(map(int, list(input())))

zero_or_one = (0, 1)
current = S[0]

for num in S[1:]:
    if num in zero_or_one or current in zero_or_one:
        current += num
    else:
        current *= num
print(current)