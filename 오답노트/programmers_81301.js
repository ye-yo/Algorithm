function solution(s) {
  let numbers = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];
  var answer = s;

  for (let i = 0; i < numbers.length; i++) {
    let arr = answer.split(numbers[i]); //zero를 기준으로 나누면 zero123의 경우 '', '123'으로 나눠짐
    answer = arr.join(i); //이걸 합칠 때 0을 붙여서 합치면 0123이 됨.
  }

  return Number(answer);
}
