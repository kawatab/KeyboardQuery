#include <iostream>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XKBrules.h>

#ifndef DFLT_XKB_RULES_FILE
#define	DFLT_XKB_RULES_FILE "base"
#endif

#ifndef DFLT_XKB_LAYOUT
#define	DFLT_XKB_LAYOUT "us"
#endif

#ifndef DFLT_XKB_MODEL
#define	DFLT_XKB_MODEL "pc105"
#endif

#ifndef NO_KEYBOARD
#define	NO_KEYBOARD "no keyboard"
#endif

class KeyboardQuery {
public:
  KeyboardQuery();
  ~KeyboardQuery();

  const char* GetLayout();
  const char* GetModel();
  const char* GetOptions();
  const char* GetRules();
  const char* GetVariant();

private:
  Display* display_;
};
