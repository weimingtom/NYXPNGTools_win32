CC := gcc
LD := ld
RM := rm -rf

CFLAGS := -std=c99

OBJS := internal.o NYXPNGTools.o flip_channels.o decrypt_png.o main.o

all: fixpng

fixpng : $(OBJS)
	$(CC) -mconsole $(CFLAGS) -o $@ $(OBJS) -lpng -lz -lws2_32

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean :
	$(RM) *.exe *.o
