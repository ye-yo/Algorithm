// 해답 : 슬라이딩 윈도우 알고리즘으로 풀이
/*
1. Map 자료구조를 사용하고 map[보석명] = 빈도수로 저장
2. 왼쪽 포인터(l)과 오른쪽 포인터(r)을 모두 1번 진열대에 위치시킴(0)
3. 양 포인터 중 둘 중 하나라도 진열대 범위를 벗어나면 알고리즘 종료
4. 양 포인터가 가리키는 범위 안에 포함된 보석 종류의 개수를 세어 봄.(map 사이즈 체크)
5. 5-1 범위 안에 보석 종류가 전체 보석 종류와 일치하면 좋은 답인지 체크한 후 l 증가 > 2로 감
    5-2 범위 안에 보석 종류가 전체 보석 종류보다 작다면 r 증가 > 3으로 감

=> l과 r을 이용해서 보석 종류가 모자라면 r을 증가시키고, 초과되면 l을 증가시키는 과정을 반복하면서 정답을 갱신
이 때 l을 증가시키기 이전, map 자료구조에서 l번 진열대에 있던 보석의 빈도수를 감소시켜주어야 함.
특히 빈도수가 1에서 0이 될 때에는 map에서 제거되야 함. 
r을 증가시킬 때는 map 자료구조에서 증가된 r번 진열대에 있는 보석의 빈도수 증가
 */
function solution(gems) {
  const cnt = new Set(gems).size;
  var ans = [1, gems.length];

  var l = 0, // left 포인터
    r = 0; //right 포인터
  const map = new Map(); // Map 사용 시 삽입 순서 유지해줌
  map.set(gems[0], 1);

  while (r < gems.length) {
    // 5-1
    if (hit.size === cnt) {
      if (ans[1] - ans[0] > r - l) ans = [l + 1, r + 1];
      if (hit.get(gems[l]) === 1)
        hit.delete(gems[l]); // 빈도수가 1에서 0이 될 때에는 map에서 제거
      else hit.set(gems[l], hit.get(gems[l]) - 1); //빈도수를 감소
      l++;
    } else {
      //5-2
      r++;
      hit.set(gems[r], (hit.get(gems[r]) || 0) + 1); //빈도수 증가
    }
  }
  return ans;
}

// 또 다른 풀이
function solution(gems) {
  const gemVarietyCounts = new Set(gems).size;
  const gemMap = new Map();
  const gemLengths = [];
  gems.forEach((gem, i) => {
    gemMap.delete(gem);
    gemMap.set(gem, i);
    if (gemMap.size === gemVarietyCounts) {
      gemLengths.push([gemMap.values().next().value + 1, i + 1]);
    }
  });

  gemLengths.sort((a, b) => {
    if (a[1] - a[0] === b[1] - b[0]) {
      return a[1] - b[1];
    }
    return a[1] - a[0] - (b[1] - b[0]);
  });

  return gemLengths[0];
}

// 나의 풀이
// 1차 시도
function solution(gems) {
  var answer = [];
  const gemSet = new Set(gems);
  const length = gems.length,
    max = gemSet.size;
  if (gemSet.size === 1) return [1, 1];
  for (let len = max - 1; len < length; len++) {
    let isExist = false;
    for (let i = 0; i < length - len; i++) {
      const buySet = new Set(gems.slice(i, i + len + 1));
      if (!isEqualSet(buySet, gemSet)) continue;
      answer = [i + 1, i + len + 1];
      isExist = true;
      break;
    }
    if (isExist) break;
  }
  return answer;
}

function isEqualSet(a, b) {
  return a.size === b.size && isEqualValue(a, b);
}

function isEqualValue(a, b) {
  let result = true;
  a.forEach((n) => {
    if (b.has(n)) return 1;
    result = false;
    return 0;
  });
  return result;
}

// 2차 시도
function solution(gems) {
  var answer = [];
  const gemSet = new Set(gems);
  const length = gems.length,
    max = gemSet.size;
  if (gemSet.size === 1) return [1, 1];
  let isExist = false;
  let len = max - 1,
    i = -1;
  while (len < length) {
    if (i >= length - len) {
      i = -1;
      len++;
    }
    i++;
    const buySet = new Set(gems.slice(i, i + len + 1));
    if (!isEqualSet(buySet, gemSet)) continue;
    answer = [i + 1, i + len + 1];
    isExist = true;
    break;
  }
  return answer;
}

function isEqualSet(a, b) {
  return a.size === b.size && isEqualValue(a, b);
}

function isEqualValue(a, b) {
  let result = true;
  a.forEach((n) => {
    if (b.has(n)) return 1;
    result = false;
    return 0;
  });
  return result;
}
