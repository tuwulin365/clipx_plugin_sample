#include <precomp.h>
#include "ClipXConfigPage.h"

// CLIPX PLUGIN SDK - DO NOT MODIFY

#define CBCLASS ClipXConfigPageI
START_DISPATCH;
  CB(SVC_CLIPX_CONFIGPAGE_GETPAGETITLE, getPageTitle);
  CB(SVC_CLIPX_CONFIGPAGE_CREATEPAGE, createPage);
  VCB(SVC_CLIPX_CONFIGPAGE_ONDESTROYPAGE, onDestroyPage);
  VCB(SVC_CLIPX_CONFIGPAGE_COPYSETTINGS, copySettings);
  VCB(SVC_CLIPX_CONFIGPAGE_APPLYSETTINGS, applySettings);
  VCB(SVC_CLIPX_CONFIGPAGE_SAVESETTINGS, saveSettings);
  VCB(SVC_CLIPX_CONFIGPAGE_LOADSETTINGS, loadSettings);
END_DISPATCH;
#undef CBCLASS
