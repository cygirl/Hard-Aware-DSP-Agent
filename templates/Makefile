# 针对 Ubuntu 环境下的跨平台编译模板
CC = gcc
CFLAGS = -Wall -O3 -pthread -I.
TARGET = dsp_firmware

SRCS = main.c dsp_core.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
