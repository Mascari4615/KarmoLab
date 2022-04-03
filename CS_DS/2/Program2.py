from ast import Str
import sys
sys.setrecursionlimit(10**7)


def Program2_1():
    # 파이썬은 C와 달리 타입을 알아서 판단하기 때문에, 타입에 따른 변수를 각각 선언하여 그 크기를 출력하기에는 어렵다.
    return


def Program2_2():
    scores = [91, 86, 97]
    grades = ['A', 'B', 'A']

    print("\n *** 학년별 취득 학점 *** \n\n")

    for i in range(3):
        print((i+1), "학년 : 총점 = ", scores[i], ", 등급 = ", grades[i], "\n")


def Program2_3():
    multiply = []
    print("\n1~9의 정수를 입력하세요 : ")
    
    while (1):
        n = int(input())
        if (n < 0) or (n > 9):
            print("\n 1~9의 정수를 입력하세요 : ")
        else:
            break

    print("\n")
        
    print("\n")
    
    for i in range(9):
        multiply.append(n * (i + 1))
        print(" {0} * {1} = {2} \n".format(n, (i + 1), multiply[i]))

def Program2_4():
	# 파이썬은 문자 배열을 만들고 문자열을 대입하는 방식으로 초기화(저장)할 수 없다
    return

def Program2_5():
    # 파이썬은 문자 배열을 만들고 문자열을 대입하는 방식으로 초기화(저장)할 수 없다
    return

def Program2_6():
	array = [[[0 for _ in range(4)] for _ in range(3)] for _ in range(2)]
	value = 1;
	for i in range(2):
		for j in range(3):
			for k in range(4):
				array[i][j][k] = value;
				print("\n array[{0}][{1}][{2}] = {3}".format(i, j, k, array[i][j][k]))
				value += 1

def Program2_7():
    # 파이썬은 문자 배열을 만들고 문자열을 대입하는 방식으로 초기화(저장)할 수 없다
    return

def Program2_8():
    # 파이썬은 기본적으로 포인터를 지원하지 않는다
    return

def Program2_9():
    # 파이썬은 기본적으로 포인터를 지원하지 않는다
    return

def Program2_10():
    # 파이썬은 기본적으로 포인터를 지원하지 않는다
    return

def Program2_11():
    # 파이썬은 기본적으로 포인터를 지원하지 않는다
    return

def Program2_12():
    # 파이썬은 기본적으로 구조체를 지원하지 않는다
    return

def Program2_13():
    # 파이썬은 기본적으로 구조체를 지원하지 않는다
    return

def fact(n):
    if (n <= 1):
        print("\n fact(1) 함수 호출!")
        print("\n fact(1) 값 1 반환!!")
        return 1
    else:
        print("\n fact({0}) 함수 호출!".format(n))
        value = (n * fact(n - 1))
        print("\n fact({0}) 값 {1} 반환!!".format(n, value))
        return value


def Program2_14():
    n = int(input("\n 정수를 입력하세요"))
    result = fact(n)
    print("\n\n {0}의 팩토리얼 값은 {1}입니다.\n".format(n, result))
    return

def hanoi(n, start, work, target):
    if (n == 1):
        print(" {0}에서 원반 {1}를(을) {2}로 옮김 \n".format(start, n, target))
    else:
        hanoi(n - 1, start, target, work)
        print(" {0}에서 원반 {1}를(을) {2}로 옮김 \n".format(start, n, target))
        hanoi(n - 1, work, start, target)

def Program2_15():
    hanoi(3, 'A', 'B', 'C')
    return

Program2_15()
