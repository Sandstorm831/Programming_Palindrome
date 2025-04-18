# Naukri Solution
# Link : https://www.naukri.com/code360/problems/find-minimum-number-of-coins_975277

def MinimumCoins(n: int) -> List[int]:
    # write your code here
    orig = n
    coins = []
    while n > 0:
        if n >= 1000:
            x = n // 1000
            n %= 1000
            temp = [1000 for i in range(x)]
            coins += temp
        if n >= 500:
            x = n // 500
            n %= 500
            temp = [500 for i in range(x)]
            coins += temp
        if n >= 100:
            x = n // 100
            n %= 100
            temp = [100 for i in range(x)]
            coins += temp
        if n >= 50:
            x = n // 50
            n %= 50
            temp = [50 for i in range(x)]
            coins += temp
        if n >= 20:
            x = n // 20
            n %= 20
            temp = [20 for i in range(x)]
            coins += temp
        if n >= 10:
            x = n // 10
            n %= 10
            temp = [10 for i in range(x)]
            coins += temp
        if n >=  5:
            x = n // 5
            n %= 5
            temp = [5 for i in range(x)]
            coins += temp
        if n >= 2:
            x = n // 2
            n %= 2
            temp = [2 for i in range(x)]
            coins += temp
        if n >= 1:
            x = n // 1
            n %= 1
            temp = [1 for i in range(x)]
            coins += temp
    return coins
    # pass
