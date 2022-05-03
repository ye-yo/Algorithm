function solution(N, stages) {
  let answer = [];
  let total = stages.length; //클리어한 사람을 담는게 아닌, 실패한 사람만큼 빼기위해서 초기값 유저수만큼
  for (let i = 1; i <= N + 1; i++) {
    let failCount = stages.filter((n) => n === i).length; //실패한 사람 count
    answer.push([i, failCount / total]); //스테이지, 실패율
    total -= failCount; //실패한 사람 수만큼 빼기
  }
  answer.pop(); // N+1만큼 반복했으니까 마지막 요소 제거
  answer.sort((a, b) => b[1] - a[1]); //2번째 원소 기준 내림차순 정렬
  return answer.map((data) => data[0]); //첫번째 원소만 반환
}
