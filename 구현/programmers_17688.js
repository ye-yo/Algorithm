function solution(str1, str2) {
  var answer = 0;
  const a = [],
    b = [];
  const eng = /^[A-Z]*$/;
  for (let i = 0; i < str1.length - 1; i++) {
    const word = str1.slice(i, i + 2).toUpperCase();
    if (eng.test(word)) a.push(word);
  }

  let str = a.join(" ");
  for (let i = 0; i < str2.length - 1; i++) {
    const word = str2.slice(i, i + 2).toUpperCase();
    if (!eng.test(word)) continue;
    b.push(word);
    if (str.includes(word)) {
      str = str.replace(new RegExp(word), "");
      answer++;
    }
  }
  const union = a.length + b.length;
  answer = union - answer === 0 ? 1 : answer / (union - answer);
  return parseInt(answer * 65536);
}
