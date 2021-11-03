#include <iostream>
using std::cout;
using std::endl;
// 디폴트 인자/매개 변수 ( Default Parameter(매개 변수), Default Argument(인자) )
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 10주차
// 함수 중첩의 축약형으로, C++에서 함수 선언 시 매개 변수에 int i=1과 같이 초기 값을 설정할 수 있다.
// 함수를 호출시 별도의 매개 변수를 전달하지 않아도 기본적인 값을 전달하도록 함수 원형을 선언할 때 초기 값(default parameter, 디폴트 인자)를 지정하는 것이다.
// 만약에 함수에 초기 값이 있을 경우, 그 만큼 매개 변수의 호출 때 요구 조건이 약화되어, 모든 매개 변수가 초기 값이 있는 경우에는 매개 변수 없이 호출해도 정상적으로 실행된다.
// 위의 특성을 통해, add(int i = 1, int j =2)라는 함수는 곧 add(), add(3), add(3, 4) 세 가지의 함수로 호출될 수 있는데, 컴파일러는 함수를 이런 모든 경우가 중첩된 것으로 취급한다.
// 이는 클래스의 생성자 중첩에서 알 수 있는데, 디폴트 인자를 가진 생성자 Dog(int a = 1)는 곧 Dog()와 Dog(4) 두 형태로 호출이 가능한데, 이 때 Dog(int a) 생성자와 기본 생성자가 중첩된 것으로 친다.
// 디폴트 인자가 사용될 경우 장점은 함수 중첩의 축약형인 점에서 코드의 길이가 간결해진다는 점과, 자주 쓰는 함수를 더 편리하게 호출할 수 있다는 점이다.

// 디폴트 인자(매개 변수)가 작동하기 위한 2가지 규칙이 있다.
// 1. 앞에 선언만 하고 main 함수 뒤에 함수 정의를 할 경우, 함수 원형 부분이 2번 적히는데, 이 때 두 부분 중 한 부분에서만 디폴트 매개 변수가 선언되어야 한다. (처음 선언 시 원형 혹은 정의할 때 원형에 한 번만 표기)
// 2. 매개 변수에 초기 값을 주어 디폴트 매개 변수로 만드는 경우, 그 변수의 다음(오른쪽)에 있는 모든 매개 변수 또한 모두 디폴트 매개 변수가 되어야 한다. (int i, int j=1과 같은 형태 금지)

// 디폴트 인자를 통해 함수 호출 시 매개 변수가 몇 개가 필요한 지에 대해 조절할 수 있다.
// 함수 호출 시 필요한 매개 변수의 수: (함수의 모든 매개 변수의 수 - 함수의 디폴트 매개 변수의 수)~(함수의 모든 매개 변수의 수)
// Gop과 Hap의 경우 (4-2)~(4) => 2~4개이다. 범위 내의 개수의 변수들이 전달 인자에 주어진다면 함수는 정상적으로 진행된다.
int Gop(int i, int j, int k = 1, int l = 1) { return(i * j * k * l); } // Gop의 경우 k와 l의 값이 없어도, 1의 값을 가지게 되는데 곱에서 1을 곱하는 건 결과에 아무런 영향도 주지 않는다.
int Hap(int i, int j, int k = 0, int l = 0) { return(i + j + k + l); } // Hap의 경우 k와 l의 값이 없어도, 0의 값을 가지게 되는데 합에서 0을 합하는 건 결과에 아무런 영향도 주지 않는다.
// 이렇게 디폴트 매개 변수는 매개 변수의 개수가 다른 경우에 필요한 곳에 사용하여 함수 중첩을 이루어 코드를 더 간단하게 작성할 수 있다.

class Dog {
private:
	int age;
public:
	Dog(int a=1) { age = a; } // 생성자 중첩: 매개 변수가 없는 경우의 기본 생성자 + 매개 변수가 있을 경우 생성자
	~Dog();
	int getAge();
	void setAge(int a);
};

int main()
{
	Dog happy(8), meri;
	int sum = 0;
	cout << happy.getAge() << " " << meri.getAge() << endl; // 8 1
	cout << Gop(4, 5, 7, 4) << endl; // 4*5*7*4 = 16*35 = 560
	for (int i = 1; i < 51; i++) { sum += Hap(i, 101 - i); }
	cout << sum << endl; // 1부터 100까지의 합, 5050
	return 0;
}
// 실행 결과
//8 1
//560
//5050
//소멸
//소멸

Dog::~Dog() { cout << "소멸" << endl; }
int Dog::getAge() { return age; }
void Dog::setAge(int a) { age = a; }
