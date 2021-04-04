

/*
코드엔진 Advanced RCE 02번 문제

해결 방법 - UPX 언패킹, 코드 패치 오류 수정등은 건너뜀

1) 일단 OEP로 들어가면 dll 들을 로딩하는 것을 볼 수 있다
처음 프로그래밍을 실행시키면 나오는 문자열들
++++++++++++++++++++++++++++++++++++
+++++Who can crack the crackme?+++++

와 같은 문자열들이 나오는것으로 보아 정상적인 main함수 라고 생각한다
좀만 내려가면, Enter Password: 라고 비밀번호를 입력하는 곳을 찾을 수가 있다
밑에다가 BP를 하나씩 설치해보면 4012D2 번지에서 입력을 받음을 알 수 있다
그러고 계속 내려가면서 분석을 하다보면 특별한 것은 없는데 4013C5번지의 CALL EDX 에서 프로그램이 꺼지게 된다
따라서, 해당 부분에 비밀번호 검증 로직이 있을 것이라 생각된다

2) 안에 들어가자 마자 검증 함수가 눈에 보인다
CMP ECX, 43
CMP ECX, 52
CMP ECX, 41
CMP ECX, 41
CMP ECX, 41
CMP ECX, 43
CMP ECX, 4B
CMP ECX, 45
CMP ECX, 44
CMP ECX, 21 이다.

이것을 C언어로 구현을 해보면, 아래와 같다





*/

#include <stdio.h>

int main() {
	int a[] = { 0x43, 0x52, 0x41, 0x41, 0x41, 0x43, 0x4B, 0x45, 0x44, 0x21 };
	for (int i = 0; i < 10; i++) {
		printf("%c", a[i]);
	}
	return 0;
}