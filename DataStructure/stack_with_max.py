#python3
import sys

class StackWithMax():
    def __init__(self):
        self.__stack = []
        self.max =[]

    def Push(self, a):
        self.__stack.append(a)
        if (len(self.max) > 0):
            if a > self.max[-1]:
                self.max.append(a)
            else:
                self.max.append(self.max[-1])
        else:
            self.max.append(a)
        

    def Pop(self):
        assert(len(self.__stack))
        self.max.pop()
        self.__stack.pop()

    def Max(self):
        assert(len(self.__stack))
        return self.max[-1]


if __name__ == '__main__':
    stack = StackWithMax()

    num_queries = int(sys.stdin.readline())
    for _ in range(num_queries):
        query = sys.stdin.readline().split()

        if query[0] == "push":
            stack.Push(int(query[1]))
        elif query[0] == "pop":
            stack.Pop()
        elif query[0] == "max":
            print(stack.Max())
        else:
            assert(0)
