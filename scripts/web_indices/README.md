The purpose of this experiment is to measure the sizes of the current index pages of popular sites. An old list from 100bestwebsites.org was used to generate popular.html.

perform-measurement.sh is used to download a page and compute its size.

parse.sh is used to parse the html list of websites and extract the URLs.

run-experiment.sh is used to execute perform-measurement.sh on each URL.

The extra URLs at the beginning and end of the file were deleted using a sed command that matched for "babelfish" and "100bestwebsites." In addition, there were also two extra wikipedia links ("List_of_Google_products" and "List_of_Yahoo_products"), which were deleted by matching for "List_of_.*_products"

produce-scatterplot.gnuplot is used to plot the results. The .eps file can be viewed with ghostscript (gs) or evince.

* Line 1 labels the x-axis "Rank"
* Line 2 labels the y-axis "Size (Bytes)"
* Line 3 sets the range of the x-axis from 0 to 100
* Line 4 sets the output file as "scatterplot.eps"
* Line 5 makes a scatterplot using the third column of results.txt (which corresponds to the sizes). No legend entry is made for the data set. 

The scatterplot shows that there isn't a significant relationship between the popularity of a site and the size of its index.html file, contrary to the idea that popular sites would have smaller index pages since they need to handle heavier user loads. 