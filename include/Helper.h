#pragma once
#include <vector>

namespace Helper
{
	inline bool IsDigit(char c)
	{
		return (c>='0' and c<='9');
	}

	inline bool IsHex(char c)
	{
		return (IsDigit(c) or (c>='A' and c<='F'));
	}

	inline void LTrim(std::string& s, char delim=' ')
	{
		if(s.length()==0)
		{
			s = "";
			return;
		}
		unsigned begin=0;
		while(s[begin++]==delim);
		s = s.substr(begin-1, s.length());
	}
	
	inline void RTrim(std::string& s, char delim=' ')
	{
		if(s.length()==0)
		{
			s="";
			return;
		}
		unsigned end=s.length()-1;
		while(s[end--]==delim);
		s = s.substr(0, end+2);
	}

	inline std::vector<std::string> SplitIntoTwo(std::string s, char delim=' ')
	{
		// splits into two at the first occurence of the delimiter
		std::vector<std::string> splitted;
		unsigned occurence = 0;
		while(s[occurence++] != delim)
		{
			if(occurence >= s.length())
			{
				splitted.push_back(s);
				return splitted;
			}
		}
		// now occurence has the first occurence index of delim
		splitted.push_back(s.substr(0,occurence-1));// -1 because we dont need the delim in the string
		s = s.substr(occurence, s.length());
		LTrim(s);
		if(s.length()==0)
			return splitted;

		splitted.push_back(s);
		return splitted;
	}

	inline std::vector<std::string> Split(std::string s, char delim= ' ')
	{
		LTrim(s);
		RTrim(s);
		// splits into multiple strings
		std::vector<std::string> splitted;
		unsigned occurence = 0;
		unsigned length = s.length();
		while(occurence <= length)
		{
			if (s[occurence] == delim)
			{
				if(occurence>0)
					splitted.push_back(s.substr(0,occurence));
				else
					splitted.push_back(std::string(""));

				s = s.substr(++occurence,length);
				if(s.length() == 0)
				{
					s="";
					splitted.push_back(s);
					return splitted;
				}
				occurence = 0;
				length = s.length();
			}
			occurence +=1;
		}
		if (s.length() >0)
				splitted.push_back(s);
		return splitted;
	}

	inline void ToUpper(std::string& s)
	{
		for(unsigned i=0;i<s.length();i++)
			s[i] = (s[i] >= 'a' and s[i] <= 'z') ? 'A' + s[i] - 'a' : s[i];
	}
}
