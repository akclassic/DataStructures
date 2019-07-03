/*
Q) Take a string as an input and output the string with the order of the words reversed but not the letters in the words
ex input: i.am.a.good.boy
   output: boy.good.a.am.i

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s, s2 = "";
        cin >> s;
        for (int i = s.length() - 1; i > 0; i--)
        {
            if (s[i] != '.')
            {
                s2 += s[i];
                s.length();
            }
            else if (s[i] == '.')
            {
                reverse(s2.begin(), s2.end());
                s2 += '.';
                cout << s2;
                s2 = "";
            }
            if(i==0){
                reverse(s2.begin(),s2.end());
            }
        }
        cout<<endl;
    }
    return 0;
}

/*
Js example
var str = 'The.quick.brown.fox.jumps.over.the.lazy.dog';

var words = str.split('.');
let wordsReversed = [];
for(let i = words.length -1; i>=0;i--){
  	wordsReversed.push(words[i]);
	//console.log(words[i]);
}
console.log(wordsReversed);

*/