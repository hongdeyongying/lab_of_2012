all:epoll_svr_udp epoll_clt_udp epoll_svr_tcp epoll_clt_tcp epoll_svr_udp_org epoll_clt_udp_org 

CC= g++ -ggdb -lpthread

epoll_svr_udp_org:epoll_svr_udp_20170401.cpp
	${CC} -o$@ $<
	
epoll_svr_udp:epoll_svr_udp.cpp
	${CC} -o$@ $<

epoll_clt_udp_org:epoll_clt_udp_20170405.cpp
	${CC} -o$@ $<

epoll_clt_udp:epoll_clt_udp.cpp
	${CC} -o$@ $<

epoll_svr_tcp:epoll_svr_tcp.cpp
	${CC} -o$@ $<
	

epoll_clt_tcp:epoll_clt_tcp.cpp
	${CC} -o$@ $<

clean:
	rm epoll_svr_udp epoll_clt_udp epoll_svr_tcp epoll_clt_tcp epoll_svr_udp_org epoll_clt_udp_org
