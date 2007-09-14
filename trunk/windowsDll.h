#ifndef _DLL_H_
#define _DLL_H_

#ifndef _MIRC_DLL_
#define _MIRC_DLL_

/*#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else  Not BUILDING_DLL 
# define DLLIMPORT __declspec (dllimport)
#endif  Not BUILDING_DLL 


class DLLIMPORT DllClass
{
  public:
    DllClass();
    virtual ~DllClass(void);

  private:

};
*/

typedef struct {
   DWORD  mVersion;
   HWND   mHwnd;
   BOOL   mKeep;
} LOADINFO;

extern "C"
{
		int __stdcall init_func(HWND mWnd, HWND aWnd, char *data, char *parms, BOOL print, BOOL nopause);
		void __stdcall LoadDll(LOADINFO* linfo);
		int __stdcall UnloadDll(int mTimeout);
		int __stdcall colorir(HWND mWnd, HWND aWnd, char *data, char *parms, BOOL print, BOOL nopause);
}
#endif /* _MIRC_DLL_ */
#endif /* _DLL_H_ */
