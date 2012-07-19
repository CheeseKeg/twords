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
 *  functions.cpp; important functions.
 *  github.com/cheesekeg/twords
 *
 */

#include "functions.hpp"

bool ischar(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'' || c == '-')
  {
    return true;
  }

  return false;
}

char tolower(char c)
{
  if (c >= 'A' && c <= 'Z')
  {
    c += 'a' - 'A';
  }

  return c;
}
