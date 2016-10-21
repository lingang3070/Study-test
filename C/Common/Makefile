#for mv500
TOPDIR=..
include $(TOPDIR)/rules.mk

CFLAGS += 

OBJS=$(patsubst %.c,%.o,$(wildcard $(SRCDIR)/*.c))

LIB = $(LIBDIR)/libserver.a

all: $(LIB)


$(LIB): $(OBJS)
	@mkdir -p $(LIBDIR)
#	$(AR) -cr $@ $(OBJS) 
#	$(RANLIB) $@
	
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	

clean:
	rm $(SRCDIR)/*.o $(LIBDIR)/*.a -f
	
