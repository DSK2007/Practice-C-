#include <iostream>
#include <string> // string은 std::string을 사용하기 위해 포함되었다.
using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef struct Tes {
	int age;
	int num;
}Tes;
// 클래스는 C에서 사용한 구조체와 유사한, 더 발전한 것으로, 구조체는 변수의 모임이라 하면 클래스는 변수와 함수의 모임이라고 볼 수 있다.
// 클래스 내에 있는 변수와 함수를 멤버라고 하며, 이들은 멤버 변수, 멤버 함수라고도 불린다.
// 보통 배열보다도 구조체 배열이 main 함수 내에서 더 적은 변수를 선언해도 해결 가능하듯이, 클래스도 변수와 함수를 미리 입력해둬서 main 함수 내에서는 코드의 길이를 단축시킬 수 있다.
// 멤버 함수는 멤버 변수에 접근이 가능하며, 이를 통해 다양한 요소들이 클래스 내에서 상호 작용할 수 있게 만들 수 있다.
// 클래스 내 정보를 입력하는 것과 클래스가 저장해놓았던 정보를 출력하는 것, 그리고 그를 변화시키는 것과 같은 일 등등을 함수(모듈, 기능)로 구현할 수 있다.

// 클래스는 기본적으로 함수와 변수들을 '형식 지정자'(Access Specifiers)로 구분을 하며, 형식 지정자에 따라 그에 접근할 수 있는 사용자가 결정된다.
// private은 해당 클래스 내부에서만 접근이 가능한 비공개 양식이다. 주로 공개할 필요가 없는 멤버 변수가 이 곳에서 선언된다.
// public은 해당 클래스 밖, main 함수에서도 접근이 가능한 공개 양식이다. 기능을 사용하기 위해서는 당연히 공개가 되어야 하기 때문에 멤버 함수가 주로 이 곳에서 선언된다.
// protected는 private보다 낮은 보안을 지닌 양식으로, main 함수 내에서는 접근이 불가하지만, 다른 클래스와 해당 클래스와 상속 관계면 그 다른 클래스 내부에서도 접근이 가능하다.
class Test {
private:
	// private 형식 내에서 멤버 변수를 주로 선언한다. 기존의 숫자를 저장하는 int, double, 문자열의 char 배열( std::string도 같은 역할을 한다.), 구조체 까지 포함해 쓸 수 있다.
	// 구조체처럼 클래스 내의 멤버 변수도 초기화를 하는 것을 권장한다.
	int num = 25;
	double num2 = 10.2;
	char str[10] = "테스트";
	string str2;
	Tes t = { 0, 0 };;
public:
	// public 형식을 가진 변수/함수 만이 main 함수 내에서 사용이 가능하다. 그렇기에 멤버 함수는 public 형식 내에서 작성되어야 할 것이다.
	Tes tt = { 0, 0 };;
	int getnum()
	{
		return num;
	}
	double makenum2()
	{
		num2 = (double)num / 2;
		return num2;
	}
	void enterstr()
	{
		cout << "문자열 입력: ";
		cin >> str;
		cout << str << endl;
	}
	void producestr2(string strin)
	{
		// std::string은 C++에서 생긴 함수로, char 배열과 달리 문자열의 길이를 지정해주지 않아도 되며, insert나 replace 등 기능으로 문자열을 더 쉽게 관리할 수 있다.
		str2 = "테스트";
		str2.insert(str2.length(), strin); // 문자열 끝에 한 칸 띄어쓰고 매개 변수로 받았던 문자열을 집어넣는다.
		cout << str2 << endl;
	}
	void arrangeStruct(int a, int b)
	{
		t.age = a;
		t.num = b;
		tt = t;
	}
};

int main()
{
	Test t;
	cout << t.getnum() << endl;
	cout << t.makenum2() << endl;
	t.enterstr();
	t.producestr2("계정");
	t.arrangeStruct(20, 2);
	// cout << t.age << t.num; // private 변수이기에 main 함수 내에서 접근할 수 없다.
	cout << t.tt.age << " " << t.tt.num << endl; // 그러나 arrangeStruct에서 private 구조체 t에서 public 구조체 tt로 값을 복사하는데, 이는 접근이 가능해 출력이 된다.
	return 0;
}
// 실행 결과 (예시)
//25
//12.5
//문자열 입력 : abc
//abc
//테스트계정
//20 2
