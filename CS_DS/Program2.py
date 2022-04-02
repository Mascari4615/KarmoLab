from ast import Str


def Program2_17():
    subject1Scores = []
    subject2Scores = []
    subject3Scores = []

    for i in range(10):
        print(str(i) + "학번 학생의 성적 입력")
        s = list(input().split())
        subject1Scores.append(int(s[0]))
        subject2Scores.append(int(s[1]))
        subject3Scores.append(int(s[2]))

    for i in range(10):
        total = subject1Scores[i] + subject2Scores[i] + subject3Scores[i]
        average = total / 3
        print("학번\t국어\t영어\t수학\t총점\t평균\n")
        print("**************************************\n")
        print(f"{i}\t{subject1Scores[i]}\t{subject2Scores[i]}\t{subject3Scores[i]}\t{total}\t{average}\n\n")

def Program2_18():
    arr = [ 19,2,25,92,36,45 ]

    print("배열 요소 출력\n")
    for i in range(6):
        print(arr[i])

    print("\n\n최솟값 최댓값 출력\n")
    min = arr[0]
    max = arr[0]
    for i in range(6):
        if (min > arr[i]):
            min = arr[i]

        if (max < arr[i]):
            max = arr[i]
    print(min, max)

    print("\n\n평균 출력\n")
    total = 0
    average = 0
    for i in range(6):
        total += arr[i]
        
    average = total / 6
    print(average)

    print("\n\n분산 출력\n")
    variance = 0
    for i in range(6):
        variance += pow(arr[i] - average, 2)
    variance /= 6
    print(variance)

def Program2_19():
    strings = []

    for i in range(5):
        strings.append(input())

    for i in range(5):
        print(strings[i])

def Program2_20():
    input1 = input()
    input2 = input()

    if input1 == input2:
        print("문자열 같음")
    else:
        print("문자열 다름")
    

def Program2_25(n):
    if (n < 1) :
        return n
    return n + Program2_25(n - 1)

def Program2_26(n):
    if n == 0 or n == 2:
        return n
    else:
        return Program2_26(n - 1) + Program2_26(n - 2)

# print(Program2_25(3))

import sys
sys.setrecursionlimit(10**6)
print(Program2_26(3))