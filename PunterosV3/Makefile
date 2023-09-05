OPT=
CFLAGS=-std=c18 -Wall
MAK= make --no-print-directory
SHELL=bash -o pipefail

readme:
	less README.txt

%.bin : %.c
	$(CC) $(CFLAGS) $(OPT) $^ -o $@

%.bin-g : %.c
	$(CC) $(CFLAGS) $(OPT) -g $^ -o $@

%.bin-san : %.c
	$(CC) $(CFLAGS) $(OPT) -g -fsanitize=address $^ -o $@

%.run :
	@$(MAK) $(*F).bin
	./$(*F).bin

%.run-san :
	@$(MAK) $(*F).bin-san
	./$(*F).bin-san

%.run-g :
	@$(MAK) $(*F).bin-g
	./$(*F).bin-g

%.ddd :
	@$(MAK) $(*F).bin-g
	ddd --command prolog.gdb $(*F).bin-g &

%.ddd-san :
	@$(MAK) $(*F).bin-san
	ddd --command prolog.gdb $(*F).bin-san &

%.run-vg :
	@$(MAK) $(*F).bin-g
	valgrind --leak-check=full ./$(*F).bin-g

clean:
	rm -f *.o *.bin*
