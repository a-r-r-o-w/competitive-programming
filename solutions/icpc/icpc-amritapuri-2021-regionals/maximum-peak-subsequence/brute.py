with open('1.out') as file:
    answers = [list(map(int, line.split())) for line in file.readlines()]

t = int(input())

for test in range(t):
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    ans = -1
    result = []

    def dfs (index, array):
        global n, k, p, ans, result
        if index >= len(p):
            x = len(array)
            if x != k:
                return
            count = 0
            for i in range(1, x - 1):
                if array[i - 1] < array[i] and array[i + 1] < array[i]:
                    count += 1
            if count > ans:
                ans = count
                result = [array[:]]
            else:
                result.append(array[:])
        else:
            # try with taking
            array.append(p[index])
            dfs(index + 1, array)
            array.pop()
            # try without taking
            dfs(index + 1, array)
    
    dfs(0, [])
    
    if answers[test] not in result:
        print('Testcase Found')
        print(n, k)
        print(p)
        print('Retard')
        print(answers[test])
        print('Correct')
        print(result)
        break
