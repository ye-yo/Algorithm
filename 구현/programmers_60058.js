//BEST 풀이
function reverse(str) {
  return str
    .slice(1, str.length - 1)
    .split("")
    .map((c) => (c === "(" ? ")" : "("))
    .join("");
}

function solution(p) {
  if (p.length < 1) return "";

  let balance = 0;
  let pivot = 0;
  do {
    balance += p[pivot++] === "(" ? 1 : -1; //나와 비슷한 방식이지만 좀 더 깔끔한 코드
  } while (balance !== 0);

  const u = p.slice(0, pivot);
  const v = solution(p.slice(pivot, p.length));

  if (u[0] === "(" && u[u.length - 1] == ")") return u + v;
  // 이미 pivot 계산할 때 개수가 맞는지 확인했음. 그러면 처음과 끝이 올바른 괄호일 경우 무조건 올바른 문자열일 수밖에 없다.
  else return "(" + v + ")" + reverse(u);
}

//나의 풀이
function checkCorrect(str) {
  const stack = [];
  for (let i = 0; i < str.length; i++) {
    if (stack[stack.length - 1] === "(") {
      if (str[i] === ")") {
        stack.pop();
        continue;
      }
    }
    stack.push(str[i]);
  }
  return stack.length > 0 ? false : true;
}

function getSplitLength(str) {
  let count = 0,
    index = str.length;
  for (let i = 0; i < str.length; i++) {
    count += str[i] === ")" ? -1 : 1;
    if (count === 0) {
      index = i + 1;
      break;
    }
  }
  return index;
}

function solution(p) {
  var answer = "";
  if (p != "") {
    const splitLength = getSplitLength(p);
    let u = p.slice(0, splitLength);
    let v = solution(p.slice(splitLength));
    const isCorrect = checkCorrect(u);
    if (isCorrect) {
      return u + v;
    }
    answer = "(" + v + ")";
    answer += u
      .slice(1, u.length - 1)
      .replace(/[\(]|[\)]/g, (w) => (w === "(" ? ")" : "("));
  }
  return answer;
}
