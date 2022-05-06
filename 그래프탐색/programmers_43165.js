//BEST 풀이
function solution(numbers, target) {
  let answer = 0;
  getAnswer(0, 0);
  function getAnswer(x, value) {
    if (x < numbers.length) {
      getAnswer(x + 1, value + numbers[x]);
      getAnswer(x + 1, value - numbers[x]);
    } else {
      if (value === target) {
        answer++;
      }
    }
  }
  return answer;
}
//나의 풀이
function dfs(numbers, num, i, target) {
  target -= num;
  if (target <= 0 && i > numbers.length - 1) return 0;
  if (i == numbers.length - 1) {
    return target === 0 ? 1 : 0;
  }
  return (
    dfs(numbers, -numbers[i + 1], i + 1, target) +
    dfs(numbers, numbers[i + 1], i + 1, target)
  );
}
function solution(numbers, target) {
  var answer = 0;
  answer =
    dfs(numbers, numbers[0], 0, target) + dfs(numbers, -numbers[0], 0, target);
  return answer;
}
