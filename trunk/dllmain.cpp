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

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <boost/regex.hpp>
#include <fstream>

using namespace std;

class londScript
{
	private:
		bool ignited;
		bool autoColor;
		bool emoticons;
		bool nickCompletion;
		bool googleColor;
		bool fraseCorretor;
		bool antesDepoisPVT;
		bool pontuacao;
		string autoColor_antes;
		string autoColor_depois;
		string autoColor_cor;
		string emoticons_antes;
		string emoticons_depois;
		string emoticons_bg;
		string emoticons_corBoca;
		string emoticons_corOlhos;
		string emoticons_olhos;
		string emoticons_bocas;
		string emoticons_olhosNeko;
		string nickCompletion_antes;
		string nickCompletion_depois;
		string pontuacao_simb;
	
	public:
	londScript() /* Construtor */
	{
		ignited = false;
		autoColor = false;
		emoticons = false;
		nickCompletion = false;
		googleColor = false;
		fraseCorretor = false;
		antesDepoisPVT = false;
		pontuacao = false;
		autoColor_antes = string();
		autoColor_depois = string();
		autoColor_cor = string();
		emoticons_antes = string();
		emoticons_depois = string();
		emoticons_bg = string();
		emoticons_corBoca = string();
		emoticons_corOlhos = string();
		emoticons_olhos = string();
		emoticons_bocas = string();
		emoticons_olhosNeko = string();
		nickCompletion_antes = string();
		nickCompletion_depois = string();
		pontuacao_simb = string();
	}
	
	~londScript() /* Destrutor */
	{
	}
	
	void setAutoColor(bool value)
	{
		autoColor = value;
	}
	
	bool getAutoColor()
	{
		return autoColor;
	}
	
	void setEmoticons(bool value)
	{
		emoticons = value;
	}
	
	bool getEmoticons()
	{
		return emoticons;
	}
	
	void setNickCompletion(bool value)
	{
		nickCompletion = value;
	}
	
	bool getNickCompletion ()
	{
		return nickCompletion;
	}
	
	void setGoogleColor(bool value)
	{
		googleColor = value;
	}
	
	bool getGoogleColor()
	{
		return googleColor;
	}
	
	void setFraseCorretor(bool value)
	{
		fraseCorretor = value;
	}
	
	bool getFraseCorretor()
	{
		return fraseCorretor;
	}
	
	void setAntesDepoisPVT(bool value)
	{
		antesDepoisPVT = value;
	}
	
	bool getAntesDepoisPVT()
	{
		return antesDepoisPVT;
	}
	
	void setPontuacao(bool value)
	{
		pontuacao = value;
	}

	bool getPontuacao()
	{
		return pontuacao;
	}
	
	void ignite()
	{
		ignited = true;
	}
	
	bool wasIgnited()
	{
		return ignited;
	}
	
	void setAutoColor_antes ( string value )
	{
        autoColor_antes = value;
	}

	string getAutoColor_antes ()
	{
		return autoColor_antes;
	}

	void setAutoColor_depois ( string value )
	{
        autoColor_depois = value;
	}

	string getAutoColor_depois ()
	{
        return autoColor_depois;
	}

	void setAutoColor_cor ( string value )
	{
        autoColor_cor = value;
	}

	string getAutoColor_cor ()
	{
        return autoColor_cor;
	}

	void setEmoticons_antes ( string value )
	{
        emoticons_antes = value;
	}

	string getEmoticons_antes ()
	{
        return emoticons_antes;
	}

	void setEmoticons_depois ( string value )
	{
        emoticons_depois = value;
	}

	string getEmoticons_depois ()
	{
        return emoticons_depois;
	}

	void setEmoticons_bg ( string value )
	{
        emoticons_bg = value;
	}

	string getEmoticons_bg ()
	{
        return emoticons_bg;
	}

	void setEmoticons_corBoca ( string value )
	{
        emoticons_corBoca = value;
	}

	string getEmoticons_corBoca ()
	{
        return emoticons_corBoca;
	}

	void setEmoticons_corOlhos ( string value )
	{
        emoticons_corOlhos = value;
	}

	string getEmoticons_corOlhos ()
	{
		return emoticons_corOlhos;
	}

	void setEmoticons_olhos ( string value )
	{
        string teste = "";

        for ( int i = 0 ; i < (int)value.size() ; i++ )
        {
			if ( value.at(i) >= 'a' && value.at(i) <= 'z' )
			{
				teste += "[";
				teste += value.at(i);
				char maiuscula = value.at(i);
				maiuscula = (maiuscula - 'a') + 'A';
				teste += maiuscula;
				teste += "]";
			}
			else if ( value.at(i) >= 'A' && value.at(i) <= 'Z' )
			{
				teste += "[";
				teste += value.at(i);
				char minuscula = value.at(i);
				minuscula = (minuscula - 'A') + 'a';
				teste += minuscula;
				teste += "]";
			}
			else if  ( value.at(i) == '+' || value.at(i) == '(' || value.at(i) == '['
					|| value.at(i) == '|' || value.at(i) == ')' || value.at(i) == '?'
					|| value.at(i) == '{' || value.at(i) == '}' || value.at(i) == '$'
					|| value.at(i) == '^' || value.at(i) == '*' || value.at(i) == '.'
					|| value.at(i) == '\\')
			{
				teste += '\\';
				teste += value.at(i);
			}
			else if ( value.at(i) != ' ' )
			{
				teste += value.at(i);
			}
			else if ( value.at(i) == ' ' )
			{
				continue;
			}

			if ( i != (int)value.size() - 1)
			{
				teste += '|';
			}
		}

		emoticons_olhos = ((string)"(") + teste + ((string)")");
	}

	string getEmoticons_olhos ()
	{
		return emoticons_olhos;
	}

	void setEmoticons_olhosNeko ( string value )
	{
        string teste = "";

        for ( int i = 0 ; i < (int)value.size() ; i++ )
        {
			if ( value.at(i) >= 'a' && value.at(i) <= 'z' )
			{
				teste += "[";
				teste += value.at(i);
				char maiuscula = value.at(i);
				maiuscula = (maiuscula - 'a') + 'A';
				teste += maiuscula;
				teste += "]";
			}
			else if ( value.at(i) >= 'A' && value.at(i) <= 'Z' )
			{
				teste += "[";
				teste += value.at(i);
				char minuscula = value.at(i);
				minuscula = (minuscula - 'A') + 'a';
				teste += minuscula;
				teste += "]";
			}
			else if  ( value.at(i) == '+' || value.at(i) == '(' || value.at(i) == '['
					|| value.at(i) == '|' || value.at(i) == ')' || value.at(i) == '?'
					|| value.at(i) == '{' || value.at(i) == '}' || value.at(i) == '$'
					|| value.at(i) == '^' || value.at(i) == '*' || value.at(i) == '.'
					|| value.at(i) == '\\')
			{
				teste += '\\';
				teste += value.at(i);
			}
			else if ( value.at(i) != ' ' )
			{
				teste += value.at(i);
			}
			else if ( value.at(i) == ' ' )
			{
				continue;
			}

			if ( i != (int)value.size() - 1)
			{
				teste += '|';
			}
		}

		emoticons_olhosNeko = ((string)"(") + teste + ((string)")");
	}

	string getEmoticons_olhosNeko ()
	{
		return emoticons_olhosNeko;
	}

	void setEmoticons_bocas ( string value )
	{
        string teste = "";
        
        for ( int i = 0 ; i < (int)value.size() ; i++ )
        {
			if ( value.at(i) >= 'a' && value.at(i) <= 'z' )
			{
				teste += "[";
				teste += value.at(i);
				char maiuscula = value.at(i);
				maiuscula = (maiuscula - 'a') + 'A';
				teste += maiuscula;
				teste += "]+";
			}
			else if ( value.at(i) >= 'A' && value.at(i) <= 'Z' )
			{
				teste += "[";
				teste += value.at(i);
				char minuscula = value.at(i);
				minuscula = (minuscula - 'A') + 'a';
				teste += minuscula;
				teste += "]+";
			}
			else if  ( value.at(i) == '+' || value.at(i) == '(' || value.at(i) == '[' 
					|| value.at(i) == '|' || value.at(i) == ')' || value.at(i) == '?'
					|| value.at(i) == '{' || value.at(i) == '}' || value.at(i) == '$'
					|| value.at(i) == '^' || value.at(i) == '*' || value.at(i) == '.'
					|| value.at(i) == '\\' )
			{
				teste += '\\';
				teste += value.at(i);
				teste += "+";
			}
			else if ( value.at(i) != ' ' )
			{
				teste += value.at(i);
				teste += "+";
			}
			else if ( value.at(i) == ' ' )
			{
				continue;
			}
			
			if ( i != (int)value.size() - 1)
			{
				teste += '|';
			}
		}
		
		emoticons_bocas = "(" + teste + ")";
	}

	string getEmoticons_bocas ()
	{
		return emoticons_bocas;
	}
	
	void setNickCompletion_antes ( string value )
	{
        nickCompletion_antes = value;
	}

	string getNickCompletion_antes ()
	{
        return nickCompletion_antes;
	}

	void setNickCompletion_depois ( string value )
	{
        nickCompletion_depois = value;
	}

	string getNickCompletion_depois ()
	{
		return nickCompletion_depois;
	}
	
	void setPontuacao_simb ( string value )
	{
        	string teste = "";
		bool fecha = false;
		bool abre = false;
		bool traco = false;
        
        	for ( int i = 0 ; i < (int)value.size() ; i++ )
        	{
			if ( value.at(i) == ']' )
				fecha = true;
			else if ( value.at(i) == '[' )
				abre = true;
			else if ( value.at(i) == '-' )
				traco = true;
			else if ( value.at(i) == '\\' )
			{
				teste += '\\';
				teste += value.at(i);
			}
			else if ( value.at(i) == ' ' )
			{
				continue;
			}
			else if ( value.at(i) != ' ' )
			{
				teste += value.at(i);
			}
		}

		if ( abre )
			teste = "[" + teste;
		if ( fecha )
			teste = "]" + teste;
		if ( traco )
			teste = teste + "-";
		pontuacao_simb = "[" + teste + "]";
	}

	string getPontuacao_simb ()
	{
		return pontuacao_simb;
	}

	void processaString(vector<string> &vect);
	void coloreEmoticons(vector<string> &vect);
	void corrigeFrase(vector<string> &vect);
	void colorePontuacao(vector<string> &vect);
	void colorePontuacao(string &str);
	void loadDB ();
	
	void init_cfg (bool &erro, string &retorno, string init_str, char token);
};

londScript configs = londScript();

string c_color = "\003";
string c_bold = "\002";
string c_underline = "\037";
string c_plain = "\017";
string c_reverse = "\026";

map<string, string> *palavrasDB = NULL;


vector<string> split ( string str , char separator);
string unify ( vector<string> vect , char unifier);
string rev_str ( string s );
string intToStr ( int numero );
int strToInt ( string str );

vector<string> split ( string str , char separator )
{
	int i;
	string teste = string();
	vector<string> teste_vec;
	
	for ( i = 0 ; i < (int)str.size() ; i++ )
	{
		if ( str.at(i) != separator )
		{
			teste += str.at(i);
		}
		else
		{
			teste_vec.push_back(teste);
			teste = string();
		}
	}
	teste_vec.push_back(teste);
	return teste_vec;
}

string unify ( vector<string> vect , char unifier ) 
{
	string teste = string();
	
	teste += vect.at(0);
	
	for ( int i = 1 ; i < (int)vect.size() ; i++ )
	{
		teste += unifier + vect.at(i);
	}
	
	return teste;
}

string rev_str ( string s )
{
	if ( !s.empty() )
	{
		s = rev_str(s.substr(1)) + s.substr(0,1);
		return s;
	}
	
	return "";
}

string intToStr ( int numero )
{
	string final = "";
	char temp ;
	do
	{
		temp = (numero % 10) + '0';
		if ( temp < '0' || temp > '9' )
		{
			exit(-1);
		}
		numero = numero / 10;
		final += temp;
	} while ( numero );
	return rev_str(final);
}

int strToInt ( string str )
{
	int temp;
	sscanf(str.c_str(), "%d", &temp);
	return temp;
}

void londScript::processaString( vector<string> & vect )
{
	/* Usa o corretor */

	if ( getFraseCorretor() )
	{
		//corrigeFrase(vect);
	}
	
	/* Colore emoticons */
	if ( getEmoticons() )
	{
		coloreEmoticons(vect);
	}
	else if ( getPontuacao() )
	{
		colorePontuacao(vect);
	}
	
	/* Usa o corretor */

	if ( getFraseCorretor() )
	{
		corrigeFrase(vect);
	}
	
	/* Bota as cores na frase */
	
	/* Colore Google */
	
	/* Bota antes/depois */
	
	/* Faz strip se necessário */
}

void londScript::coloreEmoticons(vector <string> & vect )
{
	int x = vect.size();
	//string olhos("([oO]|[xX]|;)");
	//string olhosN("([oO]|[xX]|\\+)");
	//string bocas("(\\)+|[pP]+|[dD]+)");
	string narizes("([_]+|[-]+|[.]+)");
	string babinha("(~*)");
	string olhos = "";
	string bocas = "";
	string olhosNeko = "";
	olhos = getEmoticons_olhos();
	bocas = getEmoticons_bocas();
	olhosNeko = getEmoticons_olhosNeko();
	
	string s_carinhaDeitada("^" + olhos + bocas + babinha + "$");
	boost::regex carinhaDeitada(s_carinhaDeitada);
	
	string s_carinhaNariz("^" + olhosNeko + narizes + olhosNeko + babinha + "$");
	boost::regex carinhaNariz(s_carinhaNariz);

	string s_carinhaOlhos("^" + olhosNeko + "(\\1)" + babinha + "$");
	boost::regex carinhaOlhos(s_carinhaOlhos,boost::regex::perl|boost::regex::icase);
	
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what; 
	
	string emot;
	
	for ( int i = 0 ; i < x ; i++ )
	{
		/* vect.at(i) = getEmoticons_antes() + vect.at(i) + getEmoticons_depois(); */
		if ( boost::regex_match(vect.at(i), carinhaNariz) )
		{
			emot = "";
			regex_search(vect.at(i), what, carinhaNariz, flags);
			emot = c_color + getEmoticons_corOlhos();
			if ( getEmoticons_bg() != "" )
			{
				emot += "," + getEmoticons_bg();
			}
			emot += what[1];
			if ( what[2] != "" )
			{
				emot += c_color + getEmoticons_corBoca();
				if ( what[2].str().at(0) == '.' )
				{
					emot += ".";
				}
				else if ( what[2].str().at(0) == '-' )
				{
					emot += "-";
				}
				else
				{
					emot += what[2];
				}
			}
			emot += c_color + getEmoticons_corOlhos() + what[3];
			if ( what[4] != "" )
			{
				emot += c_color + "15,00" + what[4];
			}
			emot += c_plain;
			if ( getAutoColor() )
			{
				emot += c_color + getAutoColor_cor();
			}
			
			if ( emot == "" )
			{
				emot = "erro";
			}
			vect.at(i) = emot;
		}
		else if ( boost::regex_match(vect.at(i), carinhaOlhos) )
		{
			emot = "";
			regex_search(vect.at(i), what, carinhaOlhos, flags);
			emot = c_color + getEmoticons_corOlhos();
			if ( getEmoticons_bg() != "" )
			{
				emot += "," + getEmoticons_bg();
			}
			emot += what[1] + what[2];
			if ( what[3] != "" )
			{
				emot += c_color + "15,00" + what[3];
			}
			emot += c_plain;
			if ( getAutoColor() )
			{
				emot += c_color + getAutoColor_cor();
			}
			
			if ( emot == "" )
			{
				emot = "erro";
			}
			vect.at(i) = emot;
		}
		else if ( boost::regex_match(vect.at(i), carinhaDeitada) )
		{
			emot = "";
			regex_search(vect.at(i), what, carinhaDeitada, flags);
			
			emot = c_color + getEmoticons_corOlhos();
			if ( getEmoticons_bg() != "" )
			{
				emot += "," + getEmoticons_bg();
			}
			emot += what[1];
			
			emot += c_color + getEmoticons_corBoca() + what[2];
			if ( what[3] != "" )
			{
				emot += c_color + "15,00" + what[3];
			}
			
			emot = getEmoticons_antes() + emot + getEmoticons_depois() + c_plain;
			
			if ( getAutoColor() )
			{
				emot += c_color + getAutoColor_cor();
			}
			
			if ( emot == "" )
			{
				emot = "erro";
			}
			vect.at(i) = emot;
		}
		else if ( getPontuacao() ) {
			londScript::colorePontuacao(vect.at(i));
		}
	}
}

void londScript::colorePontuacao(string & str)
{
	//string listaPontuacao("[][+!?.\\/_@#$\"'{}():;<>,=%&-]");
	string listaPontuacao = getPontuacao_simb();

	string s_pontuacao("(" + listaPontuacao + "+)");
	boost::regex pontuacao(s_pontuacao);
	string s_format;
	if ( getAutoColor() )
	{
		s_format = c_color + "01,00$&" + c_plain + c_color + getAutoColor_cor();
	}
	else
	{
		s_format = c_color + "01,00$&" + c_plain;
	}
	
	/*int x = str.size();
	
	for ( int i = 0 ; i < x ; i++ )
	{*/
	string temp = str;
	if ( str == "" )
		return;
	temp = boost::regex_replace ( temp , pontuacao, s_format, boost::match_default | boost::format_all);
	if ( temp == "" )
	{
		temp = "erro!";
	}

	str = temp;
	/*}*/
}

void londScript::colorePontuacao(vector<string> &vect)
{
	//string listaPontuacao("[][(){}!@#$%&*_+=\\|,.<>:;/?\"'-]");
	string listaPontuacao = getPontuacao_simb();

    string s_pontuacao("(" + listaPontuacao + "+)");
	boost::regex pontuacao(s_pontuacao);
	string s_format;
	if ( getAutoColor() )
	{
		s_format = c_color + "01,00$&" + c_plain + c_color + getAutoColor_cor();
	}
	else
	{
		s_format = c_color + "01,00$&" + c_plain;
	}

	int x = vect.size();

	for ( int i = 0 ; i < x ; i++ )
	{
		string temp = vect.at(i);
		if ( temp == "" )
			continue;

		temp = boost::regex_replace ( temp , pontuacao, s_format, boost::match_default | boost::format_all);
		if ( temp == "" )
		{
			temp = "erro!";
		}

		vect.at(i) = temp;
	}
}

void londScript::loadDB ()
{
	if ( palavrasDB )
	{
		palavrasDB->~map<string,string>();
	}

	palavrasDB = new map<string, string>();

	fstream filestr;

#ifdef _XCHAT_DLL_
	string path = (".xchat2/corretor.db");
	//xchat_commandf(ph, "ECHO %s", path.c_str());
	filestr.open(path.c_str(), fstream::in);
	if ( !filestr.is_open() )
	{
		xchat_command(ph, "ECHO Não foi possível abrir arquivo de correções. Você tem certeza de que um existe?");
		xchat_command(ph, "ECHO Lembre-se de colocar um arquivo chamado corretor.db no diretório das suas configurações pessoais do XChat");
		return;
	}
	//xchat_command(ph, "ECHO Beleza, carregando as correções...");
#endif

	string linha = string();

	string s_arquivo("((\\[.*)|([^=]*)=(.*))");
	boost::regex arquivo(s_arquivo);
	boost::match_flag_type flags = boost::match_default;
	boost::match_results<std::string::const_iterator> what; 

	while ( !filestr.eof() )
	{
		getline(filestr, linha);
		if ( linha == "" )
		{
			continue;
		}

		if ( boost::regex_match(linha, arquivo) )
		{
			string temp1, temp2;
			regex_search(linha, what, arquivo, flags);

			/* what[0] -> tudo
			 * what[1] -> linha
			 * what[2] -> comentário
			 * what[3] -> antes do igual (palavra errada)
			 * what[4] -> depois do igual (substituição)
			 */
			if ( what[3] != "" )
			{
				temp1 = what[3];
				temp2 = what[4];
				(*palavrasDB)[temp1] = temp2;
				//xchat_commandf(ph, "ECHO %s = %s", temp1.c_str(), temp2.c_str());
			}
		}
	}
}

void londScript::corrigeFrase (vector<string> &vect)
{
	int x = vect.size();
	string pontuacao;
	pontuacao = "?!.,@#$%&*(){}[]";
	for ( int i = 0 ; i < x ; i++ )
	{
		string temp = vect[i];
		string newstring = string();

		for ( unsigned int j = 0 ; j < temp.size(); j++ )
		{
			if ( pontuacao.find(temp[j]) == string::npos )
			{
				newstring += temp[j];
			}
		}
#ifdef _XCHAT_DLL_
		xchat_commandf(ph, "ECHO Stripped? %s",newstring.c_str());
#endif

		string correto = string();
		if ( (*palavrasDB).find(newstring) != palavrasDB->end() )
		{
			correto = (*palavrasDB).find(newstring)->second;
		}

		if ( correto != "" )
		{
			if ( temp.find(newstring) != string::npos )
			{
				int size = newstring.size();
				int pos = temp.find(newstring);
				temp = temp.substr(0, pos) + correto + temp.substr(pos+size);
#ifdef _XCHAT_DLL_
		xchat_commandf(ph, "ECHO newtemp? %s",temp.c_str());
#endif
			}
		}
		vect[i] = temp;
	}
}

void londScript::init_cfg (bool &erro, string &retorno, string init_str, char token)
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
	vector<string> token_str;
	vector<string> opt;
	
	token_str = split(init_str, token);
	erro = false;
	
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
			retorno = "Erro! Formato incorreto em: \"" + token_str.at(i) + "\"";
			erro = true;
			return;
		}
		else if ( opt.size() > 1 )
		{
			string conc = unify(opt, ':');
			
			if ( option == "ACAts" )
			{
				setAutoColor_antes(conc);
			}
			else if ( option == "ACDep" )
			{
				setAutoColor_depois(conc);
			}
			else if ( option == "NCAts" )
			{
				setNickCompletion_antes(conc);
			}
			else if ( option == "NCDep" )
			{
				setNickCompletion_depois(conc);
			}
			else if ( option == "EmoAts" )
			{
				setEmoticons_antes(conc);
			}
			else if ( option == "EmoDps" )
			{
				setEmoticons_depois(conc);
			}
			else if ( option == "EmoOlhos" )
			{
				setEmoticons_olhos(conc);
			}
			else if ( option == "EmoOlhosNeko" )
			{
				setEmoticons_olhosNeko(conc);
			}
			else if ( option == "EmoBocas" )
			{
				setEmoticons_bocas(conc);
			}
			else if ( option == "PontSimb" )
			{
				setPontuacao_simb(conc);
			}
			else
			{
				retorno = "Erro! Formato incorreto em: \"" + token_str.at(i) + "\"";
				erro = true;
				return;
			}
		}
		else
		{
			if ( option == "AutoColor" )
			{
				setAutoColor(strToInt(opt.at(0)));
			}
			else if ( option == "NickCompletion" )
			{
				setNickCompletion(strToInt(opt.at(0)));
			}
			else if ( option == "Emoticons" )
			{
				setEmoticons(strToInt(opt.at(0)));
			}
			else if ( option == "GoogleColor" )
			{
				setGoogleColor(strToInt(opt.at(0)));
			}
			else if ( option == "Pontuacao" )
			{
				setPontuacao(strToInt(opt.at(0)));
			}
			else if ( option == "FraseCorretor" )
			{
				setFraseCorretor(strToInt(opt.at(0)));
			}
			else if ( option == "AntesDepoisPVT" )
			{
				setAntesDepoisPVT(strToInt(opt.at(0)));
			}
			else if ( option == "ACAts" )
			{
				setAutoColor_antes(opt.at(0));
			}
			else if ( option == "ACDep" )
			{
				setAutoColor_depois(opt.at(0));
			}
			else if ( option == "ACCor" )
			{
				setAutoColor_cor(opt.at(0));
			}
			else if ( option == "NCAts" )
			{
				setNickCompletion_antes(opt.at(0));
			}
			else if ( option == "NCDep" )
			{
				setNickCompletion_depois(opt.at(0));
			}
			else if ( option == "EmoAts" )
			{
				setEmoticons_antes(opt.at(0));
			}
			else if ( option == "EmoDep" )
			{
				setEmoticons_depois(opt.at(0));
			}
			else if ( option == "EmoBg" )
			{
				setEmoticons_bg(opt.at(0));
			}
			else if ( option == "EmoCOlhos" )
			{
				setEmoticons_corOlhos(opt.at(0));
			}
			else if ( option == "EmoCBoca" )
			{
				setEmoticons_corBoca(opt.at(0));
			}
			else if ( option == "EmoOlhos" )
			{
				setEmoticons_olhos(opt.at(0));
			}
			else if ( option == "EmoOlhosNeko" )
			{
				setEmoticons_olhosNeko(opt.at(0));
			}
			else if ( option == "EmoBocas" )
			{
				setEmoticons_bocas(opt.at(0));
			}
			else if ( option == "PontSimb" )
			{
				setPontuacao_simb(opt.at(0));
			}
			else
			{
				retorno = "Erro! Constante desconhecida: \"" + option + "\"";
				erro = true;
				return;
			}
		}
	}
	retorno = "Informações Armazenadas";
	if ( getFraseCorretor() )
		loadDB();
	ignite();
	erro = false;
	//xchat_commandf(ph, "ECHO %s", retorno.c_str());

	//return XCHAT_EAT_ALL;
}
