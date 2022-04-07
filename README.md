# Algorithm

## 스터디 방식
직접 구현하여 푼 문제는 commit하여 올리고 풀지 못한 문제는 FAILLIST에 정리해두어 추후에 다시 풀어본다.

## Commit 규칙
### 1) 문제 풀이
[사이트명] 문제번호 문제명
```shell
[BOJ] 1913 달팽이
```

### 2) 그외 문서 작성
변경사항을 요약하여 commit에 바로 작성한다.

## C++로 알고리즘 풀이 TIP
### 실행 속도 높이기
```c++
ios_base::sync_with_stdio(false); 
cin.tie(null); 
```

`ios_base::sync_with_stdio(false); `
`ios_base::sync_with_stdio` 구문은 c의 `stdio`와 cpp의 `iostream`을 동기화시키는 역할. 
이 때 `iostream`과 `stdio`의 버퍼를 모두 사용하기 때문에 딜레이가 발생함.
=> `false`로 설정하여 동기화를 비활성화 시켜줌.
=> c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용할 수 없게되지만 사용하는 버퍼의 수는 줄어들어 실행 속도는 향상됨. (싱글 쓰레드 환경에서만 사용 권장)

`cin.tie(null);`
`cin`과 `cout`의 묶음을 풀어줌.

참고 
https://jaimemin.tistory.com/1521
https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
https://www.acmicpc.net/board/view/22716