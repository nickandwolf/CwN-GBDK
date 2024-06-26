#
# A Makefile that compiles all .c and .s files in "src" and "res" 
# subdirectories and places the output in a "obj" subdirectory
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = X:/GameBoy/GBDK/

LCC = $(GBDK_HOME)bin/lcc 

# You can set flags for LCC here
# For example, you can uncomment the line below to turn on debug output
LCCFLAGS += -debug
# LCCFLAGS += -v     # Uncomment for lcc verbose output

#Banking?
LCCFLAGS += -Wl-yt0x1B
LCCFLAGS += -Wl-j -Wm-ya4 -autobank -Wb-ext=.rel -Wb-v

# You can set the name of the .gb ROM file here
PROJECTNAME    = CwN-alpha

SRCDIR      = src
OBJDIR      = obj
RESDIR      = res
DATADIR		= data

BINS	    = $(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(DATADIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS       = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)

all:	prepare $(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "data/" to .o object files
$(OBJDIR)/%.o: $(DATADIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)
	if exist "-p" rmdir /Q /S -p
	if exist $(OBJDIR) rmdir /Q /S $(OBJDIR)
#	rm edit $(PROJECTNAME).ihx
	
	
prepare:
	mkdir -p $(OBJDIR)

clean:
#	rm -f  *.ihx *.cdb *.adb *.noi *.map
	if exist "-p" rmdir /Q /S -p
	if exist $(OBJDIR) rmdir /Q /S $(OBJDIR)

