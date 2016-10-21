CC = gcc
INCLUDE_DIRS = /home/aravind/git/mraa/include \
				/home/aravind/git/mraa/api/mraa
CFLAGS = $(addprefix -I,$(INCLUDE_DIRS))
all:
	$(CC) $(CFLAGS) $(arg1) -o obj -lmraa
clean:
	rm -rf obj