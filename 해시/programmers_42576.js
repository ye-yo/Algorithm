// 참고 풀이 1
function solution(participant, completion) {
  // 해시맵을 잘 사용한 풀이
  const map = new Map();

  for (let i = 0; i < participant.length; i++) {
    let a = participant[i],
      b = completion[i];

    map.set(a, (map.get(a) || 0) + 1); //참가자 있으면 더하고
    map.set(b, (map.get(b) || 0) - 1); //완료한 참가자면 빼고
  }

  for (let [k, v] of map) {
    // 완료한 참가자라면 0이되어야 함
    if (v > 0) return k;
  }

  return "nothing";
}
// 참고 풀이 2
const solution = (p, c) => {
  //정렬했을 때 다른 부분이 있다면 해당하는 참가자가 완주를 못한 것
  p.sort();
  c.sort();
  while (p.length) {
    let pp = p.pop();
    if (pp !== c.pop()) return pp;
  }
};

//나의 풀이
function solution(participant, completion) {
  var answer = "";
  const userMap = {};
  completion.forEach((user) => {
    userMap[user] = (userMap[user] | 0) + 1;
  });

  participant.forEach((user) => {
    if (userMap[user] > 0) {
      userMap[user]--;
    } else answer += user;
  });
  return answer;
}
