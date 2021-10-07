#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int stt = 6;
// 함수와 클래스의 멤버 함수
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 6주차
// C++의 클래스 내에서 선언하는 멤버 함수와 C에서 사용하던 사용자 정의 함수는 선언, 정의, 호출하는 데 별로 차이점이 없다.
// 클래스와 구조체의 유사성, 클래스에서 도입된 멤버 변수 기능과 관련해 그 둘 간의 차이점을 알아보자.
class AllAround {
private:
	int val = 20;
public:
	// 멤버 함수는 public 속성의 접근 권한을 지녀야 클래스 밖에서, 예를 들어 클래스 밖인 main 함수 내와 같은 곳에서 호출할 수 있다.
	// private은 비공개, public은 공개, protected는 일부 공개(이 클래스에서 파생되는 자식 클래스만)되는 개념으로 보면 된다.
	// 이 접근 권한 지정자 중 오직 public만 클래스의 멤버 함수를 main 함수 내에서 사용하게 해준다. 그러므로 멤버 변수는 public에서 선언되어야 한다.
	// 또한 클래스 외부에서의 멤버 함수의 정의는 네임스페이스(std::string과 같이)가 변수 이름 앞에 들어가야 한다. 자료형 클래스이름::변수이름(void AllAround:Display)과 같은 식으로 정의한다.
	// 네임스페이스란 범위 지정 연산자 "::"가 중간에 들어가는, 모든 식별자가 유일하도록 보장하는 코드 영역을 정의하는 것을 의미한다.
	// 우리가 잘 쓰게 될 cout, cin도 std라는 네임스페이스로 그 영역이 정의되며, 이를 생략하기 위해서는 using namespace std나 using std::cout, using std::cin 등 따로 표현을 해주어야 한다.
	// 네임스페이스로 클래스의 코드 영역은 클래스이름::(AllAround::)과 같이 적용할 수 있다.
	void display(string st); // 클래스 내부에서의 멤버 함수 정의는 네임스페이스를 필요로 하지 않는다.
	void show_double_number(int x);
	int give_double_number(int x);
	int add(int x, int y);
	char vending_1(int x);
	const char* vending_2(int x);
	// string 함수 라이브러리에 들어간 std::string를 사용해서 문자열을 출력할 수도 있다.
    // string 클래스를 지닌 변수는 기존 char 문자열과 차이점이 있다.
    // 1. 끝에 공백(\0)이 들어가지 않는다.
    // 2. 클래스이므로 string.size()와 같이 이미 만들어진 클래스 멤버 함수의 기능을 사용할 수 있어 편리하다.
    // 특히 string.size()는 문자열 길이를 반환하며, string.replace()와 같이 문자열 중간에 글자를 바꾸는 등 문자열을 더 유연하게 처리할 수 있다.
    // C++의 클래스로 새로 만들어진 함수로, #include <string>으로 포함시키면 이 클래스를 사용할 수 있다.
	string vending_3(int x);
	void confirm();
};

int main()
{
	AllAround M;
	M.display("안녕"); // main 내에서 클래스 멤버 함수 호출은 C에서 구조체 멤버를 찾을 때와 같이 [클래스변수이름.멤버함수이름(매개변수)]와 같은 형식으로 써야 한다.
	M.show_double_number(3); // 다른 함수 호출과 같이 매개 변수의 자료형이 void형이면 생략할 수 있다.
	cout << M.give_double_number(3) << endl;
	cout << M.add(2, 3) << endl;
	cout << M.vending_1(1) << endl;
	cout << M.vending_2(1) << endl;
	cout << M.vending_3(1) << endl;
	M.display("이와 같이 클래스의 멤버 함수는 기존 C의 함수와 같이 선언, 정의, 호출함으로서 사용할 수 있다.");
	M.confirm();
	return 0;
}
// 실행 결과 (예시)
//안녕
//6
//6
//5
//A
//커피
//커피
//이와 같이 클래스의 멤버 함수는 기존 C의 함수와 같이 선언, 정의, 호출함으로서 사용할 수 있다.
void AllAround::display(string st)
{
	cout << st << endl;
}
void AllAround::show_double_number(int x)
{
	cout << x * 2 << endl;
}
int AllAround::give_double_number(int x)
{
	return x * 2;
}
int AllAround::add(int x, int y)
{
	return x + y;
}
char AllAround::vending_1(int x)
{
	if (x == 1) { return 'A'; }
	else return 'B';
}
const char* AllAround::vending_2(int x)
{
	if (x == 1) { return "커피"; }
	else return "유자차";
}
string AllAround::vending_3(int x)
{
	if (x == 1) { return "커피"; }
	else return "유자차";
}

void AllAround::confirm()
{
	int val = 10; // 클래스의 멤버 함수 내에 멤버 변수와 같은 이름의 지역 변수가 선언되면, 그 함수가 우선시되어 클래스 멤버 변수를 참조할 수가 없게 된다.
	// 이를 구분하기 위해서는 네임스페이스를 이용해 지역의 위치를 표기해줌으로서 컴파일러에게 어느 변수를 원하는지 알려줄 수 있다.
	int val2 = AllAround::val; // 클래스 멤버 함수 내에 멤버 변수와 똑같은 지역 변수가 있다면, [클래스이름::변수이름]과 같이 네임스페이스를 입력해 구분할 수 있다.
	int val3 = ::stt; // 전역 변수를 언급하는 경우, 네임스페이스에 공백을 두고 범위 지정 연산자 "::"만 입력해 [::변수이름]과 같이 사용할 수 있다.
	cout << "여러 val 변수 중 클래스 내 멤버 변수 val의 값은 " << val2 << "입니다." << endl;
}
