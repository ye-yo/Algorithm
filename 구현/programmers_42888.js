//BEST 풀이
function solution(record) {
  const userInfo = {};
  const action = [];
  const stateMapping = {
    Enter: "님이 들어왔습니다.",
    Leave: "님이 나갔습니다.",
  };

  record.forEach((v) => {
    const [state, id, nick] = v.split(" "); //비구조화 할당. 없는 원소는 undefined 처리되서 괜찮음

    if (state !== "Change") {
      action.push([state, id]); // change외에 최종 배열에 들어갈 요소들만 푸시해서 반복 횟수 줄임
    }

    if (nick) {
      userInfo[id] = nick;
    }
  });

  return action.map(([state, uid]) => {
    // 배열에 담을 때 배열 안에 배열 담아서 id, action 모두 참조 가능
    return `${userInfo[uid]}${stateMapping[state]}`;
  });
}

//나의 풀이
function solution(record) {
  var answer = [];
  const userMap = {};
  const actions = {
    Enter: "들어왔습니다.",
    Leave: "나갔습니다.",
  };
  record.forEach((log) => {
    const message = log.split(" ");
    if (message.length > 2) {
      userMap[message[1]] = message[2];
    }
    answer;
  });
  record.forEach((log) => {
    const message = log.split(" ");
    if (message[0] === "Change") {
      return false;
    }
    answer.push(`${userMap[message[1]]}님이 ${actions[message[0]]}`);
  });
  return answer;
}
