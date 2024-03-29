# 다익스트라(Dijkstra)

> 최단 경로 탐색 알고리즘으로 특정한 정점에서 다른 모든 정점으로 가는 최단 경로를 계산하면 알고리즘이다.

## 풀이 방식

- 정점을 탐색하면서 현재까지 알고 있던 최단 경로를 계속해서 갱신한다.
- 정점 간의 간선 값은 2차원 배열로 저장

- Dist 배열 : 해당 정점까지의 최소 비용 저장. 최소 비용은 Dist를 무한대(INF)로 초기화
- Visited 배열: 방문 정점 표시(혹은 우선순위큐를 사용하는 문제는 if문으로 대체가능)

1. 시작 노드와 직접적으로 연결된 모든 정점들의 Dist를 업데이트
   (1)-3-(2) 1과 2가 3으로 연결되어 있다면 정점 2는 Dist[2] = 3;
   시작 노드는 Dist[시작점]= 0
2. 시작 노드를 방문한 노드로 체크
3. 연결된 정점 중 비용이 가장 적게 드는 정점을 선택해서 위의 과정 반복
   이 때 갱신될 수 있는 정점들은 최소값으로 갱신해줌

## 풀이 팁

https://www.acmicpc.net/board/view/34516

- 정점 비용 비교할 때 `다른 경로로 해당 정점까지 오는 비용(저장된 비용) vs 이전 정점거쳐 해당 정점까지 오는 비용`
- 우선순위큐에 다음으로 탐색할 정점정보를 넣을 때, 새로 업데이트 된 비용 정보를 넣기
- 방문체크 방법

1. visited 배열을 사용

```cpp
int cur = pq.top().second;
int distance = pq.top().first * -1;
pq.pop();
// 이미 방문한 정점이면 넘어감
if (visited[cur]) continue;
```

2. 우선순위큐를 사용할 경우 아래코드로 대체 가능

```cpp
int cur = pq.top().second;
int distance = pq.top().first * -1;
pq.pop();
// 이미 담겨 있는 비용보다 크면 넘어감
if (dist[cur] < distance) continue;
```

- INF는 간선 가중치의 최대값 \* (정점 개수 -1) 보다 큰 값을 사용해야 함
- "서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다."는 조건을 유념하기!
  간선이 들어올 때 두 도시 사이를 이동하는 비용을 무조건 덮어쓰면 안 된다. 나중에 입력된 간선의 비용이 더 크다면 더 적은 비용의 간선이 있음에도 무효가 됨.
