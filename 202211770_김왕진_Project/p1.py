# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    mean = sum(input) // len(input)  # 평균값
    median = sorted(input)[len(input) // 2]  # 중앙값

    result = [mean, median]
    return result

# 입력값 출력
print("입력값")
for num in input:
    print(num)

# 문제 풀이
result = problem1(input)

# 출력값 출력
print("출력값")
print(result[0])
print(result[1])
print("정답입니다.")
