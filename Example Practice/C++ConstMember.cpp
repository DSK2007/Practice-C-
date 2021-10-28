#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;
// const 멤버와 객체
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 9주차
// const 변수: 자료형 앞에 const 키워드를 써서 선언한다. 변수에 상수(Constant) 의미를 부여해 그 내용을 변경할 수 없게 한다.
// 보통은 const는 변수에 쓰이고, 함수 선언에서도 매개 변수나, 리턴형에 쓰이기도 한다. 그런데 이 const를 함수 선언 뒤에 붙여 const 함수를 만들 수 있다.
// 그리고 이런 const 함수와 const 변수는 클래스 내부에서도 약간 독특한 특징을 가진다. 이를 통틀어 const 멤버와 객체라고 부르며 이에 대해 알아보자.

// 클래스 내부에서의 const
class Person {
private:
	int age;
	string name;
public:
	// const 멤버 함수는 함수 선언 뒤[ 리턴형 함수이름() 뒤 ] const 키워드를 써서 만들 수 있다.
	// const 멤버 함수는 약 조건 3가지가 충족되어야 한다.
	// 1. 멤버 변수를 변경해서는 안된다.
	// 2. 다른 함수를 호출 할 때, 그 함수 또한 const 함수여야 한다. 그렇지 않은 함수를 호출하면 안된다.
	// 3. 생성자/소멸자와 같은 특수 함수는 제외된다.
	// const 멤버 함수가 되기 적합한 함수는 어떠한 멤버 변수도 바꾸지 않는 함수이다. (get이 들어가는 접근자 등)
	// const 함수로 만들어서 얻는 이점은 오류를 더 쉽게 검출할 수 있다는 것이다.
	Person() { age = 20; name = "홍길동"; job = "기자"; cout << "사람 1명이 데이터베이스에 등록되었습니다." << endl; }
	~Person() { cout << "사람 1명의 정보를 데이터베이스에서 제거했습니다." << endl; }
	void setAge(int a) { age = a; }
	int getAge() const { return this->age; }
	void setName(string a) { name = a; }
	string getName() const { return this->name; }
	void Watch(string obj) const { cout << this->name << "은 " << obj << "를(을) 유심히 쳐다보며 관찰하고 있습니다." << endl; }
	int Calculate(int n1, char op, int n2) const;
	string job;
};

int main()
{


	const int x = 3; // const 변수는 상수 식이 들어간 초기화를 선언 시 필요로 하고, 내용을 변경하지 못한다는 점을 제외하면 보통 변수와 다를 게 없다.
	constexpr int y = 5; // C++11에서 추가된 constexpr 변수는 const와 기능은 유사하다. 
	// 대신, 초기화 기준이 더 강화되어 기존의 실행 때 검사을 뛰어넘어 컴파일 과정에서 검사를 진행해 그 초기화가 상수식인지 검사해 오류 검출성을 높였으나 속도가 느리다는 점이 있다.
	const Person P1; // const 객체는 기존 const 변수와 같이 선언한다. 대신 특별한 특징이 있다.
	// 1. 기존 const 변수의 특징을 받아 생성자에서의 초기화를 제외하고는 모든 멤버 변수는 그 값이 변경될 수 없다. 이는 public 멤버 변수에 접근해 main 함수 내에서 바꾸려는 것도 포함된다.
	// 2. const 객체는 const 함수가 아닌 함수는 호출할 수 없다. public이면서 const 변수가 아닌 변수는 접근해 값을 참조할 수 있으나, 변경은 불가한다.
	cout << P1.getName() << "은 흥미로운 개체를 발견했습니다." << endl;
	P1.Watch("개체");
	cout << "그런데 개체에는, 숨겨진 수식이 새겨져 있었습니다." << endl;
	cout << P1.getName() << "은(는) 그 수식을 계산해보려 했습니다." << endl;
	cout << "205563+819203=" << P1.Calculate(205563, '+', 819203) << endl;
	cout << P1.getName() << "은(는) 수식을 풀고는 만족해 돌아갔습니다." << endl;
	return 0;
}

int Person::Calculate (int n1, char op, int n2) const
{
	switch (op)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '/':
		return n1 / n2;
	case '*':
		return n1 * n2;
	default:
		cout << this->name << "은(는) 주어진 수식을 잘 이해하지 못했습니다." << endl;
		return 0;
	}
}
