#!/bin/bash
#
# g++ build script
# github.com/cheesekeg/twords
#

cd bin/

function end {
    cd ..; exit $1
}

g++ -Wall -O -c ../src/*.cpp
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    end 1
else
    echo "Compilation successful."
fi

g++ ./*.o -o ./twords
if [ $? -ne 0 ]; then
    echo "Linking failed."
    end 2
else
    echo "Linking successful."
fi

end 0
