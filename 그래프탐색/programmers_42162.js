function bfs(start, n, computers, visited) {
  const queue = [];
  queue.push(start);
  while (queue.length > 0) {
    const cur = queue.pop();
    if (visited[cur]) continue;
    visited[cur] = 1;
    for (let i = 0; i < n; i++) {
      if (!computers[cur][i] || visited[i]) continue;
      queue.push(i);
    }
  }
}
function solution(n, computers) {
  var answer = 0;
  const visited = new Array(n);
  computers.forEach((computer, index) => {
    if (visited[index]) return 0;
    answer++;
    bfs(index, n, computers, visited);
  });
  return answer;
}
