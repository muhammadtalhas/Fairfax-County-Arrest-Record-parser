#-----------------------------------------------------------------------------
# Choose a compiler & its options
#--------------------------------------------------------------------------

CC   = gcc
OPTS = -W -O0 -g

#--------------------------------------------------------------------------
# Add the debug flag (based on the #ifndef in the source files)
#--------------------------------------------------------------------------
#DEBUG=-D

#--------------------------------------------------------------------------
# Add the names of the directories
#--------------------------------------------------------------------------
SRCDIR=./src
OBJDIR=./obj
INCDIR=./include
BINDIR=./bin

#--------------------------------------------------------------------
# Add the rest of the source files. Don't forget to add the '\' character
# to continue the line. You don't need it after the last source file
#--------------------------------------------------------------------
SRCS=$(SRCDIR)/runner.c \
$(SRCDIR)/download.c 

#--------------------------------------------------------------------
# You don't need to edit the next few lines. They define other flags
# used in the compilation of the source code
#--------------------------------------------------------------------
INCLUDE = $(addprefix -I,$(INCDIR))
OBJS=${SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o}
CFLAGS   = $(OPTS) $(INCLUDE) $(DEBUG)

#--------------------------------------------------------------------
# Add the name of the executable after the $(BINDIR)/
#--------------------------------------------------------------------
TARGET = $(BINDIR)/dataPuller

all: $(TARGET)

$(TARGET): $(OBJS) 
	${CC} ${CFLAGS} -o $@ $(OBJS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
cleanall:
	rm -f $(OBJS)
	rm -f $(TARGET)
#--------------------------------------------------------------------
# Add a target named cleanall that will remove the object files as well
# as the executable
#--------------------------------------------------------------------



