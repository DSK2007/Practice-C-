#include <iostream>
using std::cout;
using std::endl;
// Template 함수와 클래스를 통한 보편적인(Generic) 프로그래밍
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 14주차
// Template은 상속과 같이 프로그래밍 내에서 다형성을 이룰 수 있는 방법 중 하나이다.
// Template은 클래스나 함수처럼 규격을 만드나 자료형을 수식의 미지수처럼 취급하여 일반화된 규격을 만들 수 있다.
// template <class T>와 같이 미지의 자료형 갯수를 정한다. 함수의 매개 변수처럼 들어간 자료형(클래스, 기본 자료형, 구조체 등 타입)이 그 자리에 들어간다.
// 함수의 경우 정의할 때만 template을 사용해 호출할 때는 정의한 내용대로 자료형을 고려해 매개 변수를 넣어주면 된다.
// 클래스의 경우 정의한 뒤에도 객체를 생성하기 위해서는 클래스이름<> 객체이름과 같은 식으로 선언한 뒤, <>안에 미지수의 개수 만큼 사용할 자료형 이름을 넣어준다.
// 함수 중첩과 비교하면 인자의 수가 다르거나 각각의 정의가 다른 경우에서는 어렵지만,
// 오직 정해진 갯수의 자료형 내에서, 자료형만 다른 함수 여러 개가 필요할 경우 극한의 효율을 낼 수 있다.

template <class T> void Swap(T &x, T &y) // template <class 자료형이름> 리턴형 함수이름(매개 변수 리스트)와 같은 형식으로 선언한다. 매개 변수 리스트에서 template에서 선언했던 자료형 이름을 타입으로 쓸 수 있다.
{
	// 이 Template 함수의 경우, 잘 알려진 두 변수의 값을 바꾸는 방법의 함수이지만,
	// Template으로 쓰인 이상, 두 함수의 자료형이 같기만 한다면 여러 자료형의 변수 2개의 값을 바꾸는 작업을 실행할 수 있다.
	// int, char, double... 등 기본 자료형의 변수를 기본적으로 바꿀 수 있다.
	// 단, 함수 정의를 이 상태에서 더 바꿀 수 없다는 것이 단점이다.
	// 함수 중첩의 경우, 인자의 자료형도 다르지만, 그 받은 것들을 다루는 과정인 정의 부분도 조금씩 다르다면 함수 중첩이 더 좋은 방법일 수도 있다.
	// 가령, main 함수에서 그냥 객체 a,b 안의 변수 x를 넘기는 게 아닌 객체 a,b 자체를 넘겨버릴 경우, 실행해버리면 그 안에 있던 y 또한 휘말릴 수 있기에 원치 않은 결과를 가져올 수 있다.
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <class T> void Before_After(T &x, T &y)
{
	cout << x << ", " << y << endl;
	Swap(x, y);
	cout << x << ", " << y << endl;
}

template <class T> class Sample
{
	T S1;
public:
	Sample(T i) : S1(i) {}
	T getS1() { return S1; }
};

int main()
{
	int i1 = 2, i2 = 1;
	double d1 = 7.5, d2 = 3.6;
	char c1 = 'B', c2 = 'A';
	Before_After(i1, i2);
	Before_After(d1, d2);
	Before_After(c1, c2);
	cout << i1 << ", " << i2 << ", " << d1 << ", " << d2 << ", " << c1 << ", " << c2 << endl;
	Sample <int> in1(i1); // 클래스에 경우, 객체로 만들 때는 앞에 template <class T>를 썼듯이 템플릿클래스이름 <사용할자료형이름>으로 선언한다.
	cout << in1.getS1() << endl;
	Sample <double> do1(d1); // 사용할 자료형이 여러 개일 경우, 상속의 경우처럼 쉼표(',')로 사이를 구분한다.
	cout << do1.getS1() << endl;
	Sample <char> ca1(c1);
	cout << ca1.getS1() << endl;
	return 0;
}
// 실행 결과
//2, 1
//1, 2
//7.5, 3.6
//3.6, 7.5
//B, A
//A, B
//1, 2, 3.6, 7.5, A, B
//1
//3.6
//A
