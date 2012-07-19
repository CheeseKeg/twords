twords; "top words" - sort words by popularity
===================================
github.com/cheesekeg/twords

Purpose
-----------------------------------
Originally made to find the most common words used in very large texts such as the works of George R. R. Martin.

License
-----------------------------------
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Building with g++ on GNU/Linux
-----------------------------------
1. Clone the repository (run "git clone git://github.com/CheeseKeg/twords.git" without quotes)
2. If needed, grant execution permission to the build script (run "chmod +x build.sh" without quotes)
3. Execute the build script (run "./build.sh" without quotes)
4. The resulting "twords" binary should be located in the "bin/" directory; you can execute it by navigating to "bin/" and running "./twords" (without quotes)

Manual
-----------------------------------
```
NAME
       twords - sort words by popularity

SYNOPSIS
       twords INPUT [LENGTH(10)] [OUTPUT]

DESCRIPTION
       Parse and count words from the file INPUT, extract the LENGTH (extracts 10 by default) most popular words, and output them to the file OUTPUT (outputs to stdout by default).

   Exit status:
       0      if OK,

       1      if argument problems (e.g., invalid number of arguments),

       2      if I/O problems (e.g., unable to establish fstream(s)).

AUTHOR
       Written by Brandon T. DeRosier.

REPORTING BUGS
       Report twords bugs to cheesekeg@gmail.com

COPYRIGHT
       Copyright (C) 2012 Brandon T. DeRosier.  License GPLv3+:  GNU  GPL
       version 3 or later <http://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is
       NO WARRANTY, to the extent permitted by law.
```
