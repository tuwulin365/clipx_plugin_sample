#include <precomp.h>
#include "plugin.h"
#include "SampleClipboardMonitor.h"
#include "SampleConfigPage.h"

_DECLARE_SERVICETSINGLE(svc_ClipXClipboardMonitor, SampleClipboardMonitor);

// the user copied some text in the clipboard
int SampleClipboardMonitor::onNewTextClipboard(const char *text) {
  // note: text is guaranteed non null
  int length = strlen(text);
  // if text is bigger than maximum size or smaller than minimum size, prevent clipx from recording this entry
  if ((g_enforce_max_text_size && length > g_max_text_size) || 
      (g_enforce_min_text_size && length < g_min_text_size)) return 0;
  // let clipx record this entry
  return 1;
}

// the user copied a bitmap in the clipboard (HBITMAP format)
int SampleClipboardMonitor::onNewBitmapClipboard(HBITMAP bmp) {
  BITMAP b;
  GetObject(bmp, sizeof(b), &b);
  int w = b.bmWidth;
  int h = b.bmHeight;
  int memused = w * h * 4;
  // if bitmap is bigger than maximum size or smaller than minimum size, prevent clipx from recording this entry
  if ((g_enforce_max_bmp_size && memused > g_max_bmp_size) || 
      (g_enforce_max_bmp_size && memused < g_min_bmp_size)) return 0;
  // let clipx record this entry
  return 1;
}

// the user copied a bitmap in the clipboard (packed DIB format)
int SampleClipboardMonitor::onNewDIBitmapClipboard(BITMAPINFO *dib) {
  // note: dib is guaranteed non null
  int w = dib->bmiHeader.biWidth;
  int h = dib->bmiHeader.biHeight;
  int memused = w * h * 4;
  // if bitmap is bigger than maximum size or smaller than minimum size, prevent clipx from recording this entry
  if ((g_enforce_max_bmp_size && memused > g_max_bmp_size) || 
      (g_enforce_max_bmp_size && memused < g_min_bmp_size)) return 0;
  // let clipx record this entry
  return 1;
}
