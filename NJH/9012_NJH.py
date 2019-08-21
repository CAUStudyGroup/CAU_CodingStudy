#result:시간초과(개선여지있음)
'''
백준: 9012문제 For Stack 사용
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다.
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” ,
그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

[입력]
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다.
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다
'''


#list를 이용한 python stack 사용
class Stack:
    def __init__(self):
        self.data=[]
        self.top=-1
    def push(self,datum):
        self.data.append(datum) #위에 입력에 의하면 저정되에 의해서는 별도에 에러가 나진 않을 것이다.
        self.top=self.top+1
    def pop(self):
        try: #불가능한 것에 시도를 할 수 있으므로 사전에 예외처리가 필요
            self.top=self.top-1
            return self.data.pop()
        except IndexError:
            print("Stack is empty")

    def peek(self):#top이 가리키는 것을 보여줌
        try:
            return self.data[self.top
            ]
        except IndexError: #0미만의 것이 예외처리될것
            print("Stack is empty")

    def __len__(self):
        return len(self.data)

    def isEmpty(self):
        return self.__len__()==0 #위에서 갯수 센것의 결과에 따라서!

#Stack을 사용하도록 해보자.
def VPS_test(string): #맞는 괄호일경우에는 True를 반환하도록 하자.
    st=Stack()
    for i in range(len(string)):
        #만약에 "("를 보면 Stack에 넣는다.
        if(string[i]=='('):
            st.push(string[i])
        elif (string[i]==')')and(st.isEmpty()==False):
            st.pop()
        else: #즉 )인데도 불구하고 False가 나온 경우를 의미한다.
            return False
    #전체를 다보았음
    if (st.isEmpty()==False):
        return False #남는 것이 있다는 것(즉, "("가 더 많다는 것을 의미한다.)
    return True


#위와 다른 방법을 사용해보자.
#첫번째 input은 무조것 숫자에 대한 것이다.
num=int(input())

for i in range(num): #위에서 입력받은 횟수만큼
    string=input()
    if(VPS_test(string))==True:
        print("YES")
    else:
        print("NO")
