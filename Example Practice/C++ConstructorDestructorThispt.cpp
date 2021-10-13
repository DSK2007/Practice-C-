#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stod;
using std::stoi;

// 생성자와 소멸자 / this 포인터
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 7주차
// 객체는 언제나 선언되어 생성될 때 생성자를 호출하며, 소멸할 때(delete 함수로 코드 중간에 소멸, 혹은 프로그램 종료 시 소멸) 소멸자를 호출한다.
// 생성자와 소멸자는 클래스 내부에서 함수로 선언되지 않아도 Bear(){}와 같이 암시적으로(Implicity) 만들어지지만, 기본 생성자와 소멸자는 아무런 변화를 주지 않는다.
// 생성될 때 기본적으로 값을 넣게 하고 싶거나 소멸될 때 알림을 알리는 등 유용하게 사용하고자 하면 가시적으로 클래스 내부에서 선언, 정의할 수 있다.

class Bear {
private: 
	string name;
	double weight;
	int age;
	int num = 0; // int num은 곰 클래스의 객체 수를 알려주는 변수로, 생성자와 소멸자에 의해서만 그 수가 조절될 것이다.
public:
	Bear(string a, double b, int c) : name(a), weight(b), age(c) { num++;  cout << "곰 1마리가 생성되었습니다. 현재 곰은 " << this->num << "마리 입니다." << endl; }
	// 생성자는 클래스이름(매개변수) {함수 정의}와 같이 선언 및 정의할 수 있다. 생성자는 클래스의 초기화를 담당한다.
	// 다른 정의 방법은 클래스이름():매개변수(값){}, 클래스이름():매개변수:{값}{}이 있다.
	// 정의 방법 예시: Bear(){}, Bear():age(1){}, Bear():age{1}{}
	// 이런 정의 방법에 다른 이유는 변수의 초기화 방법이 C++에서 추가되었기 때문이다.
	// 기존의 x=1;은 복사 초기화(Copy initialization), x(2);는 직접 초기화(direct initialization), x{3}은 유니폼 초기화(Uniform initialization)이라고 한다.
	// 뒤의 둘은 C++에서 추가된 문법으로, 직접/유니폼 초기화는 대입과 초기화를 구분할 수 있고, 성능 향상을 기대할 수 있다는 점에서 유용하다.
	// 특히 유니폼 초기화{는 배열과 같이 변수의 초기화를 리스트(initializer_list)로 여러 개로 할 수 있어 생성자와 같이 기능하게 할 수 있다.

	// 일반 자료형은 컴파일러의 처리로 자동적으로 할 수 있지만, 클래스는 사용자 정의형이므로 그 초기화를 처리하기 어렵다.
	// 그래서 미리 변수 값이 초기화되어 있지 않는 한, 쓰레기 값이 멤버 변수에 들어가게 된다.
	// 멤버 변수에 미리 값을 지정하는 방법도 있지만, 생성자에서 값을 초기화하게 한다면 그러한 처리가 필요 없다.
	// 생성자는 그래서 특히 멤버 변수의 초기화를 담당한다.

	// 생성자는 객체가 생성될 때 자동으로 호출되고, 사용자가 임의로 호출할 수 없다. 리턴형이 생략되며, 아예 리턴형이 없는 것으로 친다.
	// 생성자는 초기화되는 값이 달라질 수 있으므로, 여러 개 존재할 수 있으며, 대신 생성자의 매개 변수가 중복되어선 안된다.
	// 나중에 나올 new와 delete을 통해 동적으로 클래스를 운용할 때도 생성자와 소멸자가 있으면 객체가 더 잘 표현되게 할 수 있다.
	// 동적으로 운용하지 않을 때도 메모리를 초기화한다는 점에 의의를 두고 만들어 두는 것이 좋다.

	~Bear();
	// 소멸자는 ~클래스이름(매개변수) {함수 정의}와 같이 선언 및 정의할 수 있다. 소멸자는 객체가 소멸할 때 호출된다.
	// 객체는 임의적으로 삭제되지 않는 한 프로그램의 종료 시 소멸하며 그 때 소멸자가 호출된다.
	// 그러나 new, delete에서 동적으로 운용할 시 소멸자에서 객체를 delete하면 그 객체가 차지하던 메모리가 스스로 비어진다.
	// 이렇게 생성자로 인스턴스가 스스로 그 값을 초기화하게 하고, 소멸자로 소멸할 때 스스로 메모리도 정리하게 할 수 있게 해준다.
	void setV(string ind, string st);
	string getName() { return this->name; }
	double getWeight() { return this->weight; }
	int getAge() { return this->age; }
	// this 포인터는 자동적으로 시스템이 생성하는 멤버가 호출될 때, 그 멤버가 속한 객체를 가리키는 const형 포인터이다. 즉, 객체의 주소를 가리킨다.
	// 포인터 객체의 멤버 호출과 같이 this->멤버이름과 같이 접근할 수 있고, return *this와 같이 표현해 객체 자기자신을 반환할 수도 있다.
	// 멤버 함수에서 this 포인터는 어떤 객체가 자신을 호출했는 지 알고자 하는 경우 사용한다.
	// 객체에서 멤버 변수는 객체마다 따로 만들어지지만, 멤버 함수는 공유하기 때문에, 호출 시 자신이 어떤 객체에 있는지 알기 위해서이다.
	// this 포인터는 명시적으로 표기되어 있지 않아도, 밑의 예시와 같이 클래스에서 멤버 함수를 호출하면 객체의 주소를 this 포인터에 넣고 멤버를 호출한다.
	// this 포인터는 연산자 중첩(operator overloading)에서 사용된다. 일반 자료형과 달리 정의되지 않은 클래스 사이의 연산자(+, - 등)를 통한 연산에 관련된 문제를 해결한다.
	// 클래스가 자기 자신을 다른 클래스에 매개 변수로 넘길 때 사용되기도 한다.

};
int main()
{
	Bear BR("반다리", 123.4, 6), *pBR; // 포인터 객체는 생성자와 소멸자가 적용되지 않는다.
	pBR = &BR;
	BR.setV("name", "반다리");
	BR.setV("weight", "123.4");
	BR.setV("age", "6");
	pBR->setV("age", "5");
	cout << "이름: " << BR.getName() << ", 나이: " << BR.getAge() << "살, 몸무게: " << BR.getWeight() << "kg" << endl;
	cout << "이름: " << pBR->getName() << ", 나이: " << pBR->getAge() << "살, 몸무게: " << pBR->getWeight() << "kg" << endl;
	return 0;
}

void Bear::setV(string ind, string st) {
	if (ind == "name") { this->name = st; } 
	else if (ind == "weight") { this->weight = stod(st); }
	else if (ind == "age") { this->age = stoi(st); }
}

Bear::~Bear() { num--; cout << "곰 1마리가 소멸되었습니다. 현재 곰은 " << this->num << "마리 입니다." << endl; }
