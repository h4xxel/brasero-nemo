CFLAGS	= -fPIC -shared -Wall -O2 -DGETTEXT_PACKAGE=\""nemo-extensions"\" `pkg-config --cflags libnemo-extension libbrasero-burn3 libbrasero-media3`
LDFLAGS = `pkg-config --libs libnemo-extension libbrasero-burn3 libbrasero-media3`

.PHONY: clean

libnemo-brasero.so: nemo-burn-bar.o nemo-burn-extension.o brasero-utils.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

nemo-burn-bar.o: nemo-burn-bar.c nemo-burn-bar.h
nemo-burn-extension.o: nemo-burn-extension.c nemo-burn-bar.h brasero-utils.h
brasero-utils.o: brasero-utils.c brasero-utils.h

clean:
	$(RM) *.o *.so
