#include <iostream>
using std::cout;
using std::endl;

class B; // 전방 참조 (forward reference)
// 전방 참조는 앞의 이 개체가 다른 개체에 의해 참조된다면, 미리 이름만을 알려주어 오류를 방지하게 해주는 행위이다.
// 지금 클래스 A의 경우 B 클래스를 참조하는 friend 함수가 존재한다. 이 경우 A 클래스는 B 클래스 앞에 코드가 있어 오류가 날 수 있다.
// 이를 방지하기 위해 전방 참조를 사용한다. class B 선언을 이름만을 알리고 넘긴다.
// 나중에 B 클래스를 정의하지 않으면 당연히 오류가 발생하므로, B 클래스를 정의와 선언이 따로 있는 함수처럼 다시 다른 줄에 선언과 정의를 동시에 하면 된다.

// Friend 함수와 클래스 + 전방 참조, 예외 처리
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 14주차
// 클래스 멤버 변수는 대부분 private으로 지정되어 외부에 의한 접근이 제한되어 있다.
// 그러나 예외적으로 이를 넘어서 외부에서 그런 멤버 변수들을 접근해도 허용된 것들이 바로 Friend 함수와 클래스다.
// 이 문법은 비-객체지향적이지만 여러 문법(연산자 중첩 등)들이 사용한다.
// friend는 상대 함수/클래스를 친구로 선언해, 해당 클래스의 멤버 변수는 아니지만 클래스의 멤버를 자유롭게 사용 가능하게 해주는 함수이다.
// friend로 지정된 클래스, 함수는 클래스 내부에서 선언되어 클래스의 멤버로 보이지만, 아니기 때문에 상속되지 않는다.
// friend 함수는 멤버 함수가 아니기 때문에, 앞에 어디 객체에 속했는지 표시하는 것들이 ('A., A->')이 필요하지 않다.
// 클래스 A가 클래스 C를 친구로 선언한 경우, C는 A에게 마음대로 접근이 가능하나 A가 C를 접근하는 경우는 속하지 않는다. C가 A의 친구로 선언되지 않았기 때문이다.

class A {
	int x, y;
public:
	A(int i, int j) { x = i; y = j; }
	void setX(int i) { x = i; }
	int getX() { return x; }
	friend int DoubleX(A a) { return (a.x * 2); }
	friend class C;
	friend const char* com(A a1, B b1);
	const char* com2(A a2);
	// 1. friend 함수는 이 클래스의 멤버 함수로 취급하지 않는다.
	// 2. 1로 인해 friend 함수는 클래스 안에 있음에도 상속되지 않는다.
	// 3. 그리고 또한 보통 멤버 함수처럼, 이 클래스 내부에 모든 함수/변수에 접근이 가능하다.
	// 4. 그리고 4에서 friend 함수는 보통 멤버 함수처럼 상속 받아서 접근이 제한된(private) 함수/변수에 접근할 수는 없다.
};

class B : public A {
	int y;
public:
	B(int i) : A(100, 200) { y = i; }
	void setY(int i) { y = i; }
	int getY() { return y; }
	friend int DoubleY(B b) { return (b.y * 2); }
	friend const char* com(A a1, B b1);
	friend const char* A::com2(A a2);
};

class C {
	int c, sum = 0;
public:
	C(int i) { c = i; }
	const char* com(int i) { return ((c == i) ? "c의 값과 같음" : "c의 값과 같지 않음"); }
	void s(A a) { sum = a.x + a.y + c; }
	void print() { cout << sum << std::endl; }
};

const char* com(A a1, B b1) { return ((a1.x == b1.x) ? "x의 값이 동일" : "x의 값이 동일하지 않음"); }
const char* A::com2(A a2) { return ((x == a2.x) ? "x의 값이 동일" : "x의 값이 동일하지 않음"); }

// 예외 처리
// 특정 부분을 탐색하여 오류가 될 만한 부분을 찾아내 대처하는 등 내장된 코드로 실행 오류를 잡아내는 방법
// 실행 오류가 나기 전에 미리 그럴 만한 부분을 찾아봐서(try), 잡아내면(catch), 그 부분을 반환해서(throw) 잡아낸 부분대로 대처를 하게 해준다.
// try 안에 검사할 부분을 두고, 그 뒤에 catch문을 적어 조건에 따른 예외 처리를 할 수 있다.
// 이 경우 try로 찾고, if문이 조건에 맞으면 throw로 그 오류의 값을 전달한다. 전해진 값은 catch문에서 처리하며, 이를 처리할 지점을 분기하기 위해 자료형을 특정할 수 있다.
// 분기가 갈리는 경우는 catch의 조건문 안에 들어가는 자료형의 형태이다. 여러 개의 catch문이 있을 경우, 먼저 조건문에 맞는 자료형을 throw 받은 catch문이 실행되며, 나머지 catch문들은 switch-case문처럼 생략된다.
void Div(double ja, double mo)
{
	try {
		if (mo == 0) throw mo;
		cout << "결과: " << ja / mo << endl;
	}
	catch (double) {
		cout << "오류: 영으로 나눌 수 없음" << endl;
	}
}
int main()
{
	//
	A aa(30, 60);
	aa.setX(3);
	// cout << aa.DoubleX(aa) << endl; (DoubleX는 aa의 멤버 함수가 아님)
	cout << DoubleX(aa) << endl; // private 변수인 x의 값인데도 접근이 가능해 가져오게 됨.
	B bb(60);
	bb.setY(6);
	bb.setX(3); // B 클래스 안에 상속 받은 클래스 A의 x를 설정함.
	cout << DoubleX(bb) << endl; // B 클래스 안에 상속 받은 클래스 A의 x값을 가져오게 됨.
	cout << DoubleY(bb) << endl;
	cout << "--------------------------" << endl;
	A ahappy(5, 10);
	B bnabi(3);
	cout << ahappy.getX() << ", " << bnabi.getX() << endl;
	cout << com(ahappy, bnabi) << endl;
	// cout << happy.com2(nabi); // Dog 클래스에 com2가 없음 (friend 함수래서 없음)
	// cout << com2(nabi); // com2 식별자가 정의되어 있지 않음. 
	cout << bnabi.com2(ahappy) << endl; // friend 함수이지만 com2는 B의 멤버 함수이기도 하기 때문에, 앞에 어디 객체에 속해있는지 표시해야 한다.
	cout << "--------------------------" << endl;
	A a(10, 20);
	C c(30);
	c.s(a);
	c.print();
	cout << c.com(a.getX()) << endl;
	cout << "--------------------------" << endl;
	Div(3, 2);
	Div(3, 0);
	return 0;
}
// 실행 결과
//6
//6
//12
//--------------------------
//5, 100
//x의 값이 동일하지 않음
//x의 값이 동일하지 않음
//--------------------------
//60
//c의 값과 같지 않음
//--------------------------
//결과: 1.5
//오류 : 영으로 나눌 수 없음
