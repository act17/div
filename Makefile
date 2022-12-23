div: sources/main.c sources/tarottools/querytonumber.c sources/tarottools/tarotgen.c sources/tarottools/tarotprint.c sources/tarottools/accuracycheck.c
	gcc -o $@ $^ -Werror -Wpedantic -g
clean:
	rm div
