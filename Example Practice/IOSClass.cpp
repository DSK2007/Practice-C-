#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::ios;
using std::fixed;
using std::setw;
using std::setfill;
// 입출력 객체 / 스트림 (I/O Stream Object)
// C의 입출력 함수: printf(), scanf() -> C++의 입출력 객체(스트림): cout, cin
// C++의 입출력 객체는 객체 지향 개념을 새로운 입출력 함수이다. 입출력 스트림은 문자열과 데이터 타입을 가진 객체 사이에서 자동적으로 데이터를 변환시킨다.
// 입출력 객체 스트림은 객체의 자동 데이터 변환 및 처리 + 객체 지향적 프로그래밍에 알맞다는 특징 덕분에 C++에서 사용하기 적합하며 편리하고, 사용하기에 권장한다.
// 자동 데이터 변환이라는 장점 덕분에, printf, scanf에서의 %d, &x와 같은 변수마다 서식 지정 문자를 필요로 하지 않아 더 간단하다.

// 입출력 스트림 객체는 iostream(표준 입출력), fstream(파일 입출력)등 비슷한 용도의 스트림들이 클래스 라이브러리를 생성해 모여있으므로 알맞은 라이브러리를 포함시켜서 쓰면 된다.
// 입출력 객체 또한 일반 객체와 같이 동일한 스트림 객체들로 정의되어 있기 때문에, 동작 메커니즘이나 형이 다른 기능들과 일관성을 유지한다.
// iostream은 입력 모음의 istream, 출력 모음의 ostream의 다중 상속된 파생클래스로, 입출력을 모두 제공한다.
// ifstream, ofstream, fstream도 이런 점에서는 위의 스트림들과 비슷하게, fstream이 파일에 대한 입출력을 모두 제공한다.

// cin은 삽입 연산자(Insertion Operator) >>를 사용해 데이터를 콘솔로부터 입력받으며, cout는 추출 연산자(Extraction Operator) <<를 사용해 변수의 내용을 콘솔에 출력한다.
// 삽입 연산자 >>와 추출 연산자 <<는 모두 연산자 중첩 (Visual Studio에서 오버로드(Overloading)되어있다는 걸 확인 가능) 되어 있으며, 이는 모든 기본 자료형에 대해 그 처리를 중첩해 놓은 것이다.
// cin과 cout는 iostream 라이브러리에 작성되어 있어 사용하기 위해서는 #include <iostream>으로 포함시켜야 한다.
// cin과 cout는 네임스페이스로 std를 지니기에 std::cout와 같이 작성하거나, using namespace std 또는 객체 하나 씩 using std::cout를 사용한다고 미리 컴파일러에 알려주어야 한다.

// 입출력 조절자 (I/O Manipulator)
// 입출력 조절자는 함수를 이용한 형식 입출력 기능을 제공하며, 입출력 연산자 (<<, >>) 사이에 연속적으로 직접 기술할 수 있다는 이점이 있다.
// endl, dec(10진수), oct(8진수), hex(16진수)가 존재하며, 이는 다음 연산자에 출력될 데이터가 있다면 지정한 형식대로 데이터가 출력되도록 만들어준다.
// 변수에 임시적으로 형 변환 연산자를 붙이면 그 구간만 바뀐 형식으로 출력되듯이, 입출력 조절자도 실제적인 값이나 값의 형태에 영향을 주지 않는다.
// setw, setfill 등 각각 ios 클래스의 width, fill에 대응하는 입출력 조절자 또한 있는데, 이는 라이브러리 iomanip을 포함시켜야 사용할 수 있다.

// ios 클래스
// ios 클래스는 iostream에 포함되어 있는 클래스이다.
// ios 클래스는 형식 지정을 할 수 있는 형식 입출력이 가능하게 해준다. 이는 printf에서 char 형의 변수를 %d를 써서 int 형으로 출력시키는 것과 비슷하다.
// 입출력 스트림 객체는 지정된 형식대로 형식을 정하는 형식 상태(formal state), 그리고 그런 상태들을 비트 형태로 정리해놓은 형식 플래그(formal flag)라는 값이 있다.
// ios 클래스는 그런 형식 플래그의 값이 열거되어 있어, 출력 전 클래스의 함수를 호출하면 특정 비트의 값(0이냐 1이냐로 결정)을 바꿔주어 원하는 대로 형식을 지정할 수 있게 한다.
int main()
{
	// 1. setf와 unsetf - 형식 플래그의 값을 변경해 형식 상태를 바꿔주는 ios 클래스의 멤버 함수. cout에 접합되어 있어 cout.setf()와 같이 사용한다.
	// setf(형식 플래그)/unsetf(형식 플래그): 플래그를 세트/클리어한다. 형식 플래그를 인수로 받아 그 플래그 값에 해당하는 비트의 필드를 세트(1로 조정)/클리어(0으로 조정)한다.
	// setf로 설정된 플래그의 값은 unsetf로 클리어하지 않는 한 계속 유지된다. 반대로 unsetf는 출력하기 전마다 플래그를 미리 클리어해주어야 적용된다.
	// unsetf로 클리어된 플래그의 값은 다음 한 번의 출력에서만 유효하다. cout.unsetf(ios::dec)로 10진수의 출력을 클리어해도, 다음 한 번의 출력에서만 적용되고 다다음부터는 본래대로 출력된다.
	cout << "디폴트\n";
	cout << 100 << ':' << -50 << endl;   // 100:-50
	cout << 0.5 << ':' << 100.123 << endl; // 0.5 : 100.123
	cout.unsetf(ios::dec); // 10진수의 숫자로 출력하지 않는다. 다음 출력 시 10진수의 숫자가 나와도 10진수로 출력하지 않는다.
	cout.setf(ios::hex | ios::showbase | ios::uppercase); // 16진수의 숫자로 출력, 수치 베이스의 접두 문자를 출력(16진수는 0x, 8진수는 0), 16진수(0x의 x, a-f, 혹은 e+04 등)의 영문을 대문자로
	cout << "hex, showbase, uppercase\n";
	cout << 100 << ':' << -50 << endl;  // 0X64:0XFFFFFFCE (원래 10진수인 수가 16진수로, 접두 문자인 0x를 붙여서, 영문인 X,F,C,E 모두 대문자(안하면 소문자)로 출력했다.)
	// 만약에 cout.unsetf(ios::dec)이 없었다면, 100:-50으로 출력되었을 것이다.
	cout.setf(ios::scientific);
	cout << "scientific\n";
	cout << 0.5 << ':' << 100.123 << endl; // 5.000000E-001:1.00123E+002
	cout.unsetf(ios::hex | ios::scientific); // showbase와 uppercase는 10진수일 때는 적용되지 않는다.
	cout << "hex, scientific unsetting\n";
	cout << 100 << ':' << -50 << endl; // 100:-50
	cout << 0.5 << ':' << 100.123 << endl;// 0.5:100.123
	cout << "---------------------------------------------------" << endl;
	// 2. ios 클래스: width 과 fill,  / 입출력 조절자: setw()와 setfill(), setiosflags()와 resetiosflags()
	// ios 클래스는 자료 출력시 폭(width), 정밀도(precision) 등을 설정하는 멤버 함수들이 있다.
	// 그리고 iomanip에서 보면 width에 대응하는 setw(), fill에 대응하는 setfill() 입출력 대응자도 존재한다. 
	// 그리고 setf와 unsetf에 대응하는 setiosflags와 resetiosflags 입출력 조절자를 통해 플래그 세트/클리어 또한 한 줄로 줄일 수 있다.
	cout << setfill('*') << setw(10) << 100.25 << endl; // 입출력 조절자 setw가 width, setfill이 fill의 기능을 더 짧게 한 줄로 대응할 수 있다. 대신 이는 이 출력에만 해당된다.
	cout << "디폴트\n";
	cout.width(10); // int width(int w): 출력 폭을 w로 설정한다. 다음 한 번의 출력에만 적용된다. 그러므로 다시 쓰기 위해서는 출력 전에 항상 써주거나 입출력 조절자 setw()를 사용한다.
	cout << -50 << endl;
	cout << "[ * fill ]\n";
	cout.fill('*'); // int fill(char ch): 남는 필드의 문자를 ch로 채운다.
	cout.width(10);
	cout << -50 << endl;
	cout.width(10);
	cout << "HanSH" << endl;
	cout.fill(' ');
	cout.precision(6);  // int precision(int p): 소수점을 포함하지 않는 전체 자리수를 p로 지정한다.
	cout<< 12.34567 << endl;
	cout << fixed;  // precision과 함께 사용하면, precision은 소수점 이하의 자리수만 설정한다.
	cout.precision(3); // 소수점 이하의 자리수(. 뒤 자리수)는 3자리로 설정되었다.
	cout << 12.34567 << endl; // .34567에서 4번째 자리수 부터의 수들인 6, 7은 무시된다.
	cout << 12345 << 67890 << 1234567890 << 1234567890 << 1234567890 << endl;
	cout << "10칸 오른쪽 정렬" << endl;
	cout << setw(10) << "abcdefg" << setw(10) << "abcdefg" << endl; // ios에 포함된 left 플래그를 세트했다.
	cout << "10칸 왼쪽 정렬" << endl;
	cout << setiosflags(ios::left) << setw(10) << "abcdefg" << setw(10) << "abcdefg" << endl; // cout.setf 대신 setiosflags 입출력 조절자를 사용해 한 줄로 줄일 수 있다.
	cout << "다시 10칸 오른쪽 정렬" << endl;
	cout << resetiosflags(ios::left) << setw(10) << "abcdefg" << setw(10) << "abcdefg" << endl; // cout.unsetf 대신 resetiosflags 입출력 조절자를 사용해 한 줄로 줄일 수 있다.
	return 0;
}
// 실행 결과 (test.txt)
//디폴트
//100:-50
//0.5 : 100.123
//hex, showbase, uppercase
//0X64 : 0XFFFFFFCE
//scientific
//5.000000E-01 : 1.001230E+02
//hex, scientific unsetting
//100 : -50
//0.5 : 100.123
//-------------------------------------------------- -
//****100.25
//디폴트
//* ******-50
//[*fill]
//* ******-50
//* ****HanSH
//12.3457
//12.346
//1234567890123456789012345678901234567890
//10칸 오른쪽 정렬
//abcdefg   abcdefg
//10칸 왼쪽 정렬
//abcdefg   abcdefg
//다시 10칸 오른쪽 정렬
//abcdefg   abcdefg
