//BEST 풀이
function solution(new_id) {
  const answer = new_id
    .toLowerCase() // 1
    .replace(/[^\w-_.]/g, "") // 2
    .replace(/\.+/g, ".") // 3
    .replace(/^\.|\.$/g, "") // 4
    .replace(/^$/, "a") // 5 공백이면 a로 치환
    .slice(0, 15)
    .replace(/\.$/, ""); // 6
  const len = answer.length;
  return len > 2 ? answer : answer + answer.charAt(len - 1).repeat(3 - len); // .repeat() 문자열 반복 메소드
}

// 나의 풀이
function solution(new_id) {
  var answer = new_id.toLowerCase();
  answer = answer
    .replace(/[^0-9a-z\-\_\.]/g, "")
    .replace(/\.+/g, ".")
    .replace(/^\.|\.$/g, "");
  if (answer == "") answer = "a";
  if (answer.length > 15) {
    answer = answer.substr(0, 15).replace(/\.$/g, "");
  }
  while (answer.length < 3) {
    answer += answer.charAt(answer.length - 1);
  }
  return answer;
}
