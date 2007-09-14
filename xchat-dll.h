#ifndef _DLL_H_
#define _DLL_H_
#define PNAME "Lond's Script"
#define PDESC "Auto cor, google color, correção e outras tantas coisas";
#define PVERSION "0.1"

#ifndef _XCHAT_DLL_
#define _XCHAT_DLL_
#endif

extern "C"
{
	int xchat_plugin_init(xchat_plugin *plugin_handle,
                      char **plugin_name,
                      char **plugin_desc,
                      char **plugin_version,
                      char *arg);
	void xchat_plugin_get_info(char **name, char **desc, char **version, void **reserved);

}
#endif /* _DLL_H_ */
