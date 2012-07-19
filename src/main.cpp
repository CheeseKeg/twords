/*
 *  This file is part of twords.
 *
 *  twords is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  twords is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with twords.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  --------------------------------------------------------------------
 *
 *  main.cpp; main function.
 *  github.com/cheesekeg/twords
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"

struct word
{
  unsigned int num;
  std::string w;
};

int main (int argc, char **argv)
{
  // Argument variables
  std::string input_file, output_file;
  unsigned int list_length;
  // IO pointers
  std::istream *input;
  std::ostream *output;
  // Word database
  std::vector<word> words;

  // Check number of arguments
  if (argc < 2 || argc > 4)
  {
    std::cout << "Usage: " << argv[0] << " input_file [list_length(10)] [output_file]" << std::endl;

    return 1;
  }
  // Get arguments / set defaults
  input_file = argv[1];
  if (argc >= 3) { list_length = atoi(argv[2]); } else { list_length = 10; }
  if (argc >= 4) { output_file = argv[3]; }

  // Establish input stream
  input = new std::ifstream(input_file.c_str());
  if (!input->good())
  {
    std::cout << "Error: Unable to read from " << input_file << std::endl;

    return 2;
  }

  // Establish output stream
  if (output_file.length() > 0)
  {
    output = new std::ofstream(output_file.c_str());

    if (!output->good())
    {
      std::cout << "Error: Unable to write to " << output_file << std::endl;

      return 2;
    }
  }
  else
  {
    output = &std::cout;
  }

  // Parse input and count words
  char c;
  std::string w;
  bool wrd = false;
  *input >> std::noskipws;
  while (*input >> c)
  {
    // Convert apostrophes / grave markers to apostrophe-quotes
    if (c == 226)
    {
      char d,e;
      *input >> d >> e;
      if (d == 128 && e == 153)
      {
	c = '\'';
      }
    }
    else if (c == '`')
    {
      c = '\'';
    }

    if (wrd)
    {
      if (ischar(c))
      {
	w += tolower(c);
      }
      else
      {
	wrd = false;

	bool wdone = false;
	for (unsigned int i = 0; i < words.size(); i++)
	{
	  if (w.compare(words[i].w) == 0)
	  {
	    wdone = true;
	    words[i].num++;
	    break;
	  }
	}

	if (!wdone)
	{
	  word tmp;
	  tmp.num = 1;
	  tmp.w = w;
	  words.push_back(tmp);
	}
      }
    }
    else
    {
      if (ischar(c))
      {
	wrd = true;

	w.clear();
	w += tolower(c);
      }
    }
  }

  // Extract top words
  for (unsigned int i = 0; i < list_length; i++)
  {
    unsigned int n;
    if (words.size() > 0)
    {
      n = 0;
      for (unsigned int j = 1; j < words.size(); j++)
      {
	if (words[j].num > words[n].num) n = j;
      }

      *output << words[n].w << " -> " << words[n].num << std::endl;
      words.erase(words.begin() + n);
    }
    else
    {
      break;
    }
  }

  return 0;
}
