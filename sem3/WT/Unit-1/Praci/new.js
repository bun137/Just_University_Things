let workeri = {
     postmessage : null //function add(x,y){ console.log(x+y);}
}

workeri.postmessage = (x,y) => {
    console.log(x+y);
}

workeri.postmessage(2,3);
let a = 2;
let b = 3;
workeri.postmessage(a,b);
workeri.postmessage("a","b");
workeri.postmessage("shre", " anur");
