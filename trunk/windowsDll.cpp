/*******************************************************************************
 *                                                                             *
 *  Lond's Script - A multipurpose plugin for IRC clients (XChat and mIRC)     *
 *  Copyright (C) 2007, Renato "Lond" Cerqueira                                *
 *                                                                             *
 *  This program is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by       *
 *  the Free Software Foundation, either version 3 of the License, or          *
 *  (at your option) any later version.                                        *
 *                                                                             *
 *  This program is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 *  GNU General Public License for more details.                               *
 *                                                                             *
 *  You should have received a copy of the GNU General Public License          *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
 *                                                                             *
 *******************************************************************************/

#include <windows.h>
#include "windowsDll.h"
#include "dllmain.cpp"

BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
DWORD reason        /* Reason this function is being called. */ ,
LPVOID reserved     /* Not used. */ )
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
		break;
		
		case DLL_PROCESS_DETACH:
		break;
		
		case DLL_THREAD_ATTACH:
		break;
		
		case DLL_THREAD_DETACH:
		break;
	}
	
	/* Returns TRUE on success, FALSE on failure */
	return TRUE;
}


/* Return values:
* 0 means that mIRC should /halt processing.
* 1 means that mIRC should continue processing.
* 2 means that it has filled the data variable with a command which it wants mIRC to perform, and has filled parms with the parameters to use, if any, when performing the command.
* 3 means that the DLL has filled the data variable with the result that $dll() as an identifier should return.
*/
int __stdcall init_func(HWND mWnd, HWND aWnd, char *data, char *parms, BOOL print, BOOL nopause)
{
	string init_str;
	init_str = data;
	bool erro;
	string retorno;
	
	configs.init_cfg(erro, retorno, init_str, '\004');
	
	strcpy(data, retorno.c_str());
	return 3;
	/*
	String de dados para inicializar:
		AutoColor:(1|0)
		Se AutoColor = 1
			ACAts:[^\n\r\t]
			ACCor:([0-9][0-9]?)(,([0-9][0-9]?))?
			ACDep:[^\n\r\t]
		NickCompletion:(1|0)
		Se NickCompletion = 1
			NCAts:[^\n\r\t]
			NCDep:[^\n\r\t]
		Emoticons:(1|0)
		Se Emoticons = 1
			EmoAts:[^\n\r\t]
			EmoBG:[0-9][0-9]?
			EmoCBoca:[0-9][0-9]?
			EmoCOlhos:[0-9][0-9]?
			EmoDep:[^\n\r\t]
			EmoOlhos:[^\n\r\t]
			EmoOlhosNeko:[^\n\r\t]
			EmoBocas:[^\n\r\t]
		GoogleColor: (1|0)
		FraseCorretor: (1|0)
		Pontuacao: (1|0)
		Se Pontuacao = 1
			PontSimb:[^\n\r\t]
		AntesDepoisPVT: (1|0)
	*/
}

void __stdcall LoadDll(LOADINFO* linfo)
{
	//linfo->mKeep = true;
}

int __stdcall UnloadDll(int mTimeout)
{
	if ( !configs.wasIgnited() ) /* Se a dll foi chamada, mas nunca foi iniciada. */
	{
		return 1; /* Pode fechar. */
	}
	return !mTimeout; /* Caso contrário, ela foi iniciada e não pode ser fechada. */
}

int __stdcall colorir(HWND mWnd, HWND aWnd, char *data, char *parms, BOOL print, BOOL nopause)
{
	string treco;
	if ( configs.wasIgnited() )
	{
		treco = data;
		vector<string> vect = split(data, ' ');
		
		configs.processaString(vect);
		
		treco = unify(vect, ' ');
		treco = configs.getAutoColor_antes() + c_color + configs.getAutoColor_cor() + treco + configs.getAutoColor_depois();
	}
	else
	{
		treco = "ERRO! As configurações precisam ser informadas antes de qualquer operação.";
	}
	
	bool optim;
	do
	{
		optim = false;

		string s_optim_cor = "([0-9][0-9]?(,[0-9][0-9]?)?)(|[]*[0-9][0-9]?(,[0-9][0-9]?)?)";
		string temp = treco;
		boost::regex optim_cor("(.*)" + s_optim_cor + "(.*)");
		string f_optim_cor = "$1$4$6";
		while ( boost::regex_match(temp, optim_cor) )
		{
			temp = boost::regex_replace ( temp , optim_cor, f_optim_cor, boost::match_default | boost::format_all);
			optim = true;
		}
		treco = temp;
		
		s_optim_cor = "(([ ]*)|([]*))";
		temp = treco;
		optim_cor = "(.*)" + s_optim_cor + "(.*)";
		f_optim_cor = "$1$3$4$5";
		while ( boost::regex_match(temp, optim_cor) )
		{
			temp = boost::regex_replace ( temp , optim_cor, f_optim_cor, boost::match_default | boost::format_all);
			optim = true;
		}
		treco = temp;

		temp = string();
		bool bolds, unders;
		bolds = unders = false;
		for ( unsigned int i = 0 ; i < treco.size() ; i++ )
		{
			if ( treco[i] == '' )
			{
				bolds = !bolds;
				temp += treco[i];
			}
			else if ( treco[i] == '' )
			{
				unders = !unders;
				temp += treco[i];
			}
			else if ( treco[i] == '' )
			{
				if ( !bolds && !unders )
				{
					int size = 1;
					string t1("");

					if ( size > 0 && treco[i+size] == '' )
					{
						t1 += treco[i+size];
						size++;
					}
					else
					{
						size = -1;
					}
					if ( size > 0 && treco[i+size] >= '0' && treco[i+size] <= '9' )
					{
						t1 += treco[i+size];
						size++;
					}
					else
					{
						size = -1;
					}
					if ( size > 0 && treco[i+size] >= '0' && treco[i+size] <= '9' )
					{
						t1 += treco[i+size];
						size++;
					}
					if ( size > 0 && treco[i+size] == ',' )
					{
						t1 += treco[i+size];
						size++;
					}
					else
					{
						size = -1;
					}
					if ( size > 0 && treco[i+size] >= '0' && treco[i+size] <= '9' )
					{
						t1 += treco[i+size];
						size++;
					}
					else
					{
						size = -1;
					}
					if ( size > 0 && treco[i+size] >= '0' && treco[i+size] <= '9' )
					{
						t1 += treco[i+size];
						size++;
					}

					if ( size > 0 )
					{
						temp += t1;
						i += size - 1;
						optim = true;
					}
					else
					{
						bolds = unders = false;
						temp += treco[i];
					}
				}
				else
				{
					bolds = unders = false;
					temp += treco[i];
				}
			}
			else
			{
				temp += treco[i];
			}
		}

		treco = temp;
	} while ( optim );
	
	strcpy( data , treco.c_str());
	
	return 3;
}


