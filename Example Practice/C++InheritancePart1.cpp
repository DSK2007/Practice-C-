#include <iostream>
using std::cout;
using std::endl;

// 클래스의 상속 / 기본 클래스와 파생 클래스 / 상속 접근 제어 속성 / protected 멤버 / 생성자와 소멸자 / 계층적 다중 상속 / 여러 개의 기본 클래스 상속
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 12주차

// 객체 지향적 언어의 3가지 특성: 캡슐화, 다형성, 상속 중에서 상속을 알아보자.
// 상속은 클래스가 다른 클래스에 상속되어 마치 #include로 함수 라이브러리를 포함시키듯이 클래스의 멤버들을 가져올 수 있다. 코드를 재사용할 수 있게 해주는 것이다.
// 개 클래스를 만든다고 가정해보자. 그런데 개의 모든 기능을 구현하기에는 너무 시간이 걸린다.
// 그런데 미리 정의된 포유류 클래스가 있다면 상속을 통해 포유류의 기본적 구조와 관련된 기능은 생략하고 개 클래스에 고유적인 기능만 따로 추가하면 된다.
// 이를 이어서 포유류는 동물이고, 동물은 생물에 속한다. 즉 개 클래스는 생물 -> 동물 -> 포유류 -> 개 처럼 미리 정의된 클래스의 다중 상속을 통해 많은 시간과 비용을 절약할 수 있다.
// 구조 상으로 점점 올라갈 수록 단순해지고(일반화 된다고 한다.), 내려갈 수록 앞의 기능이 상속되고 고유적인 기능이 추가되어 복잡해진다(특수화 된다고 한다.).
// C와 비교하면 C는 중복되는 기능이 있어도 상속이 불가해 모든 기능을 따로 만들어야 한다. 그에 비해 C++는 상속이 가능하다.

// 상속은 한 클래스에 여러 클래스를 상속시킬 수도 있지만, 가장 큰 특징은 이미 상속을 했던 클래스를 또 다른 클래스에 상속할 수 있고, 이는 계속해 반복될 수 있다. 이를 계층적 다중 상속이라고 한다.
// 중첩, 상속이 불가한 정적인 C와 비교하면 클래스의 이러한 재사용과 중복을 가능하게 하는 것이 지양된다고 볼 수 있다. 이미 존재하는 클래스에게서 기본적인 특성을 물려받고, 나머지는 자신의 새로운 특성으로 정의하는 것이다.
// 상속의 이러한 특성을 통틀어 상속성(Inheritance)라고 하며, 이는 프로그램 개발 속도의 비약적 향상, 코드 재사용을 통한 경비 절감 등 긍정적인 효과를 얻을 수 있다.
// 실무에서도 주로 개발 환경은 다른 회사가 제공하는 클라우팅 컴퓨팅 서비스로 마련된 유저 인터페이스(User Interface, UI)를 사용해 개발하는 경우가 많고, 그러한 경우 미리 만들어진 클래스에 상속이 자주 사용된다는 점에서 중요하다.

// 상속은 클래스를 선언할 때 표기해서 효과를 얻을 수 있다.
// C++에서는 class A : public B 처럼, 클래스 선언 뒤 중괄호('{}')가 나오기 전 콜론(':')을 놓고 상속 접근 제어 속성과 상속할 클래스 이름을 입력한다.
// *: C#, swift, kotlin 등은 클래스 이름 앞에 접근 제어 속성을 빼고 쓴다[class A : B]. / python은 괄호를 사용한다[class A(B)].
// 상속 접근 제어 속성은 기존의 멤버가 지니던 private, protected, public 3가지를 사용해서 지정한다. 그대로 상속하기 위해서는 public을, 제한적이고 싶으면 private을 주로 사용한다.
// 상속을 한 클래스를 기본 클래스(부모 클래스)라고 하며, 상속을 받은 클래스를 파생 클래스(자식 클래스)라고 한다.
// 이들의 관계를 영어권에선 is-a 관계라고 부르는데, 부모-자식 관계라고 보면 된다. B가 부모 클래스, A가 자식 클래스라 치고 두 문장을 살펴보자.
// B는 A의 부모 클래스이다. ( B is superclass(기본/부모 클래스) of A. ) / A는 B의 자식 클래스 이다. ( A는 subclass(파생/자식 클래스) of B. ) -> 이 2가지 명제가 성립되는 관계라는 걸 알 수 있다.
// 이를 is-a 관계로 묘사하는 이유는, 그림으로 나타내면 자식 클래스 A가 부모 클래스 B에게서 상속 과정(Inherits from)을 받았다고 화살표를 치는 것이기 때문이다. 이를 혼동하지 않고 잘 알아두자.

// 상속에서 접근 제어 속성
// 접근 제어 속성은 private, protected, public 3가지가 존재했다. 상속에서 이 속성들은 상속될 때, 그리고 상속 접근 제어 속성으로서 사용될 때 2가지 경우에 사용된다.
// private 멤버는 상속될 때 상속이 불가하다. 정확히는 자신이 원래 속하던 클래스의 멤버 함수만 접근하게 해준다.
// protected 멤버는 상속되면 파생 클래스의 정의 부분에서 사용할 수 있다. 그러나 클래스 밖인 main 함수에서는 호출하지 못하기 때문에, public 함수에서 이들을 호출하거나 값을 사용할 멤버 함수를 만들어야 한다.
// public 멤버는 상속되면 클래스 정의 부분이든, main 함수 밖에서든 사용할 수 있다.

// 이렇게 앞에 속성에 따라 상속이 되면, 상속 접근 제어 속성은 자신과 비교해 상속했던 멤버들 중 보안성이 낮은 멤버 모두를 자신의 속성으로 덮어 씌운다. (보안성 강도 순: private > protected > public)
// 덮어 씌워진 속성은 다중 상속되어도 유지된다. 할아버지 클래스에서 public 멤버였어도 private 상속을 이미 1번 거쳤으면 자식 클래스에서는 상속 불가가 되버릴 수 있다.

// 상속 접근 제어 속성에 따른 상속 3가지 
// 공통점: private 멤버는 상속되지 않는다. (*상속 불가: 어느 속성에도 속하지 않는 접근 불가 상태로 상속된다. 접근 방법은 그 private 멤버가 속했던 클래스의 멤버 함수로 접근하는 것 뿐이다.)
// (*덮어 씌워지다: 속성이 덮어 씌워지면, 자식 클래스 내에서는 그 속성의 특성대로 처리된다. 예를 들어 public 멤버가 private 멤버가 덮어 씌어지면, main 함수 밖에서 호출할 수 없고, 정의 부분에서만 쓸 수 있다.)
// private 상속: public, protected 멤버 모두 private 멤버로 덮어 씌워진다. 이들은 자식 클래스 내에서 정의 부분에서만 사용될 수 있다. 또한 이들은 다음 상속 시 상속 불가다.
// public 상속: 상속되는 모든 멤버는 속성을 그대로 유지한다. public 멤버는 main 함수 내에서도 호출이 가능하지만, protected 멤버는 자식 클래스 내에서 정의 부분에서만 사용될 수 있다.
// protected 상속: public 멤버는 protected 멤버로 덮어 씌운다. private 상속과 매우 유사해 자주 사용되지는 않는다. 대신 private 상속과 비교해 protected 상속은 자식 클래스의 정의 부분에서는 사용될 수 있고, 다음 상속 때도 상속에 대한 제한이 없다는 점이 있다.

// 상속될 때 생성자와 소멸자에 대하여
// 상속 시 생성자가 있었다면, 그리고 그 생성자가 매개 변수가 필요하다면, 자식 클래스는 생성자를 만들어 부모 클래스의 생성자에 매개 변수를 넘겨주어야 한다.
// 생성자는 상속되어도 클래스 정의 부분에서 호출되지 않고, 가장 위의 부모 클래스의 생성자 부터, 가장 밑의 자식 클래스의 생성자 순으로 차례대로 호출되어 실행된다.
// 소멸자는 생성자의 역순으로 가징 밑부터 가장 위 순으로 호출되어 실행되며, 매개 변수가 없기 때문에 넘겨줄 걱정은 하지 않아도 된다.

class A { // 할아버지 클래스, 계층 구조 상 가장 위의 부모 클래스이다.
private:
	int a;
protected:
	int ap;
public:
	A(int i, int j) : a(i), ap(j) {}
	void setA(int i) { a = i; }
	int getA() { return a; }
	void setAP(int i) { ap = i; }
	int getAP() { return ap; }
};

class B : public A { // 아버지 클래스, 계층 구조 상 중간에 있는 부모 클래스이다. 할아버지 클래스의 자식이다. 할아버지의 특성을 물려받았다.
 // int a; (A 클래스에서 온 멤버 함수 외 접근 불가)
private:
	int b;
protected:
 // int ap;
	int bp;
public:
 // A(int i, int j) : a(i), ap(j) {} // 생성자는 멤버 함수와 달리 상속되어도 생성자를 따로 입력하는 게 아닌, 파생 클래스의 생성자에게서 매개 변수를 넘겨 받는 것으로 대신한다.
 // void setA(int i) { a = i; }
 // int getA() { return a; }
 // void setAP(int i) { ap = i; }
 // int getAP() { return ap; }
	B(int i, int j, int k, int l) : A(i, j), b(k), bp(l) {} // 직접 초기화 ( B():A(1,2){} ) 의 방식으로 넘겨주는 것이 좋다. 복사 초기화 ( B(){A(1,2)} ) 으로는 호출하지 않으면 매개 변수만을 넘길 수 없다.
	void setB(int i) { b = i; }
	int getB() { return b; }
	void setBP(int i) { bp = i; }
	int getBP() { return bp; }
};

class C : public B { // 자식 클래스. 할아버지 클래스의 자식의 자식, 아버지 클래스의 자식이다. 할아버지, 아버지의 특성을 물려받았다.
// int a; (A 클래스에서 온 멤버 함수 외 접근 불가)
// int b; (B 클래스에서 온 멤버 함수 외 접근 불가)
private:
	int c;
//protected:
	// int ap;
	// int bp;
public:
 // A(int i, int j) : a(i), ap(j) {} // 생성자는 멤버 함수와 달리 상속되어도 생성자를 따로 입력하는 게 아닌, 파생 클래스의 생성자에게서 매개 변수를 넘겨 받는 것으로 대신한다.
 // void setA(int i) { a = i; }
 // int getA() { return a; }
 // void setAP(int i) { ap = i; }
 // int getAP() { return ap; }
 // B(int i, int j, int k, int l) : A(i, j), b(k), bp(l) {} // 직접 초기화 ( B():A(1,2){} ) 의 방식으로 넘겨주는 것이 좋다. 복사 초기화 ( B(){A(1,2)} ) 으로는 호출하지 않으면 매개 변수만을 넘길 수 없다.
 // void setB(int i) { b = i; }
 // int getB() { return b; }
 // void setBP(int i) { bp = i; }
 // int getBP() { return bp; }
	void setC(int i) { c = i; }
	int getC() { return c; }
	C(int i, int j, int k, int l, int m) : B(i, j, k, l), c(m) {} // 매개 변수를 넘겨주는 것은 바로 전의 생성자에게만 넘겨주면 된다. 전의 생성자는 이미 넘겨 받는다고 정의가 되어 있기 때문이다.
};

// 이렇게 계층적 다중 상속으로 이루어지는 가장 큰 결과는 바로 코드를 쓰는 속도, 개발 속도가 증가한다는 것이다.
// 클래스 C에서 주석 친 코드는 만약에 상속이 이루어지지 못했더라면, 적어야 했던 코드들이다.
int main()
{
	A aa(1,2);
	B bb(1,2,3,4);
	C cc(1, 2, 3, 4, 5);
	// main 함수에서 객체를 인스턴스로 만들어 멤버를 호출할 경우, private과 protected 멤버는 그럴 수 없다는 것을 알아야 한다.
	// 이는 또한 상속 과정 중 public 멤버가 protected, private으로 바뀐 경우도 호출할 수 없다는 것을 알아야 한다.
	cout << aa.getA() << endl;
	cout << bb.getA() << endl;
	cout << cc.getA() << endl;
	cout << cc.getAP() << endl;
	return 0;
}
// 실행 결과
//1
//1
//1
//2
