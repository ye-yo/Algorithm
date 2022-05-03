function pushBucket(bucket, newDoll) {
  let cnt = 0;
  let dollId = newDoll;
  bucket.push(dollId);
  for (let i = bucket.length - 1; i > 0; i--) {
    if (bucket[i] != bucket[i - 1]) break;
    cnt += 2;
    bucket.splice(i - 1, 2);
  }
  return cnt;
}

function solution(board, moves) {
  var answer = 0;
  const bucket = [];
  for (let k = 0; k < moves.length; k++) {
    const j = moves[k] - 1;
    for (let i = 0; i < board[0].length; i++) {
      if (!board[i][j]) continue;
      answer += pushBucket(bucket, board[i][j]);
      board[i][j] = 0;
      break;
    }
  }

  return answer;
}
