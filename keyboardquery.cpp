#include "keyboardquery.hpp"

KeyboardQuery::KeyboardQuery() {
  int major = XkbMajorVersion;
  int minor = XkbMinorVersion;
  int reason;
  display_ = XkbOpenDisplay(NULL, NULL, NULL, &major, &minor, &reason);
}

KeyboardQuery::~KeyboardQuery() {
  if (display_) XCloseDisplay(display_);
}
  
const char* KeyboardQuery::GetRules() {
  XkbRF_VarDefsRec vdr;
  char* tmp = NULL;

  return
    !display_ ? NO_KEYBOARD :
    (XkbRF_GetNamesProp(display_, &tmp, &vdr) && tmp) ?
    tmp : DFLT_XKB_RULES_FILE;
}

const char* KeyboardQuery::GetModel() {
  XkbRF_VarDefsRec vdr;
  char* tmp = NULL;

  return
    !display_ ? NO_KEYBOARD :
    (XkbRF_GetNamesProp(display_, &tmp, &vdr) && vdr.model) ?
    vdr.model : DFLT_XKB_MODEL;
}

const char* KeyboardQuery::GetLayout() {
  XkbRF_VarDefsRec vdr;
  char* tmp = NULL;

  return
    !display_ ? NO_KEYBOARD :
    (XkbRF_GetNamesProp(display_, &tmp, &vdr) && vdr.layout) ?
    vdr.layout : DFLT_XKB_LAYOUT;
}

const char* KeyboardQuery::GetVariant() {
  XkbRF_VarDefsRec vdr;
  char* tmp = NULL;

  if (!display_) return NO_KEYBOARD;

  XkbRF_GetNamesProp(display_, &tmp, &vdr);
  return vdr.variant;
}

const char* KeyboardQuery::GetOptions() {
  XkbRF_VarDefsRec vdr;
  char* tmp = NULL;

  if (!display_) return NO_KEYBOARD;

  XkbRF_GetNamesProp(display_, &tmp, &vdr);
  return vdr.options;
}
