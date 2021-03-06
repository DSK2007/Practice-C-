#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// 클래스 맴버의 접근 권한
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 6주차
// C++의 클래스와 C의 구조체의 차이는 클래스는 멤버로 함수를 넣을 수 있다는 점이 크지만,
// 또 다른 차이점을 찾아보자면 멤버에 접근 권한을 지정할 수 있다는 점이다.
class Integer {
	// C++의 접근 권한은 [속성 이름:] 과 같이 입력하고 엔터로 줄을 변경해 밑에 변수/함수를 입력함으로서 지정할 수 있다.
private: // private 속성의 멤버는 해당 클래스 내에서만 접근 가능하다.
	// private 속성 멤버는 앞에 배운 기억 클래스 static과 같이 이 지역(클래스 내부)에서 접근해 값을 대입, 참조하는 게 되고, 변화된 값 또한 저장한다.
	// 이 클래스의 멤버 함수 내에서도 같은 이름을 지닌 지역 변수가 선언되지 않는 한, 이 변수를 가리키는 것으로 컴파일러에서 지정한다.
	int val = 0; // 기본적으로 클래스 내에서 접근 지정자가 없는 변수/함수는 private 속성으로 취급된다.
	// 주로 멤버 변수에게 부여되는 속성이다. 클래스 변수에 구태여 따로 코드를 다시 쳐 변수를 대입해 사용하는 것보다,
	// 멤버 함수 내에서 멤버 변수를 따로 접근해 사용한다면 더 편하고 간결하게 표현할 수 있기 때문이다.
public: // public 속성의 멤버는 어디에서든 접근이 가능하다.
	// 주로 멤버 함수에서 부여되는 속성이다. main 함수 내에서 호출함으로서 하나의 기능을 실현할 수 있다.
	int getval()
	{
		return val; // Integer 클래스 내에서 직접적으로 val을 언급해 출력할 수 없지만, 이 함수를 이용해 값만 리턴하면 값의 참조가 가능하다.
	}
	void showval()
	{
		cout << val << endl;
	}
	void setval(int ii)
	{
		val = ii; // val의 값을 변경하는데 접근이 불가한 것을 멤버 함수의 매개 변수에 값을 입력해 대입하는 식으로 운반하면 가능하다.
	}
	void enterval()
	{
		cin >> val; // 또한 private 변수인 val에 직접적으로 값을 입력할 수 없지만, 멤버 함수를 통한 입력은 제대로 기능한다.
	}
// protect 속성도 존재하는데, private 속성의 특성을 지니나, 상속 관계 사이의 클래스(자식 클래스)는 접근 권한이 허용되는 속성이다.
};
typedef struct number {
private: // C++에서 쓰인 구조체도 멤버 변수에 접근 권한을 설정할 수 있다.
	int val1 = 1; // 하지만 접근 권한을 지정해봐도 멤버 함수와 같이 접근 권한이 제한된 변수를 객체 밖에서 사용할 방법이 없기에, 클래스를 사용하는 것이 좋다.
	// 만약에 값을 미리 대입하고 main 함수 내에서 출력만 하는 용도로 쓰려하면 어떻게 될까? 그것 또한 불가하다.
public:
	int val2 = 0; // 기본적으로 구조체 내의 멤버 변수는 public 값을 지닌다. C++내에서 접근 권한이 지정되지 않는 모든 구조체 내 변수도 public 속성을 가진다.
}N;

int main()
{
	number N;
	N.val2 = 3;
	Integer I;
	// N.val1 = 1; // val1은 private 변수로 접근이 제한되어 main 내에서 대입할 수 없다.
	// cout << N.val1; // 이렇게 출력하는 행위 또한 접근이 제한되어 main 내에서 출력도 할 수 없다.
	I.enterval(); // 사용자에게 cin 함수로 값을 입력하게 해주고, 사용자가 입력한 값을 받아 val에 저장하는 기능
	I.showval(); // val에 저장되어 있던 값을 출력하는 기능
	I.setval(1); // 사용자가 매개 변수에 입력한 값을 받아 val에 저장하는 기능
	cout << I.getval() << endl; // cout 함수에 getval() 함수를 통해 클래스 내 val의 값을 리턴값으로 받아 참조해 출력할 수 있다.

	return 0;
}
// 실행 결과 (예시)
// 2 // I.enterval에서 2를 입력
// 2 // I.showval에서 val의 값 출력
// 1 // I.setval에서 다시 val의 값이 1이 된 후, cout로 I.getval 함수로 val의 값을 참조해 출력한 값
