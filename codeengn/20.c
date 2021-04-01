

/* 

CodeEngn basic rce의 마지막 문제로써 코드는 쉽지만 접근 방법이 상당히 난해하였다

문제
이 프로그램은 Key파일을 필요로 하는 프로그램이다.
'Cracked by: CodeEngn!' 문구가 출력 되도록 하려면 crackme3.key 파일안의 데이터는 무엇이 되어야 하는가
Ex) 41424344454647
(정답이 여러개 있는 문제로 인증시 맞지 않다고 나올 경우 Contact로 연락주시면 확인 해드리겠습니다)


간략한 해결방법
1) 20.exe와 같은 폴더에 CRACKME3.KEY 파일을 만들고 18바이트의 데이터를 써본다
2) 분석을 진행하다보면, 예시로 적은 데이터(123456789012345678) 이 pppppppppzz~~z! 라는 값으로 변경됨을 확인할 수 있다
3) 아래와 같이 코드를 적는다
4) 아래와 같이 코드를 성공적으로 적었는데, 18바이트 마지막 4바이트 값이 XOR DWORD PTR : [4020F9], 12345678
한 값과 동일해야 성공적인 메세지가 뜬다
따라서, CRACKME3.KEY의 마지막 4바이트 값을 XOR한 뒤의 결과인 [4020F9]에 있는 값으로 수정한다
*/

#include <stdio.h>
#include <string.h>

void main() {
    char key[] = "CodeEngn";
    int BL= 0x41;
    for(int i = 0; i<strlen(key); i++) {
        printf("%x ", key[i] ^ BL);
        BL++;
    }
}