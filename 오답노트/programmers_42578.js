//BEST 풀이
function solution(clothes) {
  return (
    Object.values(
      clothes.reduce((obj, t) => {
        obj[t[1]] = obj[t[1]] ? obj[t[1]] + 1 : 1; //객체에 {카테고리: 옷 갯수} 형태로 갯수를 누적
        return obj;
      }, {})
    ).reduce((a, b) => a * (b + 1), 1) - 1 //그 갯수들을 + 1 한 값으로 모두 곱한 후 -1 (조합 수식)
  );
}
//나의풀이
function solution(clothes) {
  var answer = 1;
  const map = new Map();
  clothes.forEach((item) => {
    map.set(item[1], (map.get(item[1]) || 1) + 1); //입지 않는 경우의 수 1을 포함해서 count
  });
  //수학/about.md 의 조합 참고
  map.forEach((i) => {
    // 조합 구하는 공식
    answer *= i;
  });
  return answer - 1; // 아무것도 안입는 경우 제외
}
