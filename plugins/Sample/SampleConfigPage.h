#ifndef SAMPLE_CONFIGPAGE_H
#define SAMPLE_CONFIGPAGE_H

#include <ClipXConfigPage.h>

extern int g_enabled;
extern int g_enforce_max_text_size;
extern int g_max_text_size;
extern int g_enforce_min_text_size;
extern int g_min_text_size;
extern int g_enforce_max_bmp_size;
extern int g_max_bmp_size;
extern int g_enforce_min_bmp_size;
extern int g_min_bmp_size;

extern HWND g_last_dlg;

class SampleConfigPage : public ClipXConfigPage {
  // return the name that appears in the config list
  virtual const char *getPageTitle();
  // save settings to ini
  virtual void saveSettings(const char *inifile, const char *section);
  // load settings from ini
  virtual void loadSettings(const char *inifile, const char *section);
  // create and return the config page
  virtual HWND createPage(HWND parent);
  // settings should be copied to dialog's work variables
  virtual void copySettings();
  // settings should be validated (user clicked ok/apply)
  virtual void applySettings();
};

#endif
