dist_doc_DATA = programming_guide.tex

if BUILD_MANUAL
doc_DATA = programming_guide.pdf

programming_guide.pdf : programming_guide.tex
	${PDFLATEX} $<
	${PDFLATEX} $<
	${PDFLATEX} $<

clean-local:
	rm *.pdf *.toc *.aux *.log
endif
