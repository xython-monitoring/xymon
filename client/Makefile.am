bin_PROGRAMS = logfetch

logfetch_SOURCES = logfetch.c
logfetch_LDADD = $(top_srcdir)/lib/libxymonclient.a
logfetch_CPPFLAGS = -I $(top_srcdir)/include

if IS_NETBSD
bin_PROGRAMS += netbsd-meminfo
netbsd_meminfo_SOURCES = netbsd-meminfo.c
endif

if IS_FREEBSD
bin_PROGRAMS += freebsd-meminfo
freebsd_meminfo_SOURCES = freebsd-meminfo.c
endif

