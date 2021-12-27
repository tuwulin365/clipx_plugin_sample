#include <precomp.h>
#include "plugin.h"

// Construct the plugin object and export it

DECLARE_CLIPX_PLUGIN(SampleClipXPlugin)

// plugin implementation

const char *SampleClipXPlugin::getName() { 
  return "ClipX Limits 1.1"; 
}

GUID SampleClipXPlugin::getGUID() { 
  // This is the GUID for your plugin, you must change it to your own when you create your own plugin.
  // To do this, use GUIDGEN.EXE, which comes with Microsoft VisualC++
  // {6D9F9C9E-99BC-4573-8C2B-A163B53B0B2E}
  static const GUID PLUGIN_GUID = 
  { 0x6d9f9c9e, 0x99bc, 0x4573, { 0x8c, 0x2b, 0xa1, 0x63, 0xb5, 0x3b, 0xb, 0x2e } };
  return PLUGIN_GUID; 
}

void SampleClipXPlugin::onCreate() {
  // plugin is loaded
}

void SampleClipXPlugin::onDestroy() {
  // plugin is unloaded
}

void SampleClipXPlugin::about(HWND parent) {
  MessageBox(parent, "ClipX Limits 1.1 - Sample ClipX Plugin\nFrancis Gastellu - 2004", "About This Plugin", MB_ICONINFORMATION|MB_OK);
}

