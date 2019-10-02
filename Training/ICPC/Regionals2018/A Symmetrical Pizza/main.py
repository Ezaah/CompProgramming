def gcd(a,b):
    while b > 0:
        tmp = b
        b = a % b
        a = tmp
    if a < 0:
        return -a
    else:
        return a

def lcm(a, b):
    ans = (a / gcd(a,b))*b
    if ans < 0:
        return -ans
    else:
        return ans

angle = 100*float(input())
least = lcm(angle, 36000)
print(int(least/angle))
