.PHONY: main.dvi

main.dvi: 
	latex main.tex
	bibtex main.aux
	latex main.tex
	xdvi main.dvi

build:
	latex main.tex
	bibtex main.aux
	pdflatex main.tex
	evince main.pdf
