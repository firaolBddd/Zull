//Firoal Berehanu
//c++ code to check if a word is a palindrome
//09/11/2023




#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()  {
char word[81];
bool good = true;
char wordspace[81];
cin.getline(wordspace, 81);
//cout << wordspace;
int i;
int v;
int c=0;
for(i = 0; i<= strlen(wordspace); i++){
 if(isalpha(wordspace[i])) {
        // cout << wordspace[i] << "\n";
 word[c] = wordspace[i];
 c++;


 }
}
word[c] = '\0';
//cout << word;
for( v=0; v<= strlen(word); v++ ) {
        if(isupper(word[v])) {
                word[v] = word[v] + 32;


                        }


}
cout << word;
for(int w = 0; w<=strlen(word); w++){
        if(!(word[w]==word[strlen(word)-1-w])){
                good = false;

}}
if(good == true){
        cout<< "    palindrome";

}else {
        cout<< "    not palindrome";

}
return 0;}
