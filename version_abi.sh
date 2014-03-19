#!/bin/bash

# Copyright (C) 2014 Aurelien Vallee
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

if [ ! -f $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h ]; then
    echo "version.sh: error: $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h does not exist" 1>&2
    exit 1
fi

CURRENT=`egrep '^#define +CRASHBURN_VERSION_ABI_CURRENT +[0-9]+$' $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h`
REVISION=`egrep '^#define +CRASHBURN_VERSION_ABI_REVISION +[0-9]+$' $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h`
AGE=`egrep '^#define +CRASHBURN_VERSION_ABI_AGE +[0-9]+$' $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h`

if [ -z "$CURRENT" -o -z "$REVISION" -o -z "$AGE" ]; then
    echo "version.sh: error: could not extract version from $(dirname $0)/crashburn-lib/include/crashburn/crashburn.h" 1>&2
    exit 1
fi

CURRENT=`echo $CURRENT | awk '{ print $3 }'`
REVISION=`echo $REVISION | awk '{ print $3 }'`
AGE=`echo $AGE | awk '{ print $3 }'`

echo $CURRENT:$REVISION:$AGE | tr -d '\n'
