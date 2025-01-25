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

if (@ARGV < 1) {
	print STDERR "usage: line file:address[,address] ...\n" .
		"\taddress is n or /regexp/[+-n]\n";
	exit 1;
}

sub num($) {
	my ($i) = @_;
	return substr($lines[$i], 0, 4);
}

sub line($$) {
	my ($p, $i) = @_;
	my $delta = 0;
	if($p =~ /^\d+$/) {
		return $p - 1;
	}
	if($p =~ /(.*?)([+-]\d+)$/) {
		$p = $1;
		$delta = $2;
	}
	if($p !~ /^\/(.*)\/$/) {
		print STDERR "invalid address: $p\n";
		exit 1;
	}
	$p = $1;
	for(; $i<@strip; $i++) {
		if($strip[$i] =~ $p) {
			return $i + $delta;
		}
	}
	print STDERR "no match for $p\n";
	exit 1;
}

sub find($) {
	my $arg = $_[0];
	$arg =~ s/!/\\/g;
	if($arg !~ /^(.*?):(.*)$/) {
		print STDERR "invaid file:address: ", $_[0];
		exit 1;
	}

	my ($file, $pattern) = ($1, $2);
	
	open(F, "../xv6/fmt/$file") || die "open ../xv6/fmt/$file: $!";
	@lines = <F>;
	close F;
	
	@strip = @lines;
	s/^[0-9]{4} // for @strip;

	if ($pattern =~ /(.*?),(.*)/) {
		($p1, $p2) = ($1, $2);
		my $i = line($p1, 0);
		my $j = line($p2, $i+1);
		return sprintf num($i) . "-" . num($j);
	} else {
		my $i = line($pattern, 0);
		return num($i);
	}
}

for($i=0; $i<@ARGV; $i++) {
	my $s = $ARGV[$i];
	if($s =~ /:/) {
		push @all, find($s);
	} else {
		push @all, $s;
	}
}

printf ".ds LINE \"%s\n", join(', ', @all);