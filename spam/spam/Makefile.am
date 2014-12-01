pyexec_LTLIBRARIES = spam.la

spam_la_SOURCES = spam.c
spam_la_LDFLAGS = -module -avoid-version -export-symbols-regex initspam
spam_la_CPPFLAGS = $(PYTHON_CFLAGS) -I$(top_srcdir)/include
