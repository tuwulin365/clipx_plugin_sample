#include <precomp.h>
#include "plugin.h"
#include "SampleConfigPage.h"
#include "resource.h"

_DECLARE_SERVICETSINGLE(svc_ClipXConfigPage, SampleConfigPage);

// the name that appears in the config list
const char *SampleConfigPage::getPageTitle() {
  return "Limits";
}

// settings, with default values
int g_enabled = 1;
int g_enforce_max_text_size = 0;
int g_max_text_size = 32767;
int g_enforce_min_text_size = 0;
int g_min_text_size = 16;
int g_enforce_max_bmp_size = 0;
int g_max_bmp_size = 640*480*4;
int g_enforce_min_bmp_size = 0;
int g_min_bmp_size = 16*16*4;

// temp values
int t_enforce_max_text_size=0;
int t_max_text_size=0;
int t_enforce_min_text_size=0;
int t_min_text_size=0;
int t_enforce_max_bmp_size=0;
int t_max_bmp_size=0;
int t_enforce_min_bmp_size=0;
int t_min_bmp_size=0;
int t_enabled=0;

// load settings from ini
void SampleConfigPage::loadSettings(const char *inifile, const char *section) {
  g_enforce_min_text_size = GetPrivateProfileInt(section, "limits_enforce_min_text_size", g_enforce_min_text_size, inifile);
  g_enforce_max_text_size = GetPrivateProfileInt(section, "limits_enforce_max_text_size", g_enforce_max_text_size, inifile);
  g_enforce_min_bmp_size = GetPrivateProfileInt(section, "limits_enforce_min_bmp_size", g_enforce_min_bmp_size, inifile);
  g_enforce_max_bmp_size = GetPrivateProfileInt(section, "limits_enforce_max_bmp_size", g_enforce_max_bmp_size, inifile);
  g_min_text_size = GetPrivateProfileInt(section, "limits_min_text_size", g_min_text_size, inifile);
  g_max_text_size = GetPrivateProfileInt(section, "limits_max_text_size", g_max_text_size, inifile);
  g_min_bmp_size = GetPrivateProfileInt(section, "limits_min_bmp_size", g_min_bmp_size, inifile);
  g_max_bmp_size = GetPrivateProfileInt(section, "limits_max_bmp_size", g_max_bmp_size, inifile);
  g_enabled = GetPrivateProfileInt(section, "limits_enabled", g_enabled, inifile);
}

// save settings to ini
void SampleConfigPage::saveSettings(const char *inifile, const char *section) {
  WritePrivateProfileString(section, "limits_enforce_min_text_size", StringPrintf("%d", g_enforce_min_text_size), inifile);
  WritePrivateProfileString(section, "limits_enforce_max_text_size", StringPrintf("%d", g_enforce_max_text_size), inifile);
  WritePrivateProfileString(section, "limits_enforce_min_bmp_size", StringPrintf("%d", g_enforce_min_bmp_size), inifile);
  WritePrivateProfileString(section, "limits_enforce_max_bmp_size", StringPrintf("%d", g_enforce_max_bmp_size), inifile);
  WritePrivateProfileString(section, "limits_min_text_size", StringPrintf("%d", g_min_text_size), inifile);
  WritePrivateProfileString(section, "limits_max_text_size", StringPrintf("%d", g_max_text_size), inifile);
  WritePrivateProfileString(section, "limits_min_bmp_size", StringPrintf("%d", g_min_bmp_size), inifile);
  WritePrivateProfileString(section, "limits_max_bmp_size", StringPrintf("%d", g_max_bmp_size), inifile);
  WritePrivateProfileString(section, "limits_enabled", StringPrintf("%d", g_enabled), inifile);
}

// settings are copied to temporary variables, which the dialog works on, when the clipx config dialog is brought up 
void SampleConfigPage::copySettings() {
  t_enforce_max_text_size = g_enforce_max_text_size;
  t_max_text_size         = g_max_text_size;
  t_enforce_min_text_size = g_enforce_min_text_size;
  t_min_text_size         = g_min_text_size;
  t_enforce_max_bmp_size  = g_enforce_max_bmp_size;
  t_max_bmp_size          = g_max_bmp_size;
  t_enforce_min_bmp_size  = g_enforce_min_bmp_size;
  t_min_bmp_size          = g_min_bmp_size;
  t_enabled               = g_enabled;
}

// settings are validated when the user clicks ok or apply
void SampleConfigPage::applySettings() {
  g_enforce_max_text_size = t_enforce_max_text_size;
  g_max_text_size         = t_max_text_size;
  g_enforce_min_text_size = t_enforce_min_text_size;
  g_min_text_size         = t_min_text_size;
  g_enforce_max_bmp_size  = t_enforce_max_bmp_size;
  g_max_bmp_size          = t_max_bmp_size;
  g_enforce_min_bmp_size  = t_enforce_min_bmp_size;
  g_min_bmp_size          = t_min_bmp_size;
  g_enabled               = t_enabled;
}

void updateVisibility(HWND hwndDlg) {
  EnableWindow(GetDlgItem(hwndDlg, IDC_ENFORCE_MIN_TEXT), t_enabled);
  EnableWindow(GetDlgItem(hwndDlg, IDC_ENFORCE_MAX_TEXT), t_enabled);
  EnableWindow(GetDlgItem(hwndDlg, IDC_ENFORCE_MIN_BITMAP), t_enabled);
  EnableWindow(GetDlgItem(hwndDlg, IDC_ENFORCE_MAX_BITMAP), t_enabled);
  EnableWindow(GetDlgItem(hwndDlg, IDC_MIN_TEXT), t_enabled && t_enforce_min_text_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_STATIC_MIN_TEXT), t_enabled && t_enforce_min_text_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_MAX_TEXT), t_enabled && t_enforce_max_text_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_STATIC_MAX_TEXT), t_enabled && t_enforce_max_text_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_MIN_BITMAP), t_enabled && t_enforce_min_bmp_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_STATIC_MIN_BITMAP), t_enabled && t_enforce_min_bmp_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_MAX_BITMAP), t_enabled && t_enforce_max_bmp_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_STATIC_MAX_BITMAP), t_enabled && t_enforce_max_bmp_size);
  EnableWindow(GetDlgItem(hwndDlg, IDC_STATIC_ENABLE), t_enabled);
}

HWND g_last_dlg = NULL;

// dialog operates only on temp values, the values are copied from the actual settings prior to running the dialog,
// and copied back to the actual settings when teh user clicks ok or apply
INT_PTR CALLBACK dlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_INITDIALOG:
      g_last_dlg = hwndDlg;
      SetDlgItemInt(hwndDlg, IDC_MIN_TEXT, t_min_text_size, 0);
      SetDlgItemInt(hwndDlg, IDC_MAX_TEXT, t_max_text_size, 0);
      SetDlgItemInt(hwndDlg, IDC_MIN_BITMAP, t_min_bmp_size, 0);
      SetDlgItemInt(hwndDlg, IDC_MAX_BITMAP, t_max_bmp_size, 0);
      CheckDlgButton(hwndDlg, IDC_ENFORCE_MIN_TEXT, t_enforce_min_text_size ? BST_CHECKED : BST_UNCHECKED);
      CheckDlgButton(hwndDlg, IDC_ENFORCE_MAX_TEXT, t_enforce_max_text_size ? BST_CHECKED : BST_UNCHECKED);
      CheckDlgButton(hwndDlg, IDC_ENFORCE_MIN_BITMAP, t_enforce_min_bmp_size ? BST_CHECKED : BST_UNCHECKED);
      CheckDlgButton(hwndDlg, IDC_ENFORCE_MAX_BITMAP, t_enforce_max_bmp_size ? BST_CHECKED : BST_UNCHECKED);
      CheckDlgButton(hwndDlg, IDC_ENABLE, t_enabled ? BST_CHECKED : BST_UNCHECKED);
      updateVisibility(hwndDlg);
      return TRUE;
    case WM_USER+0x100:
      t_enabled = g_enabled;
      CheckDlgButton(hwndDlg, IDC_ENABLE, t_enabled ? BST_CHECKED : BST_UNCHECKED);
      updateVisibility(hwndDlg);
      return 0;
    case WM_COMMAND: {
      int wNotifyCode = HIWORD(wParam);
      int wID = LOWORD(wParam);
      HWND hwndCtl = (HWND) lParam;
      switch (wID) {
        case IDC_ENFORCE_MIN_TEXT: t_enforce_min_text_size = IsDlgButtonChecked(hwndDlg, IDC_ENFORCE_MIN_TEXT); updateVisibility(hwndDlg); g_clipx->config_allowApply(); return 0;
        case IDC_ENFORCE_MAX_TEXT: t_enforce_max_text_size = IsDlgButtonChecked(hwndDlg, IDC_ENFORCE_MAX_TEXT); updateVisibility(hwndDlg); g_clipx->config_allowApply(); return 0;
        case IDC_ENFORCE_MIN_BITMAP: t_enforce_min_bmp_size = IsDlgButtonChecked(hwndDlg, IDC_ENFORCE_MIN_BITMAP); updateVisibility(hwndDlg); g_clipx->config_allowApply(); return 0;
        case IDC_ENFORCE_MAX_BITMAP: t_enforce_max_bmp_size = IsDlgButtonChecked(hwndDlg, IDC_ENFORCE_MAX_BITMAP); updateVisibility(hwndDlg); g_clipx->config_allowApply(); return 0;
        case IDC_ENABLE: t_enabled = IsDlgButtonChecked(hwndDlg, IDC_ENABLE); updateVisibility(hwndDlg); g_clipx->config_allowApply(); return 0;
        case IDC_MIN_TEXT:
        case IDC_MAX_TEXT:
        case IDC_MIN_BITMAP:
        case IDC_MAX_BITMAP:
          if (wNotifyCode == EN_CHANGE) {
            BOOL success = TRUE;
            int value = GetDlgItemInt(hwndDlg, wID, &success, FALSE);
            if (success) {
              switch (wID) {
                case IDC_MIN_TEXT: t_min_text_size = value; return 0;
                case IDC_MAX_TEXT: t_max_text_size = value; return 0;
                case IDC_MIN_BITMAP: t_min_bmp_size = value; return 0;
                case IDC_MAX_BITMAP: t_max_bmp_size = value; return 0;
              }
            }
            g_clipx->config_allowApply(); 
          }
          break;
      }
      break;
    }
    case WM_DESTROY:
      g_last_dlg = NULL;
      break;
  }
  return 0;
}

// create the sub dialog
HWND SampleConfigPage::createPage(HWND parent) {
  return CreateDialog(the->getOSModuleHandle(), MAKEINTRESOURCE(IDD_CONFIGPAGE), parent, dlgProc);
}

