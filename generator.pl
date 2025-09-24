#!/usr/bin/perl

# Map Generator Script
#
# USAGE:
#   perl generator.pl <width> <height> <density>
#
# PARAMETERS:
#   width    - Integer: The width of the map (number of columns)
#   height   - Integer: The height of the map (number of rows)
#   density  - Integer: Controls obstacle density (0 = no obstacles, higher values = more obstacles)
#
# OUTPUT FORMAT:
#   - First line: "{height}.ox" (header indicating map dimensions)
#   - Following lines: map rows containing 'o' (obstacles), '.' (empty spaces) and 'x' (filled spaces)
#
# EXAMPLES:
#   # Generate a 10x5 map with low obstacle density
#   perl generator.pl 10 5 1
#
#   # Generate a 20x15 map with high obstacle density
#   perl generator.pl 20 15 8
#

use warnings;
use strict;

die "Usage: program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.OX\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "O";
		}
		else {
			print "X";
		}
	}
	print "\n";
}
