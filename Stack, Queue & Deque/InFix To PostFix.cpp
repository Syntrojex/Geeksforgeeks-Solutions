#include<iostream>
#include<stack>
#include<string>

using namespace std;

int precedence(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}

	if (ch == '*' || ch == '/' || ch == '%')
	{
		return 2;
	}

	return 0;
}

string convertToPostfix(string input)
{
	string output = "";
	stack<char> st;

	for (char ch : input)
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		{
			output += ch;
		}

		else if (ch == '(')
		{
			st.push(ch);
		}

		else if (ch == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				output += st.top();
				st.pop();
			}

			if (!st.empty() && st.top() == '(')
			{
				st.pop();
			}
		}

		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		{
			while (!st.empty() && precedence(st.top()) >= precedence(ch))
			{
				output += st.top();
				st.pop();
			}

			st.push(ch);
		}
	}

	while (!st.empty())
	{
		output += st.top();
		st.pop();
	}

	return output;
}

int main()
{
	string input;
	cin >> input;

	cout << convertToPostfix(input);

	return 0;
}
