# Rational Calculator

This is a simple line-oriented calculator used for expressions involving rational numbers. 

* Rationals can be entered as a pair of positive integers separated by a slash: n/d. A positive integer can be represented as n/1. 
* Numbers can be combined in expressions with the operators +, -, *, and % (for division; the / sign isn't used since it is used to enter a single rational value). 
* Spaces and parentheses can be used to separate parts of expressions. 
* The calculator only implements binary operators so it doesn't support unary minus. To compute -r, evaluate 0-r. 
* Expressions must be entered on a single line. The calculator evaluates the expression on each input line and prints the result. 
* The end of input is indicated by typing the end-of-file character (ctrl-D in Linux shell windows). 

The calculator makes no effort to detect or report errors such as illegal input, additional characters on the input line following a complete expression, or rationals with a denominator of 0. If it is unable to make sense out of something, it usually generates the result 0/0 and goes on to process the next input line.