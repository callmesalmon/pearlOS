#!/usr/bin/python3

# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.    

from sys import argv

colors = {
    "BLACK"        : "0",
    "BLUE"         : "1",
    "GREEN"        : "2",
    "CYAN"         : "3",
    "RED"          : "4",
    "PURPLE"       : "5",
    "BROWN"        : "6",
    "GRAY"         : "7",
    "DARK_GRAY"    : "8",
    "LIGHT_BLUE"   : "9",
    "LIGHT_GREEN"  : "a",
    "LIGHT_CYAN"   : "b",
    "LIGHT_RED"    : "c",
    "LIGHT_PURPLE" : "d",
    "YELLOW"       : "e",
    "WHITE"        : "f"
}

def generate():
    result = "#pragma once\n" + \
        "#define INCLUDED_COLOR\n"
    for color in colors:
        result += "#define " + color + " 0x" + colors[color] + "\n"
    for bgcolor in colors:
        for fgcolor in colors:
            if bgcolor != fgcolor:
                bgcode = colors[bgcolor]
                fgcode = colors[text_color]
                result += f"#define {fgcolor}_ON_{backround_color} 0x{bgcode}{fgcode}\n"
    return result

def fwrite(filename, data):
    with open(filename, "w") as f:
        return f.write(str(data))

if len(argv) > 1:
    fwrite(argv[1], generate())
