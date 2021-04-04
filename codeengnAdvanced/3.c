
/*

CodeEngn Advanced RCE 03번 문제

별거없다.
Name이 CodeEngn일때 적절한 Serial을 찾는건데
CodeEngn을 치면 00403284 주소에 정답인 Serial이 입력됨
내가 입력한 Serial과 정답인 Serial을 비교함


CodeEngn Advanced RCE 05번 문제

별거없다
Serial을 찾는 문제인데 visual basic으로 프로그래밍 되어있다
Serial을 찾는 다는건 사용자가 입력한 Serial과 정답인 Serial을 비교하는 구문이 있을거라고 생각이 가능하다
intermodular calls를 보면 VbaStrcmp 라는 함수로 비교를 하고있다
분석을 하다보면 정답이 677345 라는 것을 쉽게 찾을 수 있다


*/