
self.onmessage = function (event){
    console.log(self);
    console.log(event);
    console.log(event.data);
    self.postMessage("heyy nice to see you! -_- no-cheating ik ");
    
}


