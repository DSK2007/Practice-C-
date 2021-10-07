#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Dog {
private:
	int age = 2;
public:
	string name = "Happy Puppy";
	int getAge();
	void setAge(int a);
};
// 객체의 멤버 호출
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 6주차
// 객체의 멤버 호출은 구조체와 같이 변수가 포인터 변수가 아닌지, 혹은 맞는지 2가지 경우에 따라 달라진다.
// 포인터 객체가 아닌 일반 클래스 객체의 멤버는 num.val1 = 1; / num.display("안녕");처럼 객체이름.멤버변수이름 / 객체이름.멤버함수이름(매개변수)과 같이 멤버를 호출한다.
// 포인터 클래스 객체는 pnum->val2 = 2; / pnum->display("안녕");처럼 객체이름->멤버변수이름 / 객체이름->멤버함수이름(매개변수)과 같이 멤버를 호출한다.
// 즉, 포인터가 아닌 클래스 객체는 .을, 포인터 클래스 객체는 ->를 객체 이름과 멤버변수/함수 이름의 중간에 넣음으로서 값을 참조하거나 함수를 실행한다.

int main()
{
	Dog happy;
	Dog* Phappy = &happy;
	happy.setAge(3);
	happy.name = "Happy";
	cout << happy.getAge() << endl;
	Phappy->setAge(4);
	Phappy->name = "Happy";
	cout << Phappy->getAge() << endl;
	return 0;
}
// 실행 결과
//3 //getAge에서 나온 Dog 클래스 객체 happy의 age의 값이 출력됨
//4 //getAge에서 나온 Dog 클래스 객체 pHappy의 age의 값이 출력됨.

// 객체의 멤버가 호출될 때 일부 멤버 함수는 길이에 따라 inline 함수로 취급되기도 한다.
// 그렇다면 가장 재사용되기 쉬운 함수 부분은 어디일까 생각해보자면 즉시 return을 하는 getAge() 함수의 부분이 inline 함수가 되기에 적합하다.
// 클래스 내에 있는 age의 값을 리턴값으로 반환하기만 하면 되기 때문에, 사실상 cout << happy.getAge() << endl은 cout << happy.age << endl와 동일하다.
// 그러나 Dog 클래스의 멤버 변수 age는 private 속성을 지니기에, 직접적으로 접근할 수 없어 이렇게 짧은 함수가 사용되는 것이다.
int Dog::getAge() { return age; } 
void Dog::setAge(int a) { age = a; }

// 밑에 주석 처리된 예제를 보고 이 예제에서 배운 사실을 다시 알아보자. (이 곳의 Dog 클래스는 위에 써진 코드의 Dog 클래스와 내용이 동일하다.)
// int main()
// {
// Dog happy;
// Dog.age = 2; // Dog는 객체 이름이 아닌 클래스 이름이므로 사용할 수 없다. 이 부분은 실행에서 제외되어야 한다.
// happy.age = 3; // Dog 클래스 내 멤버 변수 age는 private 속성으로, Dog 클래스 내부에서만 쓰일 수 있기에 main 함수 내에서는 접근할 수 없어 실행에서 제외되어야 한다.
// cout << happy.age; // 위와 같이 private 속성의 멤버 변수는 main 함수 내에서 접근할 수 없다. 당연히 값을 입력하는 것도 불가하다. 실행에서 제외되어야 한다.
// happy.setAge(3); // 위의 Dog 클래스의 내용과 비교해보면 이는 정상적으로 진행되는 부분이다. 이를 통해 happy의 age의 값을 3으로 변경할 수 있다.
// cout << happy.getAge() // 위의 Dog 클래스의 내용과 비교해보면 이는 정상적으로 진행되는 부분이다. 클래스 내부에서 age에 접근함으로서 age의 값을 출력하게 해준다.
// }
