#include <iostream>
#include <string> // string은 std::string을 사용하기 위해 포함되었다.
using std::cout;
using std::cin;
using std::endl;
using std::string; // std::string은 char 배열 대신 매개 변수 및 문자열의 편리한 수정을 위해 사용되었다.
using std::getline; // std::getline은 cin 대신 띄어쓰기가 있는 문자열을 입력할 때를 위해 사용되었다.
// 출처 및 참고: 2021학년도 2학기 인덕대학교 한성현 교수님 C++프로그래밍 강좌 5주차
// C++는 기존 C언어에서 문법 포함 및 개선, 그리고 객체 지향 프로그래밍 기법과 객체의 구현 방법인 Class를 추가한 것이다.
// 객체 지향 프로그래밍은 자료와 처리 동작을 한데 묶은 객체 개념을 메인으로 하는 프로그래밍 기법이다. C++는 이를 기반으로 프로그래밍을 할 수 있게 개선되었다.
// 기본 C의 구조적 프로그래밍은 자료와 처리 동작이 따로 있어 재사용 등 확장이 어렵지만, 이제는 C++는 둘을 객체로 묶어 프로그램의 유지 보수 및 확장, 나중에 재사용하는 것도 쉬워지게 되었다.
// 그리고 그것을 구현하는 것이 바로 Class이다.
class Person {
	// Class는 객체의 기본 규격/객체의 타입이다. C의 구조체가 여러 변수를 모은 새로운 자료형 타입을 선언하게 해주었듯, 프로그래머가 원하는 객체의 타입을 선언하게 해준다.
	// 객체는 자료와 그를 처리하는 연산(Method)를 하나로 묶은 요소이다. 즉 객체는 자료의 값을 표현하는 변수와 그를 연산하고 응용하는 함수까지 포함한 개념이다.
	// 프로그램을 실질적으로 구성한다. (main 함수 내에서는 Class의 멤버 함수를 호출함으로서 기능을 실현한다.)
	// 한 클래스에서 생성되거나 그 클래스에 속하는 하나의 객체를 인스턴스(Instance)라고 한다. 클래스의 객체로 선언되고, 그에 맞는 메모리까지 할당되었으면 인스턴스라고 불린다.
	// 클래스는 하나의 설계도, 객체는 설계도를 기반으로 해 제품명만 나온 제품, 인스턴스는 그 객체를 완성한, 실체가 있는 하나의 독립적 존재라고 볼 수 있다.
	// 클래스 내부에 있는 함수/변수들은 서로 접근할 수 있으며, 이 한계는 접근 지정자 prviate, public 등에 의해 정의된다.
private: // 이 클래스 내부에서만 사용 가능한, 비공개된 부분이다. 다른 클래스와 상속 관계여도 그 클래스는 접근할 수 없다.
	int age = 20; // 나이
	string job = "회사원"; // 직업
	string resisdence = "한국 서울"; // 거주지 (국가, 지역)
	string birthplace = "한국 서울"; // 출생지 (국가, 지역)
	string education = "대학교 졸업"; // 학력
	string name = "김철수"; // 이름
public: // main 함수 내에서도 사용 가능하게 해주는, 공개된 부분이다. 여기에 선언된 변수는 main 함수 내에서도 값을 대입/참조가 가능하며 함수 또한 호출이 가능하다.
	// main 함수 내에서 호출을 해야 클래스의 기능이 구현될 수 있으므로, 대부분의 멤버 함수는 public에서 선언되어야 할 것이다.
	void givemeinfo() // 모든 멤버 변수를 형식대로 출력해 정보를 알려주는 함수이다.
	{
		cout << age << "세 " << job << " " << resisdence << " 거주 " << birthplace << " 출생 " << education << " " << name << endl;
	}
	void enterinfo(string strin) // 매개 변수로 멤버 변수의 이름을 받아 클래스의 멤버 변수에 입력하게 해주는 멤버 함수이다.
	{
		// int 에는 cin, string에는 getline을 사용해 정보를 입력 및 저장받을 수 있도록 한다.
		// 단, education(학력) 멤버 변수의 입력은 cin으로 미리 출력된 선택지의 번호를 받아 문자열을 완성시키도록 한다.
		if (strin == "나이" || strin == "age")
		{
			cout << "나이를 입력하시오: ";
			cin >> age;
			cin.ignore(32767, '\n'); // getline과 병행 시 오류 방지
		}
		else if (strin == "직업" || strin == "job")
		{

			cout << "직업을 입력하시오: ";
			getline(cin, job);
		}
		else if (strin == "거주지" || strin == "resisdence")
		{
			cout << "거주지를 입력하시오 (형식 예시: 한국 서울): ";
			getline(cin, resisdence);
		}
		else if (strin == "출생지" || strin == "birthplace")
		{
			cout << "출생지를 입력하시오 (형식 예시: 한국 서울): ";
			getline(cin, birthplace);
		}
		else if (strin == "학력" || strin == "education")
		{
			string std = ""; // 빈 string을 선언해둔다.
			int a = 0, b = 3;
			cout << "1. 초등학교" << " " << "2. 중학교" << " " << "3. 고등학교" << " " << "4. 대학교" << " " << "5. 대학원" << " " << "6. 무학력" << endl;
			cout << "학력에 맞는 학교를 숫자를 입력해 선택하시오: ";
			cin >> a;
			if (a < 6 && a >= 1) // 졸업 / 재학 중이 필요없는 무학력은 이를 넘어간다.
			{
				cout << "1. 재학 중" << " " << "2. 졸업" << endl;
				cout << "학력에 맞는 상황을 숫자를 입력해 선택하시오: ";
				cin >> b;
			}
			switch (a) { // switch-case 문으로 아까 입력했던 경우의 수대로 문자열을 완성시킨다.
			case 1:
				std.replace(0, 9, "초등학교");
				break;
			case 2:
				std.replace(0, 7, "중학교");
				break;
			case 3:
				std.replace(0, 9, "고등학교");
				break;
			case 4:
				std.replace(0, 7, "대학교");
				break;
			case 5:
				std.replace(0, 7, "대학원");
				break;
			case 6:
				std.replace(0, 10, "무학력");
				break;
			default:
				std.replace(0, 10, "무학력"); // 1-6 사이의 숫자가 아닐 경우, 자동으로 학력이 없는 것으로 친다.
				break;
			}
			switch (b) {
			case 1:
				std.insert(std.length(), " 재학 중");
				break;
			case 2:
				std.insert(std.length(), " 졸업");
				break;
			default:
				break; // 학력이 있는 경우 재학 중 / 졸업을 붙이고, 아니면 자동으로 넘어간다.
			}
			education = std; // 완성된 문자열 string을 education에 그대로 대입한다.
			cin.ignore(32767, '\n'); // getline과 병행 시 오류 방지
		}
		else if (strin == "이름" || strin == "name")
		{
			cout << "이름을 입력하시오 (형식 예시: 김철수): ";
			getline(cin, name);
		}
	}
	// protected라는 접근 지정자도 존재하는데, 이는 main 함수 내에서는 못 쓰지만 상속 관계인 클래스는 접근이 가능하게 해주는 형식 지정자이다.
	// 그러나 상속 개념을 사용하지 않을 때는 public, private 만으로도 클래스를 구현하기에 충분하다.
}; // 클래스 끝에 객체 이름을 미리 선언할 수 있는데, 이게 아까 말했던 '인스턴스가 아닌 객체'의 모습이다. 아직 객체 이름은 있으나 완성은 되지 않았다.
// 이렇게 클래스를 통해 객체 타입을 선언함으로서, main 함수 내에 객체 선언으로 인스턴스를 구현해 객체 지향 프로그래밍 기법을 이룰 수 있다.
// 클래스에는 상속, 캡슐화, 함수/연산자 중첩(Overloading) 등 여러 방법으로 객체를 더 자세하고 유연하게 구현할 수 있으며, 이를 제대로 활용하는 것이 주 과제이다.
int main()
{
	Person J; // 그리고 인스턴스는 이렇게 만들어진 객체가 메모리에 할당되었을 때를 의미한다. 코드 내에서 멤버 함수를 호출하면 기능이 실행된다.
	J.givemeinfo(); // 인스턴스가 된 객체는 멤버 변수의 값을 저장하고 멤버 함수에 따라 연산(Method)를 할 수 있다.
	J.enterinfo("age");
	J.enterinfo("직업");
	J.enterinfo("resisdence");
	J.enterinfo("출생지");
	J.enterinfo("education");
	J.enterinfo("이름");
	J.givemeinfo();
	return 0;
}
// 실행 결과 (예시)
//20세 회사원 한국 서울 거주 한국 서울 출생 대학교 졸업 김철수
//나이를 입력하시오 : 44
//직업을 입력하시오 : 인형 재단사
//거주지를 입력하시오(형식 예시 : 한국 서울) : 한국 서울
//출생지를 입력하시오(형식 예시 : 한국 서울) : 미국 캔자스주
//1. 초등학교 2. 중학교 3. 고등학교 4. 대학교 5. 대학원 6. 무학력
//학력에 맞는 학교를 숫자를 입력해 선택하시오 : 4
//1. 재학 중 2. 졸업
//학력에 맞는 상황을 숫자를 입력해 선택하시오 : 2
//이름을 입력하시오(형식 예시 : 김철수) : 해리스 김
//44세 인형 재단사 한국 서울 거주 미국 캔자스주 출생 대학교 졸업 해리스 김
