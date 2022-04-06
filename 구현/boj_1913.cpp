#include <iostream>
#include <cmath>
using namespace std;
#define MAX 999

int N, target;
int arr[MAX][MAX] = {0,};

struct Position {
  int x;
  int y;
  int direction; //하: 1, 우 : 2, 상 : 3, 좌 : 4
};

Position getNextPosition(Position pos){
  switch (pos.direction){
    case 1:
      pos.x++;
      break;
    case 2:
      pos.y++;
      break;
    case 3:
      pos.x--;
      break;
    case 4:
      pos.y--;
    break;
    default:break;
  }
  return pos;
}

Position move(Position pos)
{
  Position temp = {pos.x, pos.y, pos.direction};
  temp = getNextPosition(temp);
  int prevX = temp.x;
  int prevY = temp.y;

  if(prevX >= N || prevY >= N || prevX < 0 || prevY < 0 || arr[prevX][prevY] > 0){
    pos.direction = pos.direction >= 4 ? 1 : ++pos.direction;
    pos = getNextPosition(pos);
    return pos;
  }
  return temp;
}

int main(void)
{
  cin >> N;
  cin >> target;

  int center = floor(N / 2); // 소수점 내림
  int i = 0;
  int j = 0;
  int num = N * N;
  int targetX, targetY;  
  Position pos = {0, 0, 1};
  while (true)
  {
    if(target == num){
      targetX = pos.x + 1;
      targetY = pos.y + 1;
    }
    arr[pos.x][pos.y] = num--;
    if (pos.x == center && pos.y == center)
      break;
    pos = move(pos);
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("%d %d\n", targetX,targetY);
  return 0;
}