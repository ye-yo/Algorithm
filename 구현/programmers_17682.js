function solution(dartResult) {
  const answer = [];
  let score = 0,
    numString = "";
  for (let i = 0; i < dartResult.length; i++) {
    const word = dartResult[i];
    if (!isNaN(word)) {
      numString += word;
      continue;
    }
    // numString 두는 대신 정규식으로 숫자와 문자 배열을 따로 둬서 계산하면 깔끔
    if (numString != "") {
      answer.push(score);
      score = Number(numString);
      numString = "";
    }
    // switch 대신 object 이용하면 더 깔끔하게 가능
    switch (word) {
      case "D":
        score *= score;
        break;
      case "T":
        score *= Math.pow(score, 2);
        break;
      case "#":
        score *= -1;
        break;
      case "*": {
        score *= 2;
        answer[answer.length - 1] *= 2;
        break;
      }
      default:
        break;
    }
    if (i == dartResult.length - 1) {
      answer.push(score);
    }
  }

  return answer.reduce((acc, cur) => acc + cur);
}
