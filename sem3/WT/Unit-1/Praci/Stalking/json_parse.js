let stringi =
  '{"namei": "shre","penguini": "anurag","moodi1" : "happy","timei":"1024"}';

let objecti = JSON.parse(stringi);

// console.log(objecti);

let newString = JSON.stringify(objecti);

console.log(newString);