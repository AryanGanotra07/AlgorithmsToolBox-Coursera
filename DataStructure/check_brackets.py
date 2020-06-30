# python3

from collections import namedtuple

class Bracket:
    """Bracket class.
    It stores a bracket type which is one of [, (, { and position of the
    bracket in the string.
    """

    def __init__(self, bracket_type, position):
        self.bracket_type = bracket_type
        self.position = position

    def match(self, char):
        """Matches given character with the bracket's type."""

        if self.bracket_type == '[' and char == ']':
            return True
        if self.bracket_type == '{' and char == '}':
            return True
        if self.bracket_type == '(' and char == ')':
            return True
        return False

def find_mismatch(text):
    stack = []
    for index, char in enumerate(text, start=1):

        if char in ("[", "(", "{"):
            stack.append(Bracket(char, index))

        elif char in ("]", ")", "}"):
            if not stack:
                return index

            top = stack.pop()
            if not top.match(char):
                return index
    if stack:
        top = stack.pop()
        return top.position

    return "Success"


def main():
    text = input()
    mismatch = find_mismatch(text)
    print(mismatch)
    # Printing answer, write your code here


if __name__ == "__main__":
    main()
