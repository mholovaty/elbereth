dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(spam, 1.0)
AC_PROG_CC

dnl Initialize automake
AM_INIT_AUTOMAKE

AM_PROG_CC_C_O 

dnl Initialize Libtool
LT_INIT

dnl Check if Libtool is present
dnl Libtool is used for building share libraries 
AC_PROG_LIBTOOL

dnl Check Python
AM_PATH_PYTHON(2.7)
PY_PREFIX=`$PYTHON -c 'import sys ; print sys.prefix'`
PYTHON_LIBS="-lpython$PYTHON_VERSION"
PYTHON_CFLAGS="-I$PY_PREFIX/include/python$PYTHON_VERSION"
AC_SUBST([PYTHON_LIBS])
AC_SUBST([PYTHON_CFLAGS])

AC_CONFIG_FILES(Makefile
                spam/Makefile
                include/Makefile)
AC_OUTPUT