
/*

코드엔진 Advanced RCE 01 문제

이 프로그램은 몇 밀리세컨드 후에 종료 되는가
정답인증은 MD5 해쉬값(대문자) 변환 후 인증하시오



해결방법
1) peid로 파일을 열어보면 , UPX로 패킹되어 있음을 알 수 있다. 따라서 언패킹을 해준다
2) Intermodular calls 를 보면 timegettime(), Isdebuggerpresent() 라는 함수에 Set breakpoint on every commands 를 해준다
3) 차례대로 실행을 하다보면, 첫번째 Isdebuggerpresent() 함수에서 TEXT EAX, EAX 함수 다음에 JNZ ~ 라는 어셈블리어가 나온다
IsDebuggerPresent() 함수는 디버깅이 당하고 있으면 반환값이 1이 되므로, TEXT EAX, EAX를 수행했을 시 Z 플래그가 1이 됨을 알 수 있고
디버깅을 당하고 있지 않으면 반환값이 0이 되므로 TEXT EAX, EAX를 수행했을 시 Z플래그가 1로 세팅됨을 알 수 있다.
따라서, 우리는 JNZ 를 JZ 아니면 JE로 수정해주면 된다
4) 첫번째 timegettime() 함수에서 1번째로 부른 timegettime() 함수의 반환값과 2번째로 부른 timegettime() 함수의 반환값의 차이를
[EBX+4] 의 값인 337B와 비교해서 분기를 설정하고 있다
따라서, 337B 가 답임을 알 수 있고 10진수로 변환하면 13179 그리고, MD5로 변환하면 db59260cce0b871c7b2bb780eee305db 가 정답이 된다

*/