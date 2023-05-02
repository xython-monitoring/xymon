#SUBDIRS = client lib

bin_PROGRAMS = client/logfetch client/msgcache client/clientupdate client/orcaxymon
noinst_LIBRARIES = lib/libxymonclient.a lib/libxymonclientcomm.a

lib_libxymonclient_a_SOURCES = lib/osdefs.c lib/cgiurls.c lib/libcolor-client.a lib/crondate.c lib/digest.c lib/encoding.c lib/errormsg.c lib/holidays.c lib/ipaccess.c lib/md5.c lib/memory.c lib/misc.c lib/msort.c lib/rmd160c.c lib/sha1.c lib/sha2.c lib/sig.c lib/stackio.c lib/strfunc.c lib/suid.c lib/tree.c lib/color.c lib/environ.c lib/timefunc.c
lib_libxymonclient_a_CPPFLAGS = -I $(top_srcdir)/include -DXYMONTOPDIR=\"$(XYMONTOPDIR)\" -DXYMONLOGDIR=\"$(XYMONLOGDIR)\" -DXYMONHOSTNAME=\"$(XYMONHOSTNAME)\" -DXYMONHOSTIP=\"$(XYMONHOSTIP)\" -DXYMONHOSTOS=\"$(XYMONHOSTOS)\" -DXYMONHOME=\"$(XYMONCLIENTHOME)\"
#lib_libxymonclient_a_LIBADD = lib/libenviron-client.a lib/libcolor-client.a lib/libtimefunc-client.a

lib_libxymonclientcomm_a_SOURCES = lib/locator.c lib/loadhosts.c lib/sendmsg.c lib/xymond_ipc.c lib/xymond_buffer.c

#lib_libcolor_client_a_SOURCES = lib/color.c
#lib_libcolor_client_a_CPPFLAGS = -I $(top_srcdir)/include -DCLIENTONLY

#lib_libenviron_client_a_SOURCES = lib/environ.c
#lib_libenviron_client_a_CPPFLAGS = -I $(top_srcdir)/include -DCLIENTONLY -DXYMONTOPDIR=\"$(XYMONTOPDIR)\" -DXYMONLOGDIR=\"$(XYMONLOGDIR)\" -DXYMONHOSTNAME=\"$(XYMONHOSTNAME)\" -DXYMONHOSTIP=\"$(XYMONHOSTIP)\" -DXYMONHOSTOS=\"$(XYMONHOSTOS)\" -DXYMONHOME=\"$(XYMONCLIENTHOME)\"

#lib_libtimefunc_client_a_SOURCES = lib/timefunc.c
#lib_libtimefunc_client_a_CPPFLAGS = -I $(top_srcdir)/include -DCLIENTONLY

client_logfetch_SOURCES = client/logfetch.c
client_logfetch_LDADD = $(top_srcdir)/lib/libxymonclient.a
client_logfetch_CPPFLAGS = -I $(top_srcdir)/include

client_msgcache_SOURCES = client/msgcache.c
client_msgcache_LDADD = $(top_srcdir)/lib/libxymonclient.a
client_msgcache_CPPFLAGS = -I $(top_srcdir)/include

client_clientupdate_SOURCES = client/clientupdate.c
client_clientupdate_LDADD = $(top_srcdir)/lib/libxymonclient.a lib/libxymonclientcomm.a
client_clientupdate_CPPFLAGS = -I $(top_srcdir)/include

client_orcaxymon_SOURCES = client/orcaxymon.c
client_orcaxymon_LDADD = $(top_srcdir)/lib/libxymonclient.a lib/libxymonclientcomm.a
client_orcaxymon_CPPFLAGS = -I $(top_srcdir)/include

# See issue #1
#if IS_NETBSD
#bin_PROGRAMS += client/netbsd-meminfo
#client_netbsd_meminfo_SOURCES = client/netbsd-meminfo.c
#endif

if IS_FREEBSD
bin_PROGRAMS += client/freebsd-meminfo
client_freebsd_meminfo_SOURCES = client/freebsd-meminfo.c
endif

if IS_OPENBSD
bin_PROGRAMS += client/openbsd-meminfo
client_openbsd_meminfo_SOURCES = client/openbsd-meminfo.c
endif

if SERVERBUILD
bin_PROGRAMS += xymonproxy/xymonproxy \
	xymonproxy/xymoncgimsg.cgi \
	xymonnet/xymonnet \
	xymonnet/xymonping \
	xymongen/xymongen \
	xymond/xymond \
	xymond/xymond_channel \
	xymond/xymond_locator \
	xymond/xymond_filestore \
	xymond/xymond_history \
	xymond/xymond_alert

if HAVE_RRD
bin_PROGRAMS +=	xymond/xymond_rrd
endif

noinst_LIBRARIES += lib/libxymon.a lib/libxymontime.a lib/libxymoncomm.a

xymond_xymond_SOURCES = xymond/xymond.c
xymond_xymond_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_channel_SOURCES = xymond/xymond.c
xymond_xymond_channel_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_locator_SOURCES = xymond/xymond_locator.c xymond/xymond_worker.c
xymond_xymond_locator_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_filestore_SOURCES = xymond/xymond_filestore.c xymond/xymond_worker.c
xymond_xymond_filestore_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_history_SOURCES = xymond/xymond_history.c xymond/xymond_worker.c
xymond_xymond_history_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_alert_SOURCES = xymond/xymond_alert.c\
	xymond/xymond_worker.c \
	xymond/do_alert.c
xymond_xymond_alert_LDADD = lib/libxymoncomm.a lib/libxymontime.a

xymond_xymond_rrd_SOURCES = xymond/xymond_rrd.c \
	xymond/xymond_worker.c \
	xymond/do_rrd.c \
	xymond/client_config.c
xymond_xymond_rrd_LDADD = lib/libxymoncomm.a lib/libxymontime.a


xymonproxy_xymonproxy_SOURCES = xymonproxy/xymonproxy.c
xymonproxy_xymonproxy_LDADD = lib/libxymon.a lib/libxymontime.a

xymonproxy_xymoncgimsg_cgi_SOURCES = xymonproxy/xymoncgimsg.c
xymonproxy_xymoncgimsg_cgi_LDADD = lib/libxymon.a lib/libxymontime.a lib/libxymoncomm.a

xymonnet_xymonnet_SOURCES = xymonnet/xymonnet.c \
	xymonnet/contest.c \
	xymonnet/httptest.c \
	xymonnet/httpresult.c \
	xymonnet/ldaptest.c \
	xymonnet/dns.c \
	xymonnet/dns2.c \
	xymonnet/httpcookies.c
xymonnet_xymonnet_LDADD = lib/libxymon.a lib/libxymontime.a lib/libxymoncomm.a

xymonnet_xymonping_SOURCES = xymonnet/xymonping.c
xymonnet_xymonping_LDADD = lib/libxymon.a lib/libxymontime.a

xymongen_xymongen_SOURCES = xymongen/xymongen.c \
	xymongen/loadlayout.c \
	xymongen/loaddata.c \
	xymongen/pagegen.c \
	xymongen/process.c \
	xymongen/wmlgen.c \
	xymongen/rssgen.c \
	xymongen/util.c \
	xymongen/debug.c \
	xymongen/csvreport.c
xymongen_xymongen_LDADD = lib/libxymontime.a lib/libxymoncomm.a
#xymongen_xymongen_LDADD = lib/libxymon.a lib/libxymontime.a lib/libxymoncomm.a

lib_libxymon_a_SOURCES = \
	lib/osdefs.c \
	lib/acklog.c \
	lib/availability.c \
	lib/calc.c \
	lib/cgi.c \
	lib/cgiurls.c \
	lib/clientlocal.c \
	lib/color.c \
	lib/crondate.c \
	lib/digest.c \
	lib/encoding.c \
	lib/environ.c \
	lib/errormsg.c \
	lib/eventlog.c \
	lib/files.c \
	lib/headfoot.c \
	lib/xymonrrd.c \
	lib/holidays.c \
	lib/htmllog.c \
	lib/ipaccess.c \
	lib/loadalerts.c \
	lib/loadcriticalconf.c \
	lib/links.c \
	lib/matching.c \
	lib/md5.c \
	lib/memory.c \
	lib/misc.c \
	lib/msort.c \
	lib/netservices.c \
	lib/notifylog.c \
	lib/acknowledgementslog.c \
	lib/readmib.c \
	lib/reportlog.c \
	lib/rmd160c.c \
	lib/sha1.c \
	lib/sha2.c \
	lib/sig.c \
	lib/stackio.c \
	lib/strfunc.c \
	lib/suid.c \
	lib/timefunc.c \
	lib/tree.c \
	lib/url.c \
	lib/webaccess.c
lib_libxymon_a_CPPFLAGS = -I $(top_srcdir)/include -DXYMONTOPDIR=\"$(XYMONTOPDIR)\" -DXYMONLOGDIR=\"$(XYMONLOGDIR)\" -DXYMONHOSTNAME=\"$(XYMONHOSTNAME)\" -DXYMONHOSTIP=\"$(XYMONHOSTIP)\" -DXYMONHOSTOS=\"$(XYMONHOSTOS)\" -DXYMONHOME=\"$(XYMONCLIENTHOME)\"

lib_libxymontime_a_SOURCES = lib/run.c lib/timing.c

lib_libxymoncomm_a_SOURCES = \
	lib/loadhosts.c \
	lib/locator.c \
	lib/sendmsg.c \
	lib/xymond_ipc.c \
	lib/xymond_buffer.c \
	lib/osdefs.c \
	lib/acklog.c \
	lib/availability.c \
	lib/calc.c \
	lib/cgi.c \
	lib/cgiurls.c \
	lib/clientlocal.c \
	lib/color.c \
	lib/crondate.c \
	lib/digest.c \
	lib/encoding.c \
	lib/environ.c \
	lib/errormsg.c \
	lib/eventlog.c \
	lib/files.c \
	lib/headfoot.c \
	lib/xymonrrd.c \
	lib/holidays.c \
	lib/htmllog.c \
	lib/ipaccess.c \
	lib/loadalerts.c \
	lib/loadcriticalconf.c \
	lib/links.c \
	lib/matching.c \
	lib/md5.c \
	lib/memory.c \
	lib/misc.c \
	lib/msort.c \
	lib/netservices.c \
	lib/notifylog.c \
	lib/acknowledgementslog.c \
	lib/readmib.c \
	lib/reportlog.c \
	lib/rmd160c.c \
	lib/sha1.c \
	lib/sha2.c \
	lib/sig.c \
	lib/stackio.c \
	lib/strfunc.c \
	lib/suid.c \
	lib/timefunc.c \
	lib/tree.c \
	lib/url.c \
	lib/webaccess.c
lib_libxymoncomm_a_CPPFLAGS = -I $(top_srcdir)/include -DXYMONTOPDIR=\"$(XYMONTOPDIR)\" -DXYMONLOGDIR=\"$(XYMONLOGDIR)\" -DXYMONHOSTNAME=\"$(XYMONHOSTNAME)\" -DXYMONHOSTIP=\"$(XYMONHOSTIP)\" -DXYMONHOSTOS=\"$(XYMONHOSTOS)\" -DXYMONHOME=\"$(XYMONCLIENTHOME)\"

endif

AM_CFLAGS=
#AM_LDFLAGS=

AM_CFLAGS+=-Wall
AM_CFLAGS+=-Wextra
#AM_CFLAGS+=-D_FILE_OFFSET_BITS=64
