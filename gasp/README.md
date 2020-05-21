The command

> $ ./gasp [options] STRING FILE...

should read the listed files (FILE...) and copy each line
from the input to stdout if it contains STRING anywhere.
Each output line is preceded by the name of the file it is in. 

Options (does not handle multi-character combinations):

-i: Ignore case when searching for lines that contain STRING

-n: Number lines in output