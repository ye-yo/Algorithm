#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

int M, N;
int arr[MAX][MAX] = {0,};
int cornerCount = 0;

struct Position {
  int x;
  int y;
  int direction; //우: 1, 하 : 2, 좌 : 3, 상 : 4
};

Position getNextPosition(Position pos){
  switch (pos.direction){
    case 1:
      pos.y++;
      break;
    case 2:
      pos.x++;
      break;
    case 3:
      pos.y--;
      break;
    case 4:
      pos.x--;
    break;
    default:break;
  }
  return pos;
}

Position move(Position pos)
{
  Position temp = {pos.x, pos.y, pos.direction};
  temp = getNextPosition(temp);
  int nextX = temp.x;
  int nextY = temp.y;

  if(nextX >= M || nextY >= N || nextX < 0 || nextY < 0 || arr[nextX][nextY] > 0){
    cornerCount++;
    pos.direction = pos.direction >= 4 ? 1 : ++pos.direction;
    pos = getNextPosition(pos);
    return pos;
  }
  return temp;
}

int main(void)
{
  cin >> M >> N;

  int i = 0;
  int j = 0;
  int emptyCell = M * N;
  Position pos = {0, 0, 1};
  while (true)
  {
    arr[pos.x][pos.y] = 1;
    emptyCell--;
    pos = move(pos);
    if (emptyCell == 1)
        break;
  }
  printf("%d\n", cornerCount);
  return 0;
}