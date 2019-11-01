from sys import stdin
sum = 0
for line in stdin:
    if(int(line) == 0):
        break
    sum += int(line)
print(sum)