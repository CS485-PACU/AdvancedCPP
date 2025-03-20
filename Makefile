#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

SUBDIRS := $(wildcard */.)
SUBDIRSCLEAN := $(addsuffix clean, $(SUBDIRS))

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -f Makefile_linux -C $@

clean: $(SUBDIRSCLEAN)
	@echo $(SUBDIRSCLEAN)

%/.clean: %
	$(MAKE) -f Makefile_linux -C $< clean

.PHONY: all $(SUBDIRS)