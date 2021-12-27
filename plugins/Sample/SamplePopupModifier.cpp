#include <precomp.h>
#include "SamplePopupModifier.h"
#include "SampleConfigPage.h"

_DECLARE_SERVICETSINGLE(svc_ClipXPopupModifier, SamplePopupModifier);

#define ID_ENABLEDISABLE 0

// called when clipx is constructing the system tray popup menu, add your items here
void SamplePopupModifier::customizeSystrayMenu(ClipXMenuHandler *menu) {
  // add to the bottom
  // menu->addMenuItem(MF_STRING|(g_enabled?MF_CHECKED:0), ID_ENABLEDISABLE, "Enable Item Size Limits");
}

// called when clipx is constructing the clipboard history menu, add your items here
void SamplePopupModifier::customizeHistoryMenu(ClipXMenuHandler *menu, int is_hotkey, int is_submenu) {
  if (is_submenu) {
    // add to the top
    menu->insertMenuItem(MF_STRING|(g_enabled?MF_CHECKED:0), ID_ENABLEDISABLE, "Enable Item Size Limits");
  }
}

// command callback for your popup items
void SamplePopupModifier::onCommand(int cmd) {
  switch (cmd) {
    case ID_ENABLEDISABLE:
      g_enabled = !g_enabled;
      if (IsWindow(g_last_dlg)) 
        SendMessage(g_last_dlg, WM_USER+0x100, 0, 0);
      break;
  }
}
