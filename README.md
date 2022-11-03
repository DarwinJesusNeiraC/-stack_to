# Stack implementation in C++ 11

This is for the **object technology** course of the Systems Engineer career of the Universidad Nacional de San Agustin de Arequipa.


# Stack Abstract Data Type
## Types
```
 - S: Stack
 - I, F: ELEMENT
```
## Signatures
```
 - new     :           -->  STACK
 - push    : STACK x E -->  STACK
 - pop     : STACK x E -->  STACK
 - top     : STACK     -/-> ELEMENT (partial)
 - resize  : STACK     
 - empty   : STACK     -->  BOOL
 ```
## Axioms
```
 - pop(new) == newStack
 - pop(push(S, I)) == S
 - top(newStack) == undefined
 - top(push(S,I)) == I
 - empty(newStack) == true
 - empty(push(S,I)) == False
 ```
