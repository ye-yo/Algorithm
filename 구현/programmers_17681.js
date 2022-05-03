function solution(n, arr1, arr2) {
  var answer = [];
  for (let i = 0; i < arr1.length; i++) {
    let str = (arr1[i] | arr2[i]) // OR 비트연산
      .toString(2) // 2진수로
      .padStart(n) // 길이, 채울문자 만큼 채워주는 최신 문법(ES2017+)
      .replace(/[0]/g, " ")
      .replace(/[1-9]/g, "#");
    answer.push(str);
  }
  return answer;
}
