dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(cs512, 0.0.1)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_CONFIG_MACRO_DIR([m4])

PKG_CHECK_MODULES(OPENCV, opencv, HAVE_OPENCV=yes, HAVE_OPENCV=no)

AC_SUBST(OPENCV_CFLAGS)
AC_SUBST(OPENCV_LIBS)

if test "x$HAVE_OPENCV" = "xno"; then
   AC_MSG_ERROR(OpenCV libraries could not be found)
fi

AM_OPTIONS_WXCONFIG
reqwx=2.4.0
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.
 
		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

