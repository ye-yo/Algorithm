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

## 문자열

### 문자열 자르기

```cpp
문자열.substr(시작위치, 길이)
```

두 번째 인수(길이)는 생략 가능. 생략 시 시작위치부터 마지막까지

뒤에서 부터 자르려면

```cpp
문자열.substr(문자열.length() - 길이)
```

### 마지막 문자 제거

```cpp
문자열.pop_back()
```

## Vector(벡터)

### i번째 원소 제거

```cpp
v.erase(v.begin() + i);
```

## Queue(큐)

#include <queue>

### 우선순위 큐

priority_queue<int> pq;

## 정렬

#include<algorithm>

```cpp
sort(배열의 시작주소, 배열의 마지막 주소);

//배열일 경우 배열 변수는 포인터이므로
sort(배열명, 배열명+ 배열 크기);
sort(arr, arr+10)

//vector일 경우
sort(v.begin(), b.end())
```

정렬 범위는 start <= arr <end 이기 때문에 배열의 크기를 넣어줘야 함.

sort()함수는 기본 오름차순 정렬

### 내림차순 정렬

sort(start,end,grearter<자료형>())

### 임의의 조건 기준으로 정렬

sort(start,end,compare)를 이용하면 사용자가 정한 함수(compare)를 기준으로 정렬

## 동적 할당

1. new
2. malloc

차이점

1. 자료형 선언 필요 여부
   `malloc`은 포인터 타입을 모르기 때문에 return 값의 자료형은 `(void*)`
   이 때문에 사용 시 `int * i = (int*)malloc(sizeof(int))` 같이 자료형을 앞에 선언해주어야 함.
   `new`는 `type-safe`로 해당 객체에 맞는 포인터로 반환해주어 자료형 선언 필요 없음
2. 초기값 할당 가능 여부
   `new`는 초기값 줄 수 있음. malloc은 불가
3. 예외처리 여부
   new는 에러발생시 예외처리. malloc은 NULL 반환
4. 메모리 재조정
   malloc은 realloc으로 할당된 메모리 크기 재조정 가능. new는 불가능

### new

`new` 연산자 사용해 할당한 것은 힙 영역에 메모리가 할당되며 힙 영역의 메모리는 프로그래머가 관리해야 하므로 반드시 사용 후 `delete`를 해주어야 한다. 동적 배열일 경우 `delete[]`(배열이라는 것을 명시하기 위해)

```cpp
int* arr = new int[n];

delete[] arr;
```

### malloc

해제는 `free` 함수로

```
int *arr = (int *)malloc(sizeof(int) * size);

free(arr);
```

### calloc

`calloc`은 할당과 동시에 0으로 초기화함

```
int *arr = (int *)calloc(size, sizeof(int));

free(arr);
```

### realloc

메모리 사이즈 변경 시에 사용

### 2차원 배열 동적 할당

1. vector
2. memset
   memset(arr, 0, sizeof(int) \* 5);
3. 이중 loop

#### memset

```cpp
#include <string.h> // memset 함수 사용을 위해 include

/* 메모리 할당 */
int **arr = new int*[sizeY];
for(int i = 0; i < sizeY; ++i) {
    arr[i] = new int[sizeX];
    memset(arr[i], 0, sizeof(int)*sizeX); // 메모리 공간을 0으로 초기화
}

/* 메모리 해제 */
for(int i = 0; i < sizeY; ++i) {
    delete [] arr[i];
}
delete [] arr;
```

#### 이중 loop

```cpp
// int형 2차원 배열 동적 할당
int** alloc2DArr (int rows, int cols){
    if(rows <= 0 || cols <= 0) return NULL;
    int** mat = new int* [rows];
    for (int i=0 ; i<rows ; i++ )
        mat[i] = new int[cols];
    return mat;
}

// int형 2차원 배열 동적 해제
void free2DArr ( int** mat, int rows, int cols=0){
    if(mat != NULL){
        for(int i=0 ; i<rows ; i++)
            delete[] mat[i];
        delete[] mat;
    }
}

```

# 문자열 변환, 문자열 처리

## 문자열 포인터

```cpp
char *str = "sentence";
```

str은 포인터로 선언되었으므로 주소값이 들어가야 하는데 문자열을 할당하고 있음.
하지만 여기서 `"sentence"`는 주소값이 맞음. `"sentence"`라는 문자열이 저장된 주소값을 가리킴.
위의 코드를 실행하면 `"sentence"`의 시작주소값을 가져와서 str에 대입이 되고
str은 `"sentence"`라는 리터럴을 가리킴.

## ❗️ :string"에서 "const char \*"(으)로의 적절한 변환 함수가 없습니다

const char\*을 파라미터로 쓰는 함수에 string을 사용하려면

```cpp
string str = "I want to convert string to char*";;
char * c = str.c_str();
```

## 문자열 문자 배열로 변환

## int > string 변환

to_string(a)

## string > int / long / long long 변환

```cpp
stoi(num);
stol(num);
stoll(num);
```

## char 배열에 string 넣기

strcpy(arr, "string");

## 아스키 코드 <> 문자 변환

atoi(문자)
(char)(아스키코드)

## 소문자 대문자 전환

tolower(문자열)
toupper(문자열)

# 해시맵

## 해시맵에 키 존재하는지 체크

if(map.count(key) > 0)
if(map.find(key) == map.end()) // 키 없음
map[key]도 연습할 땐 됐음

# 정렬

## 사전 순 정렬

a < b
