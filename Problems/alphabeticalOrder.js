let senctence = "This is abcd my string";
let flag = true;

let words = senctence.split(" ");
// console.log(words);
let alphaOrder = [];

//brute force approach
for(let i=0;i<words.length;i++){
    flag = true;
    for(let j=0;j<words[i].length-1 && flag === true;j++){
        words[i]=words[i].toLowerCase();
        if(words[i][j]>words[i][j+1]){
            console.log('inside if');
            flag=false;
        }
    }
    if(flag){
        alphaOrder.push(words[i]);
    }
}

console.log(alphaOrder);

