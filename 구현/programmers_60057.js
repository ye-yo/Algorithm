function solution(s) {
  var answer = s.length;
  for (let i = 1; i <= s.length / 2; i++) {
    let cnt = 0,
      str = "";
    for (let j = 0; j < s.length; j += i) {
      //substr은 deprecated 되어서 substring으로 변경
      //substr은 시작index, 길이
      //substring은 시작index, 마지막index
      //뒤에서 얼마만큼 자르는 것(str.substring(str.length - i)은 동일
      if (str.substring(str.length - i) == s.substring(j, j + i)) {
        cnt += cnt === 0 ? 2 : 1;
        continue;
      }
      if (cnt > 0) {
        str += cnt.toString();
        cnt = 0;
      }
      str += s.substring(j, j + i);
    }
    if (cnt > 0) {
      str += cnt.toString();
    }
    answer = Math.min(answer, str.length);
  }
  return answer;
}
