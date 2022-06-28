#include <iostream>
#include <string>
#include <Windows.h>
#include "Stack.h"
using namespace std;

bool isOpeningParenthesis(char p) {
	return(p == '{' || p == '[' || p == '(' || p == '<');
}

bool isClosingParenthesis(char p) {
	return(p == '}' || p == ']' || p == ')' || p == '>');
}

bool matchingParentheses(char x, char y) {
	return ((x == '{' && y == '}') || (x == '[' && y == ']') || (x == '(' && y == ')') || (x == '<' && y == '>'));
}
bool parseCode(const string& code) {
	Stack<char> parentheses;
	int* arr = new int[code.length()];
	//Intilaize the dynamic array with Zeros
	for (int i = 0; i < code.length(); i++)
		arr[i] = 0;
	int count = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);

	bool correctCode = true;
	char x;
	for (int i = 0; i < code.length(); i++) {

		if (i + 1 < code.length() && code.substr(i, 2) == "<<")
		{
			i++;
		}
		else if (isOpeningParenthesis(code[i])) {
			parentheses.Push(code[i]);
			arr[count] = i;
			count++;
		}
		else if (isClosingParenthesis(code[i]))
		{
			//parentheses.Peek(x);
			parentheses.Pop(x);
			if (!matchingParentheses(x, code[i]))
			{
				string y;
				int j = 0;
				SetConsoleTextAttribute(hConsole, 7);
				cout << "Closing parenthesis not matched. " << endl;
				//Printing the code before the opening parenthesis
				cout << code.substr(0, arr[count - 1])<<endl;

				//Printing the opening parenthesis
				SetConsoleTextAttribute(hConsole, 1);
				cout << code[arr[count - 1]];

				//Printing the code between the opening and the closing parenthesis
				SetConsoleTextAttribute(hConsole, 7);
				cout << code.substr(arr[count - 1] + 1, i - arr[count - 1] - 1);

				//Printing the closing parenthesis
				SetConsoleTextAttribute(hConsole, 1);
				cout << code[i] << endl;

				//Printing the rest of the code
				SetConsoleTextAttribute(hConsole, 7);
				cout << code.substr(i + 1)<< endl;

				correctCode = false;
				break;
			}
		}
	}
	delete []arr;
	if (!parentheses.isEmpty())
	{
		cout << "Opening Parenthesis are not matched" << endl;
	}
	return correctCode;
}

int main() {

	string testCode[2] = { 
"#include <iostream> \n\
using namespace std; \n\
int main(){ \n\
cout<<""Hello World""; \n\
return 0; \n\
}" 
,

"#include <iostream> \n\
using namespace std; \n\
int main(]{ \n\
cout<<""Hello World""; \n\
return 0; \n\
}"

};

	if (parseCode(testCode[0]))
		cout << "The code is Correct" << endl << endl;

	if(parseCode(testCode[1]))
		cout << "The code is Correct" << endl;

	/*Stack<int> stack;
	int data;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);

	stack.Print();

	stack.Pop(data);

	stack.Print();

	stack.Peek(data);

	cout << data << endl;

	stack.Print();*/
}