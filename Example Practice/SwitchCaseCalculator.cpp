#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::cin;
int main(void)
{
	char op;
	int num1, num2;
	for (;;)
	{
		cout << "사칙연산만 가능합니다." << endl;
		cout << "끝내려면 0+0을 입력하세요" << endl;
		cout << "계산하려는 수식(예:10+20)을 입력하세요:";
		cin >> num1 >> op >> num2;

		if (num1 == 0 && num2 == 0 && op == '+') { break; }
		switch (op)
		{
		case '+':
			cout << "덧셈 결과는 " << num1 + num2 << "입니다." << endl;
			break;
		case '-':
			cout << "뺄셈 결과는 " << num1 - num2 << "입니다." << endl;
			break;
		case '*':
			cout << "곱셈 결과는 " << num1 * num2 << "입니다." << endl;
			break;
		case '/':
			cout << fixed;
			cout << "나눗셈 결과는 " << (double)num1 / (double)num2 << "입니다." << endl;
			break;
		default:
			cout << "다시 입력하세요." << endl;
			break;
		}
	}
	return 0;
}
// 실행 결과
// 기존의 계산기가 0+0을 제외한 수식을 주는 한 이어진다.
// 끝내는 수식은 무조건 0+0이여야 하며, 0-0과 같이 수만 보는 게 아닌 기호 +도 조건에 포함했다.
