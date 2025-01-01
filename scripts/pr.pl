#!/usr/bin/perl
# Copyright (c) 2006-2018 Frans Kaashoek, Robert Morris, Russ Cox,
#                         Massachusetts Institute of Technology
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

use POSIX qw(strftime);

if($ARGV[0] eq "-h"){
	shift @ARGV;
	$h = $ARGV[0];
	shift @ARGV;
}else{
	$h = $ARGV[0];
}

$page = 0;
$now = strftime "%b %e %H:%M %Y", localtime;

@lines = <>;
for($i=0; $i<@lines; $i+=50){
	print "\n\n";
	++$page;
	print "$now  $h  Page $page\n";
	print "\n\n";
	for($j=$i; $j<@lines && $j<$i +50; $j++){
		$lines[$j] =~ s!//DOC.*!!;
		print $lines[$j];
	}
	for(; $j<$i+50; $j++){
		print "\n";
	}
	$sheet = "";
	if($lines[$i] =~ /^([0-9][0-9])[0-9][0-9] /){
		$sheet = "Sheet $1";
	}
	print "\n\n";
	print "$sheet\n";
	print "\n\n";
}