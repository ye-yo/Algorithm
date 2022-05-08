# for ... in 사용 이슈

for ... in : 객체 내의 프로퍼티 속성 중 enumerable: true인 모든 프로퍼티를 순회하여 검색하는 용도 => 배열에는 적합하지 않음  
(구형 IE의 경우에는 `for...in` 사용 시 배열 인덱스 외에 검출되는 프로퍼티가 있기 때문에 undefined 와 같은 오류가 발생)  
=> 배열에 대해서는 `for ... in` 구문 보다는 `for`를 사용하거나 `forEach` 사용 권장.  

# forEach break 이슈

`forEach`는 `break`가 따로 없으며 `return false`로 가능하다고 하나 원칙적으로 순회 중단이 불가능  
특정 조건에 따라 중단해야 한다면 `for` 혹은 `some`이나 `every` 내장 메소드를 사용!  

## some

> 특정 조건을 만족하는 요소가 발견되면 순회 중단

break: return true;  
continue : return false;  

## every

> 특정 조건을 만족하지 않는 요소가 발견되면 순회 중단

모든 반환값이 true여야 true  

```js
[1,2,3,4,5].every(n, i){
    if(n === 2) return true;
    console.log(n);
}
// 1
```

- `n = 1`일 때 `n===2` 조건에 부합하지 않아 `true`를 return 하지 않음 => break 됨.
