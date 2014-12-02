dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(count-change, 1.0)


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([-Wall -Werror])

PKG_CHECK_MODULES([GLIB], [glib-2.0])
AC_SUBST([GLIB_CFLAGS])
AC_SUBST([GLIB_LIBS])

AC_PROG_CC

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT
