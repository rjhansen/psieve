EXTRA_DIST=psieve.w
bin_PROGRAMS=findprimes factor
BUILT_SOURCES=psieve.cc
findprimes_SOURCES=findprimes.cc psieve.cc
factor_SOURCES=factor.cc psieve.cc

psieve.cc: psieve.w
	ctangle psieve.w
	mv psieve.c psieve.cc

docs:	psieve.w
	cweave -bhp psieve.w
	pdflatex psieve.tex &>/dev/null
	pdflatex psieve.tex &>/dev/null
	rm -f *.tex *.toc *.aux *.idx *.scn *.log

all: findprimes factor docs

clean-local:
	rm -f psieve.cc *.pdf *.o findprimes factor *.tex *.toc *.aux *.idx *.scn *.log *~