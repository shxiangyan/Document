xelatex -no-pdf -quiet -time-statistics main.tex
bibtex main.aux
xelatex -no-pdf -quiet -time-statistics main.tex
xelatex -quiet -time-statistics main.tex
