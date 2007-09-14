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

#include "xchat-plugin.h"
#include "xchat-dll.h"
static xchat_plugin *ph;

#include <string>

std::string homeFolder = "~/.xchat2";
#include "dllmain.cpp"

void xchat_plugin_get_info(char **name, char **desc, char **version, void **reserved)
{
   *name = PNAME;
   *desc = PDESC;
   *version = PVERSION;
}

int config_lond ( char *word[], char *word_eol[], void *userdata )
{
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
	string init_str;
	vector<string> token_str;
	vector<string> opt;
	string retorno;
	
	init_str = word_eol[2];
	bool erro;
	configs.init_cfg(erro, retorno, init_str, '\004');
	/*
	token_str = split(init_str, '\004');
	
	for ( int i = 0 ; i < (int)token_str.size() ; i++ )
	{
		if ( token_str.at(i) == string() )
		{
			continue;
		}
		opt = split(token_str.at(i), ':');
		string option = opt.at(0);
		opt.erase(opt.begin());
		
		if ( opt.size() < 1 )
		{
			string erro = "Erro! Formato incorreto em: \"" + option + token_str.at(i) + "\"";
			xchat_commandf(ph, "ECHO %s", erro.c_str());
			return 3;
		}
		else if ( opt.size() > 1 )
		{
			string conc = unify(opt, ':');
			
			if ( option == "ACAts" )
			{
				configs.setAutoColor_antes(conc);
			}
			else if ( option == "ACDep" )
			{
				configs.setAutoColor_depois(conc);
			}
			else if ( option == "NCAts" )
			{
				configs.setNickCompletion_antes(conc);
			}
			else if ( option == "NCDep" )
			{
				configs.setNickCompletion_depois(conc);
			}
			else if ( option == "EmoAts" )
			{
				configs.setEmoticons_antes(conc);
			}
			else if ( option == "EmoDps" )
			{
				configs.setEmoticons_depois(conc);
			}
			else if ( option == "EmoOlhos" )
			{
				configs.setEmoticons_olhos(conc);
			}
			else if ( option == "EmoOlhosNeko" )
			{
				configs.setEmoticons_olhosNeko(conc);
			}
			else if ( option == "EmoBocas" )
			{
				configs.setEmoticons_bocas(conc);
			}
			else if ( option == "PontSimb" )
			{
				configs.setPontuacao_simb(conc);
			}
			else
			{
				string erro = "Erro! Formato incorreto em: \"" + token_str.at(i) + "\"";
				xchat_commandf(ph, "ECHO %s", erro.c_str());
				return 3;
			}
		}
		else
		{
			if ( option == "AutoColor" )
			{
				configs.setAutoColor(strToInt(opt.at(0)));
			}
			else if ( option == "NickCompletion" )
			{
				configs.setNickCompletion(strToInt(opt.at(0)));
			}
			else if ( option == "Emoticons" )
			{
				configs.setEmoticons(strToInt(opt.at(0)));
			}
			else if ( option == "GoogleColor" )
			{
				configs.setGoogleColor(strToInt(opt.at(0)));
			}
			else if ( option == "Pontuacao" )
			{
				configs.setPontuacao(strToInt(opt.at(0)));
			}
			else if ( option == "FraseCorretor" )
			{
				configs.setFraseCorretor(strToInt(opt.at(0)));
			}
			else if ( option == "AntesDepoisPVT" )
			{
				configs.setAntesDepoisPVT(strToInt(opt.at(0)));
			}
			else if ( option == "ACAts" )
			{
				configs.setAutoColor_antes(opt.at(0));
			}
			else if ( option == "ACDep" )
			{
				configs.setAutoColor_depois(opt.at(0));
			}
			else if ( option == "ACCor" )
			{
				configs.setAutoColor_cor(opt.at(0));
			}
			else if ( option == "NCAts" )
			{
				configs.setNickCompletion_antes(opt.at(0));
			}
			else if ( option == "NCDep" )
			{
				configs.setNickCompletion_depois(opt.at(0));
			}
			else if ( option == "EmoAts" )
			{
				configs.setEmoticons_antes(opt.at(0));
			}
			else if ( option == "EmoDep" )
			{
				configs.setEmoticons_depois(opt.at(0));
			}
			else if ( option == "EmoBg" )
			{
				configs.setEmoticons_bg(opt.at(0));
			}
			else if ( option == "EmoCOlhos" )
			{
				configs.setEmoticons_corOlhos(opt.at(0));
			}
			else if ( option == "EmoCBoca" )
			{
				configs.setEmoticons_corBoca(opt.at(0));
			}
			else if ( option == "EmoOlhos" )
			{
				configs.setEmoticons_olhos(opt.at(0));
			}
			else if ( option == "EmoOlhosNeko" )
			{
				configs.setEmoticons_olhosNeko(opt.at(0));
			}
			else if ( option == "EmoBocas" )
			{
				configs.setEmoticons_bocas(opt.at(0));
			}
			else if ( option == "PontSimb" )
			{
				configs.setPontuacao_simb(opt.at(0));
			}
			else
			{
				string erro = "Erro! Constante desconhecida: \"" + option + "\"";
				xchat_commandf(ph, "ECHO %s", erro.c_str());
				return 3;
			}
		}
	}
	retorno = "Informações Armazenadas";
	if ( configs.getFraseCorretor() )
		configs.loadDB();
	configs.ignite();*/
	xchat_commandf(ph, "ECHO %s", retorno.c_str());

	return XCHAT_EAT_ALL;
}

bool completaNick ( string &str )
{
	int tam = str.size();
	string temp = str;
	if ( temp[tam-1] == ':' || temp[tam-1] == ';' || temp[tam-1] == ',' )
	{
		tam--;
		temp = temp.substr(0, tam);
		string clean = string();
		for ( int i = 0 ; i < tam ; i++ )
		{
			if  ( temp[i] == '+' || temp[i] == '(' || temp[i] == '['
					|| temp[i] == '|' || temp[i] == ')' || temp[i] == '?'
					|| temp[i] == '{' || temp[i] == '}' || temp[i] == '$'
					|| temp[i] == '^' || temp[i] == '*' || temp[i] == '.'
					|| temp[i] == '\\')
			{
				clean += '\\';
			}
			clean += temp[i];
		}

		temp = clean;

		if ( tam > 2 )
		{
			if ( xchat_get_info(ph, "channel")[0] == '#' )
			{
				xchat_list *list;
				list = xchat_list_get(ph, "users");
				if ( list )
				{
					while ( xchat_list_next(ph, list) )
					{
						string temp2 = xchat_list_str(ph, list, "nick");

						string s_nick = "(.*)" + temp + "(.*)";
						boost::regex nick(s_nick, boost::regex::icase);
						if ( boost::regex_match(temp2, nick) )
						{
							str = temp2;
							return true;
						}
					}
					xchat_list_free(ph, list);
				}
			}
		}
	}


	return false;
}

int colorir ( char *word[], char *word_eol[], void *userdata )
{
	string treco, nick = string();
	if ( configs.wasIgnited() )
	{
		treco = word_eol[1];
		vector<string> vect = split(treco, ' ');
		if ( configs.getNickCompletion() )
		{
			if ( completaNick(vect.at(0)) )
			{
				nick = vect.at(0);
				vect.erase(vect.begin());
			}
		}
		configs.processaString(vect);
		treco = unify(vect, ' ');
		if ( configs.getAutoColor() )
		{
			if ( xchat_get_info(ph,"channel")[0] == '#' )
				if ( !configs.getNickCompletion() || nick == string())
					treco = configs.getAutoColor_antes() + c_color + configs.getAutoColor_cor() + treco + configs.getAutoColor_depois();
				else
					treco = configs.getNickCompletion_antes() + nick + configs.getNickCompletion_depois() + c_color + configs.getAutoColor_cor() + treco + configs.getAutoColor_depois();
			else if ( configs.getAntesDepoisPVT() )
				treco = configs.getAutoColor_antes() + c_color + configs.getAutoColor_cor() + treco + configs.getAutoColor_depois();
			else
				treco = c_color + configs.getAutoColor_cor() + treco;
		}
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
	
	/*
	s_optim_cor = "([^]*([^]*[^]*|[^]*[^]*)?|[^]*[^]*[^]*)()([0-9][0-9]?,[0-9][0-9]?)(.*)";
	temp = treco;
	optim_cor = s_optim_cor;
	f_optim_cor = "$1$4$5";
	while ( boost::regex_match(temp, optim_cor) )
		temp = boost::regex_replace ( temp , optim_cor, f_optim_cor, boost::match_default | boost::format_all);
	treco = temp;
	*/

	xchat_commandf(ph, "MSG %s %s", xchat_get_info(ph, "channel"), treco.c_str());
	
	return XCHAT_EAT_ALL;
}

int xchat_plugin_init(xchat_plugin *plugin_handle,
                      char **plugin_name,
                      char **plugin_desc,
                      char **plugin_version,
                      char *arg)
{
	/* we need to save this for use with any xchat_* functions */
	ph = plugin_handle;

	/* tell xchat our info */
	*plugin_name = PNAME;
	*plugin_desc = PDESC;
	*plugin_version = PVERSION;

	configs.ignite();
	//configs.setGoogleColor(1);

	xchat_hook_command(ph, "", XCHAT_PRI_NORM, colorir, "", 0);
	xchat_hook_command(ph, "CONFIG", XCHAT_PRI_NORM, config_lond, "Uso: config <opções>; referir ao manual para ver as opções", 0);
	//xchat_hook_print(ph, "Join", XCHAT_PRI_NORM, join_cb, 0);
	xchat_printf(ph,"Lond's Script, Copyright (C) 2007, Renato \"Lond\" Cerqueira");
	xchat_printf(ph,"This program comes with ABSOLUTELY NO WARRANTY; for details type `\\londInfo w'.");
	xchat_printf(ph,"This is free software, and you are welcome to redistribute it");
	xchat_printf(ph,"under certain conditions; type `show c' for details.\n\n");
	xchat_print(ph,"      :::        ::::::::  ::::    ::: :::::::::");
	xchat_print(ph,"     :+:       :+:    :+: :+:+:   :+: :+:    :+:");
	xchat_print(ph,"    +:+       +:+    +:+ :+:+:+  +:+ +:+     +:+");
	xchat_print(ph,"   +#+       +#+    +:+ +#+ +:+ +#+ +#+     +:+");
	xchat_print(ph,"  +#+       +#+    +#+ +#+  +#+#+# +#+     +#+");
	xchat_print(ph," #+#       #+#    #+# #+#   #+#+# #+#    #+#");
	xchat_print(ph,"########## ########  ###    #### #########");
	xchat_print(ph,"      ::::::::   ::::::::  :::::::::  ::::::::::: ::::::::: :::::::::::");
	xchat_print(ph,"    :+:    :+: :+:    :+: :+:    :+:     :+:     :+:    :+:    :+:");
	xchat_print(ph,"   +:+        +:+        +:+    +:+     +:+     +:+    +:+    +:+");
	xchat_print(ph,"  +#++:++#++ +#+        +#++:++#:      +#+     +#++:++#+     +#+");
	xchat_print(ph,"        +#+ +#+        +#+    +#+     +#+     +#+           +#+");
	xchat_print(ph,"#+#    #+# #+#    #+# #+#    #+#     #+#     #+#           #+#");
	xchat_print(ph,"########   ########  ###    ### ########### ###           ###");
	xchat_printf(ph,"                                                     V %s",PVERSION);
	//xchat_print(ph,"Pressione <f9> para configurar");

	return 1;       /* return 1 for success */
}
