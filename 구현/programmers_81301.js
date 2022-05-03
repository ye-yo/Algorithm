// BEST 풀이

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
  var answer = s; //[ 'one4seveneight' ]

  for (let i = 0; i < numbers.length; i++) {
    let arr = answer.split(numbers[i]); //i=0이면 문자열을 zero를 기준으로 분리 [ '', '4seveneight' ]
    answer = arr.join(i); // 분리된 문자열 배열을 합치는데 i로 합침 > 14seveneight
  }

  return Number(answer);
}

// 나의 풀이

function getNumber(str) {
  const eng = [
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
  let number = -1;
  eng.forEach(function (word, index) {
    if (word === str) {
      number = index;
      return 0;
    }
  });
  return number;
}

function solution(s) {
  var answer = "";
  var str = "";
  for (let index = 0; index < s.length; index++) {
    const word = s[index];
    if (isNaN(word)) {
      str += word;
      const number = getNumber(str);
      if (number > -1) {
        answer += number;
        str = "";
      }
    } else {
      answer += word;
    }
  }
  return Number(answer);
}
