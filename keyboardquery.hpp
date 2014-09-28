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
