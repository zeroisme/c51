CC = sdcc
CLEAN_SUFFIXS = .asm .lst .mem .rel .rst .sym .lk .hex .ihx .map

stctool = stcgal # 烧录工具
protocol = stc89
upload_port = /dev/ttyUSB0

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.rel, $(SRC))

%.rel: %.c
	$(CC) -c $< -o $@

main.hex: $(OBJ)
	$(CC) $(OBJ) -o $@

upload: main.hex
	@echo "开始烧录程序......"
	$(stctool) -P $(protocol) -p $(upload_port) main.hex
	@echo "清理文件......"
	make clean

clean:
	rm -f $(foreach i, $(CLEAN_SUFFIXS), *$(i))