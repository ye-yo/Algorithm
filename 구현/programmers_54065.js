//BEST 풀이
function solution(s) {
  return (
    JSON.parse(s.replace(/{/g, "[").replace(/}/g, "]")) //배열 모양으로 바꾸고 배열로 파싱
      .sort((a, b) => a.length - b.length) //정렬은 집합 요소 개수가 작은 순으로[3], [2,3],[4,2,3] (튜플 형식과 동일)
      //첫번째 요소는 튜플에서 첫번째 요소 [3]
      // [2, 3]에서는 앞의 요소 3을 제외한 2가 튜플의 두번째 요소라는 것을 알 수 있음 (차집합)
      //차집합은 길이가 K – 1인 배열에 없는 숫자를 길이가 K인 배열에서 찾는 방식으로 구현
      .reduce((arr, v, n) => {
        if (n) {
          return arr.concat(v.filter((f) => !arr.includes(f)));
        }
        return v;
      }, [])
  );
}

//나의 풀이
function solution(s) {
  var answer = [];
  const map = new Map();
  s = s.replace(/[\}]|[\{]/g, "").split(",");
  s.forEach((num) => map.set(num, (map.get(num) | 0) + 1));

  const mapToArray = [...map];
  mapToArray.sort((a, b) => b[1] - a[1]);
  mapToArray.forEach((obj) => answer.push(Number(obj[0])));
  return answer;
}
