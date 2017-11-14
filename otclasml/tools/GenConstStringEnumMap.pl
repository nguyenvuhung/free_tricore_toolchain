#! /usr/bin/perl

use warnings;
use strict;

my $USAGE = <<EOF;
Usage:
	GenConstStringEnumMap namespace id path/to/header.hxx path/to/cxxfile.cxx path/to/header/from/includepaths (lc|id) [include_util_prefix] < ids.txt
EOF
;

my ($aNamespace, $aId, $aHeader, $aCxxFile, $aHeaderInclude, $aLc, $aInclude) = @ARGV;

die $USAGE unless (defined $aNamespace && defined $aId && defined $aHeader && defined $aCxxFile && defined $aHeaderInclude && defined $aLc);

$aInclude ||= "otclasml";

my $fnLc = sub {
	my ($a) = @_;
	return lc $a;
};
my $fnId = sub {
	my ($a) = @_;
	return $a;
};

my $aUId = uc $aId;
my $aLId = lc $aId;
my $aUcId = (substr $aUId, 0, 1).(substr $aLId, 1);
my $aUNamespace = uc $aNamespace;
my $aKeyFn = ($aLc eq 'lc') ? $fnLc : $fnId;

my %map = ( );


while (my $line = <STDIN>) {
	next if $line =~ /^\s*$/;
	next if $line =~ /^#/;
	my $str = undef;
	my $enum = undef;
	if ($line =~ m/^\s*([^\s]+)\s*$/) {
		$str = $1;
		$enum = $str;
		$enum =~ s/[^a-zA-Z0-9_]/_/g;
	} elsif ($line =~ m/^\s*([^\s]+)\s*([^\s]+)\s*$/) {
		$str = $1;
		$enum = $2;
	}
	$str = $aKeyFn->($str);
	my $cur = $map{$str};
	if ((defined $cur) && ($cur ne $enum)) {
		die "ERROR: Conflicting mappings for \"$str\": \"$cur\" and \"$enum\".";
	}
	$map{$str} = $enum;
}

# TODO care about the right locale...
my @keys = sort keys %map;
my $nkeys = @keys;
my $inttype;
if ($nkeys >= 0x10000) {
	$inttype = "uint32_t";
} elsif ($nkeys >= 0x100) {
	$inttype = "uint16_t";
} else {
	$inttype = "uint8_t";
}

# #### ####
# HEADER
# ### ####
my $fHeader;
open ($fHeader, '>', $aHeader) or die "Could not open \"$aHeader\" for writing: $!";
print $fHeader <<EOF;
/* \$Id\$
 * (L)
*/
#ifndef ${aUNamespace}_${aUId}_HXX
#define ${aUNamespace}_${aUId}_HXX 1

#include <$aInclude/StringView.hxx>
#include <$aInclude/inttypes.hxx>

namespace $aNamespace { namespace $aId {

// There are $nkeys entries.
enum ${aLId}s_e : $inttype {
EOF
;

for my $key (@keys) {
	my $val = $map{$key};
	print $fHeader "\t$val,\n";
}

print $fHeader <<EOF;
	NENTRIES
}; /* enum */

extern ${aLId}s_e to$aUcId(StringView s);
extern StringView ${aLId}ToString(uintn_t val);
inline StringView toString(${aLId}s_e val) { return ${aLId}ToString(($inttype) val); }

} } /* namespaces */
#endif /* _HXX */

EOF
;

close ($fHeader);
$fHeader = undef;
# #### ####
# END of HEADER
# ### ####


# #### ####
# CXX_FILE
# ### ####
my $fCxxFile;
open ($fCxxFile, '>', $aCxxFile) or die "Could not open \"$aCxxFile\" for writing: $!";
print $fCxxFile <<EOF;
/* \$Id\$
 * (L)
*/

#include <$aHeaderInclude>
#include <$aInclude/StringView.hxx>
#include <$aInclude/inttypes.hxx>
#include <$aInclude/ConstStringMap.hxx>

namespace $aNamespace { namespace $aId {

static ConstStringMap::String ${aLId}_strings[NENTRIES + 1] = {
EOF
;

my $i = 0;
for my $key (@keys) {
	my $len = length $key;
	my $val = $map{$key};
	print $fCxxFile "\t{ \"$key\", $len }, // $i: $val\n";
	++$i;
}

my $endString = "~[invalid~entry~$aId]~";
my $lenEnd = length $endString;
print $fCxxFile <<EOF;
	{ \"$endString\", $lenEnd }
}; /* strings */

${aLId}s_e to$aUcId(StringView s) {
	return (${aLId}s_e) ConstStringMap::fromString(s, ${aLId}_strings, (uintn_t) NENTRIES);
}
StringView ${aLId}ToString(uintn_t val) {
	return ConstStringMap::toString(val, ${aLId}_strings, (uintn_t) NENTRIES);
}

} } /* namespaces */

EOF
;

close ($fCxxFile);
$fCxxFile = undef;
# #### ####
# END of CXX_FILE
# ### ####

