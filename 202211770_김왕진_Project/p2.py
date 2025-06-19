# 프로젝트 문제 2번
input = ")))()"

def problem2(s):
    stack = []
    for c in s:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if stack and stack[-1] == '(':
                stack.pop()  # 쌍 맞는 경우 제거
            else:
                stack.append(c)  # 쌍 못 맞추면 넣음

    # 남은 괄호는 전부 짝이 안 맞은 것 → 각각 짝 하나씩 추가 필요
    return len(stack)

result = problem2(input)
print(result)
assert result == 3
print("정답입니다.")
