all:
	gcc server.c -o server -lrt
	gcc client.c -o client -lrt
	./server&
	sleep 1
	./client
