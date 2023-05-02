AC_INIT([xymon], [4.3.30], [clabbe.montjoie@gmail.com])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_PREREQ
AC_PROG_CC
AM_PROG_AR
AC_PROG_RANLIB
AC_CONFIG_HEADERS([include/config.h])

AM_CONDITIONAL([IS_NUNUX], [test `uname` = 'Linux'])
AM_CONDITIONAL([IS_SOLARIS], [test `uname` = 'SunOS'])
AM_CONDITIONAL([IS_OPENBSD], [test `uname` = 'OpenBSD'])
AM_CONDITIONAL([IS_NETBSD], [test `uname` = 'NetBSD'])
AM_CONDITIONAL([IS_FREEBSD], [test `uname` = 'FreeBSD'])

AM_COND_IF(IS_NUNUX,
	CPPFLAGS="$CPPFLAGS -I/usr/include/tirpc")
AM_COND_IF(IS_FREEBSD,
	CPPFLAGS="$CPPFLAGS -I/usr/local/include"
	LDFLAGS="$LDFLAGS -L/usr/local/lib"
	)
AM_COND_IF(IS_NETBSD,
	CPPFLAGS="$CPPFLAGS -I/usr/pkg/include"
	LDFLAGS="$LDFLAGS -L/usr/pkg/lib"
	)
AM_COND_IF(IS_OPENBSD,
	CPPFLAGS="$CPPFLAGS -I/usr/local/include"
	LDFLAGS="$LDFLAGS -L/usr/local/lib"
	)

AC_ARG_ENABLE(server, AS_HELP_STRING(TODO),
	AM_CONDITIONAL([SERVERBUILD], true),
	[
	CFLAGS="$CFLAGS -DCLIENTONLY"
	AM_CONDITIONAL([SERVERBUILD], false)
	])

AC_ARG_VAR(XYMONTOPDIR,
	[TODO])
AC_ARG_VAR(XYMONCLIENTHOME,
	[TODO])
AC_ARG_VAR(XYMONLOGDIR,
	[TODO])
AC_ARG_VAR(XYMONHOSTNAME,
	[TODO])
AC_ARG_VAR(XYMONHOSTIP,
	[TODO])
AC_ARG_VAR(XYMONHOSTOS,
	[TODO])

AC_CHECK_HEADERS([fcntl.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADERS([rpc/rpc.h])

AC_CHECK_FUNCS([strerror])
AC_CHECK_FUNCS([snprintf])
AC_CHECK_FUNCS([vsnprintf])
# TODO dead code not compiling when no setenv
AC_CHECK_FUNCS([setenv])

AC_CHECK_TYPES([socklen_t], [], [], [arpa/inet.h])

AC_C_INLINE

AC_FUNC_MALLOC

dnl
dnl Check for mandatory libs
dnl
#PKG_CHECK_MODULES(PCRE, libpcre)
#CFLAGS="$CFLAGS $PCRE_CFLAGS"
#LDFLAGS="$LDFLAGS $PCRE_LDFLAGS"
AS_IF([test "x$enable_server" = "xyes"],
	[
	AC_CHECK_HEADERS([pcre.h], [], AC_MSG_ERROR([a working pcre is needed]))
	AC_CHECK_LIB(pcre, pcre_compile,
		[
		LDFLAGS="$LDFLAGS -lpcre"
		]
		,AC_MSG_ERROR([a working pcre is needed]))

	AC_CHECK_HEADERS([ares.h], [], AC_MSG_ERROR([a working cares is needed]))
	AC_CHECK_HEADERS([ares_dns.h], [], AC_MSG_ERROR([a working cares is needed]))
	AC_CHECK_HEADERS([ares_version.h], [], AC_MSG_ERROR([a working cares is needed]))
	AC_CHECK_LIB(cares, ares_version,
		[
		LDFLAGS="$LDFLAGS -lcares"
		]
		,AC_MSG_ERROR([a working cares is needed]))
	]
)

dnl
dnl Check for optionnal
dnl
AC_ARG_WITH([rrd],
	AS_HELP_STRING([--with-rrd] [TODO]),
	[with_rrd=yes],
	[with_rrd=no])

#if test "x$with_rrd" = "xyes";then
AS_IF([test "x$with_rrd" = "xyes"],
	[
	AC_CHECK_HEADERS([rrd.h])
	AC_CHECK_LIB([rrd], [rrd_update],
		[
			LDFLAGS="$LDFLAGS -lrrd"
			AM_CONDITIONAL([HAVE_RRD], true)
		],
		AC_MSG_ERROR([aworking rrd is needed])
		)
	],[
	AM_CONDITIONAL([HAVE_RRD], false)
	]
)
AC_CONFIG_FILES([
 Makefile
])
AC_OUTPUT

cat <<EOF

------------------ Summary ------------------
  Prefix.........: $prefix
  C Compiler.....: $CC $CFLAGS $CPPFLAGS
  Linker.........: $LD $LDFLAGS $LIBS
---------------------------------------------

Check the above options and compile with:
 ${MAKE-make}

EOF
