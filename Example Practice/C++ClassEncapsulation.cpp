#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stod;
using std::stoi;
// 객체와 멤버 호출
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 7주차
// 객체는 멤버의 접근 지정자의 존재로 사용자에게 멤버에 대한 접근을 제한/허용함으로서 객체의 캡슐화(Encapsulation)을 이룰 수 있다.
// 캡슐화란, 접근 지정자를 통해 건드리지 말아야 할 멤버는 접근을 제한하고, 그에 대한 간접적 접근 방식을 제공함으로서 에러 발생율을 낮추며, 설계된 목적대로 사용되도록 할 수 있다.
// 예를 들어, Bear 클래스는 직접적으로 사용자가 곰의 정보인 name, weight, age를 접근해서 바꾸기 보다 setV를 통해 간접적으로 이를 입력할 수 있게 한다.
// 이는 만약에 Bear 클래스가 다른 코드 내에서 사용되거나 동적으로 할당되는 등 더 많은 기능과 역할을 요구로 할 때 약간의 수정으로도 기능할 수 있도록 시간을 절약할 수 있다.
// 하나의 프로그램을 패키지(Package) 형태로 포장한 뒤 다른 운영체제에서도 사용할 수 있도록 호환하는 것과 같이 클래스 또한 캡슐화를 통해서 그 안정성과 호환성을 높일 수 있다.

class Bear {
private: // 캡슐화가 진행된 클래스의 멤버 변수들은 주로 private 속성을 지니게 되며, 
	// 이는 멤버 함수가 변수에 접근해서 사용할 뿐, 직접적으로 사용자가 멤버 변수에 접근해 값을 참조할 필요가 없기 때문이다.
	// 중요한 점은, private 속성으로 보호된 멤버 변수가 일단 있다면 그에 간접적으로 접근할 public 속성의 멤버 함수가 필요하다는 점이다.
	// 그렇지 않으면 사용자는 접근할 수 없는 멤버 변수를 활용할 수가 없으며, 직/간접적 모든 방면에서 접근 방식이 없는 멤버 변수는 기능을 제대로 할 수 없다.
	string name = "곰";
	double weight = 100.0;
	int age = 3;
public:
	// 캡슐화가 진행된 클래스의 멤버 함수는 public 속성으로 사용자가 이들을 접근함으로서 대부분의 멤버 변수를 입력/참조/출력할 수 있게 해주며,
	// 사용자에게 필요한 기능만을 제공할 수 있게 함으로 클래스가 의도된 목적대로 기능할 수 있게 한다.
	// 클래스 내 멤버 함수는 멤버 변수의 이름을 언급함으로서 언제나 그 값을 사용하고 참조할 수 있기에, 캡슐화가 진행되더라도 접근에 대한 지장은 없다.
	void setV(string ind, string st);
	string getName() { return this->name; } // 또한 멤버 함수는 this 포인터를 사용해 전역 변수나 지역 변수와의 충돌을 피하고 이 클래스의 멤버 변수에 접근할 수 있다.
	double getWeight() { return this->weight; } // 클래스 내 정의된 함수는 자동적으로 inline 함수가 되는데, 이는 호출 횟수가 적고 길이가 적은 코드에 적합하다.
	int getAge() { return this->age; } // 위의 조건에 맞춰 긴 함수는 따로 밑에 정의해 호출하고, 짧고 호출 횟수가 적을 함수는 클래스 내에 정리해 빠르게 사용할 수 있게 할 수 있다.

};
int main()
{
	Bear BR, ListBR[5], *pBR; // 객체 또한 포인터 객체와 객체 배열이 존재하며, 이는 기존의 포인터 변수와 변수 배열과 기능이 일치한다.
	pBR = &BR; // 포인터 객체는 객체의 주소를 입력함으로서 지정된 객체의 공개된 변수와 함수에 접근할 수 있다.
	BR.setV("name", "반다리");
	BR.setV("weight", "123.4");
	BR.setV("age", "6");
	pBR->setV("age", "5"); // 포인터 객체가 실행하는 함수 또한 역시 본래 포인터 객체가 가리키는 객체의 변수/함수에 접근해 값을 입력/참조할 수 있다.
	cout << "이름: " << BR.getName() << ", 나이: " << BR.getAge() << "살, 몸무게: " << BR.getWeight() << "kg" << endl; // 기존 객체는 "."를 객체 이름과 변수/함수 이름 사이에 넣어 호출한다.
	cout << "이름: " << pBR->getName() << ", 나이: " << pBR->getAge() << "살, 몸무게: " << pBR->getWeight() << "kg" << endl; // 포인터 객체는 "->"를 객체 이름과 변수/함수 이름 사이에 넣어 호출한다.
	ListBR[1].setV("name", "메이저"); // 객체 배열은 객체 이름 뒤에 인덱스([순서 숫자])을 입력함으로서 멤버를 호출할 수 있다.
	pBR = ListBR; // 포인터 변수와 변수 배열처럼, 객체 배열의 이름이 포인터 객체에 들어가는 경우 가리키는 객체는 배열의 시작 주소, 즉 예제로 치면 ListBR[0]을 가리킨다.'
	pBR->setV("name", "강철");
	cout << "이름: " << pBR->getName() << endl;
	cout << "이름: " << ListBR[0].getName() << endl;
	return 0;
}

void Bear::setV(string ind, string st) {
	if (ind == "name") { this->name = st; } 
	else if (ind == "weight") { this->weight = stod(st); }
	else if (ind == "age") { this->age = stoi(st); }
