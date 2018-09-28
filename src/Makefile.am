SUBDIRS = functions

jagsmod_LTLIBRARIES = rescorlaWagner.la

rescorlaWagner_la_SOURCES = rescorlaWagner.cc

rescorlaWagner_la_CPPFLAGS = -I$(includedir)/JAGS

rescorlaWagner_la_LIBADD = functions/rescorlaWagnerfunc.la
if WINDOWS
rescorlaWagner_la_LIBADD += -ljags-$(JAGS_MAJOR)
else
rescorlaWagner_la_LIBADD += -ljags
endif

rescorlaWagner_la_LDFLAGS = -module -avoid-version
if WINDOWS
rescorlaWagner_la_LDFLAGS += -no-undefined
endif
