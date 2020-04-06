
all: yan.pdf \

yan.pdf: yan.tex
	xelatex -shell-escape yan.tex
	bibtex yan.aux
	xelatex -shell-escape yan.tex
	xelatex -shell-escape yan.tex
	evince yan.pdf&


.PHONY:clean  
clean:
	-rm -fr *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *~ *.tid *.tms *.pdf *.bak *.blg *.bbl *.gz *.snm *.nav _minted*

