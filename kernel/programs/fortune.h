/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#pragma once

#include <io.h>
#include <magic.h>
#include <rand.h>
#include <drivers/display.h>

int ksh_fortune() {
    char *fortunes[] = {
        "Pohl's Law: Nothing is so good that somebody, somewhere, will not hate it.\n",

        "You either die a smart fella, or live long enough to become a fart smella\n",

        "Everyone asked you about your favorite dinosaur as a kid, now, nobody cares\n",

        "3rd Law of Comprinting:\n"
        "    Anything that can go wr\n"
        "fortune: Segmentation violation -- Core dumped\n",
        
        "Experience, n.:\n"
	    "    Something you don't get until just after you need it.\n"
		"        -- Olivier\n",

        "Famous quotations:\n\n"
        "    \" \"\n"
		"        -- Charlie Chaplin\n\n"
        "    \" \"\n"
	    "        -- Harpo Marx\n\n"
        "    \" \"\n"
	    "        -- Marcel Marceau\n",

        "Ginsberg's Theorem:\n"
        "   (1) You can't win.\n"
        "   (2) You can't break even.\n"
        "   (3) You can't even quit the game.\n\n"
        "Freeman's Commentary on Ginsberg's theorem:\n"
        "   Every major philosophy that attempts to make life seem\n"
        "   meaningful is based on the negation of one part of Ginsberg's\n"
        "   Theorem. To wit:\n\n"
        "   (1) Capitalism is based on the assumption that you can win.\n"
        "   (2) Socialism is based on the assumption that you can break even.\n"
        "   (3) Mysticism is based on the assumption that you can quit the game.\n"  
    };

    int fortune_len = len(fortunes);
    int rand_index = rand() % fortune_len;

    int i = 0;

    do {
        if (rand_index == i) {
            printk(fortunes[i]);
        }
    } while (++i <= fortune_len);

    return 0;
}