/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Yasuhiro Yamakawa <kawatab@yahoo.co.jp>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

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
