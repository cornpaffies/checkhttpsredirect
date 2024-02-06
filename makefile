checker:
	gcc -o checker checker.c `pkg-config --libs libcurl`

install:
	install checker $(HOME)/.local/bin/httpsredirectchecker

clean:
	rm checker $(HOME)/.local/bin/httpsredirectchecker
