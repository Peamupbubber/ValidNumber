# isNumber

My solution to the Valid Number Leetcode challenge [here](https://leetcode.com/problems/valid-number/).

I converted the given prompt into a context-free grammer and built a recursive descent parser to handle the cases.

The grammer:
S  -> I E | D E | e  
I  -> A DIGITS   
D  -> A DP  
A  -> SIGN | e  
DP -> DIGITS DOT | DIGITS DOT DIGITS | DOT DIGITS  
E  -> SCI I | e  

The scanner tokens are:  
SIGN   -> [+-]  
DIGITS -> [0-9][0-9]*  
DOT    -> [.]  
SCI    -> [eE]  
EMPTY  -> []  
ERR    -> .  
