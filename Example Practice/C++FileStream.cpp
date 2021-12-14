#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

// 파일 입출력
// 파일 입출력도 표준 입출력처럼 스트림을 통해 동작된다.
// 파일 입출력 동작을 위한 라이브러리로는 파일 입력에는 ifstream, 파일 출력에는 ofstream, 그리고 그 입출력 둘다 할 수 있는 fstream이 있다.
// fstream 또한 ifstream과 ofstream으로부터 상속받은 파생 클래스이기 때문에, 
// 파일을 읽는 파일 입력 클래스인 ifstream과 파일에 쓰는 파일 출력 클래스인 ofstream을 통해 파일 입출력을 모두 할 수 있다.

int main()
{
	char ch;
	ofstream hout("test.txt"); // 출력 파일 스트림 객체 "test.txt"를 선언한다. // ofstream hout; hout.open("test.txt"); 와 같이 선언할 수도 있다.
	// 선택적으로 파일 이름 뒤에 ios::in(입력 모드), ios::out(출력 모드)으로 파일 개방 모드를 정할 수 있다.
	// 출력 파일이 존재하지 않읈 시 프로그램을 실행할 때 선언한 이름대로 자동으로 만든다.
	if (!hout) { // 출력할 파일을 열 수 없는 오류가 발생했을 때 (오류가 생겨 파일이 열리지 않을 경우 객체는 0으로 반환된다. !hout은 그러면 거짓(0)의 반대인 참(1)이 되므로 조건이 실현된다.)
		cout << "출력할 파일을 열 수 없음.";
		return 1; // 오류가 일어나 비정상적으로 종료되었다고 리턴한다.
	}
	hout << "Han S. H. \n";
	hout.close(); // close를 하면 파일이 닫힌다. 다시 파일에 입출력하기 위해서는 hout.open으로 파일을 열어야 한다.
	ifstream hin("test.txt"); // 입력 파일 스트림 객체 "test.txt"를 선언한다.
	// ofstream과 달리 입력 파일이 존재하지 않을 시 자동 생성이 불가하다. 파일로부터 입력받아야 할 입장이기 때문이다.
	if (!hin) { // 입력해올 파일을 열 수 없는 오류가 발생했을 때
		cout << "입력할 파일을 열 수 없음";
		return 1; // 오류가 일어나 비정상적으로 종료되었다고 리턴한다.
	}
	hin.unsetf(ios::skipws); // 공백 무시 x (공백을 무시하는 플래그를 클리어했다.)
	while (!hin.eof()) { // 파일에 끝에 도달했는 지 확인하기 위해 eof() 함수를 사용한다.
		hin >> ch;
		if (ch == ' ') ch = '*'; cout << ch;
	}
	hin.close();
	return 0;
}
// 실행 결과 (test.txt)
//Han S. H.  (파일에 출력함)
//Han*S.*H.* (파일로부터 입력받음)
